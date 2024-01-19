// Fill out your copyright notice in the Description page of Project Settings.

#include "FightCamera.h"
#define INTROTIME 3
#define PANSECONDS 1

// Sets default values
AFightCamera::AFightCamera()
{
 	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFightCamera::BeginPlay()
{
	Super::BeginPlay();
}

void AFightCamera::Initialize(AFighter* first, AFighter* second)
{
	actor1 = first;
	actor2 = second;

	currentState = LeftIntro;
	SetActorRotation(FQuat(FRotator(0, -30, 0)));
	actor1->PlayIntro();
	GetWorldTimerManager().SetTimer(changeStateDelayHandle, this, &AFightCamera::SwapToPanLR, INTROTIME, false);
}

// Called every frame
void AFightCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetNewLocation(currentState, DeltaTime));
}

FVector AFightCamera::GetCharMidpoint(AFighter* first, AFighter* second)
{
	FVector firstPos;
	FVector secondPos;

	if (IsValid(first) && IsValid(second)) // If both actors are valid (normal state)
	{
		firstPos = first->GetActorLocation();
		secondPos = second->GetActorLocation();
	}
	else if (IsValid(first) != IsValid(second)) // If one actor is not valid (e.g. killed)
	{
		firstPos = IsValid(first) ? first->GetActorLocation() : FVector(0, -(second->GetActorLocation().Y), second->GetActorLocation().Z);
		secondPos = IsValid(second) ? second->GetActorLocation() : FVector(0, -(first->GetActorLocation().Y), first->GetActorLocation().Z);
	}
	else // The off-chance that there are no actors, set a default position
	{
		firstPos = FVector(0, -200, 90);
		secondPos = FVector(0, 200, 90);
	}

	return ((firstPos + secondPos) / 2) + (FVector(0, 0, 1) * tweakCamHeight);
}

float AFightCamera::GetDistBack(AFighter* first, AFighter* second)
{
	float firstY;
	float secondY;
	
	if (IsValid(first) && IsValid(second)) // If both actors are valid (normal state)
	{
		firstY = first->GetActorLocation().Y;
		secondY = second->GetActorLocation().Y;
	}
	else if (IsValid(first) != IsValid(second)) // If one actor is not valid (e.g. killed)
	{
		firstY = IsValid(first) ? first->GetActorLocation().Y : -(second->GetActorLocation().Y);
		secondY = IsValid(second) ? second->GetActorLocation().Y : -(first->GetActorLocation().Y);
	}
	else // The off-chance that there are no actors, set a default position
	{
		firstY = 0;
		secondY = 0;
	}

	float charDistToMidpoint = (abs(firstY - secondY) / 2) + tweakCamDist;

	// Convert degrees to radians for tan function
	return (charDistToMidpoint / tan((fov / 2) * 3.14 / 180));
}

FVector AFightCamera::GetNewLocation(CameraState target, float DeltaTime)
{
	FVector destPos;
	FVector nextPos;
	FVector midpoint;
	float newX;
	float smoothedLerpAlpha;

	switch (target)
	{
		case LeftIntro:
			return actor1->GetActorLocation() + FVector(-180, 160, 30);

		case PanningLR:
			// Logic for interpolating to right fighter
			lerpAlpha += DeltaTime / PANSECONDS;
			smoothedLerpAlpha = FMath::SmoothStep((float)0, (float)1, lerpAlpha);

			// Interpolate position
			destPos = GetNewLocation(RightIntro, 0);
			nextPos = FMath::Lerp(originalPos, destPos, smoothedLerpAlpha);

			// Interpolate rotation
			SetActorRotation(FQuat(FMath::Lerp(FRotator(0, -30, 0), FRotator(0, 30, 0), smoothedLerpAlpha)));

			return nextPos;

		case RightIntro:
			SetActorRotation(FQuat(FRotator(0, 30, 0)));
			return actor2->GetActorLocation() + FVector(-180, -160, 30);

		case PanningRM:
			// Logic for interpolating to start of gameplay
			lerpAlpha += DeltaTime / PANSECONDS;
			smoothedLerpAlpha = FMath::SmoothStep((float)0, (float)1, lerpAlpha);

			// Interpolate position
			destPos = GetNewLocation(Gameplay, 0);
			nextPos = FMath::Lerp(originalPos, destPos, smoothedLerpAlpha);

			// Interpolate rotation
			SetActorRotation(FQuat(FMath::Lerp(FRotator(0, 30, 0), FRotator(0, 0, 0), smoothedLerpAlpha)));

			return nextPos;

		case Gameplay:
			midpoint = GetCharMidpoint(actor1, actor2);
			newX = GetDistBack(actor1, actor2) < minDistBack ? minDistBack : GetDistBack(actor1, actor2);
			SetActorRotation(FQuat(FRotator(0, 0, 0)));
			return FVector(-newX, midpoint.Y, midpoint.Z);
	}

	return FVector(0, 0, 0);
}

void AFightCamera::SwapToPanLR()
{
	GetWorldTimerManager().ClearTimer(changeStateDelayHandle);
	lerpAlpha = 0;
	originalPos = GetActorLocation();
	actor2->PlayIntro();
	currentState = PanningLR;
	GetWorldTimerManager().SetTimer(changeStateDelayHandle, this, &AFightCamera::SwapToRightIntro, PANSECONDS, false);
}

void AFightCamera::SwapToRightIntro()
{
	GetWorldTimerManager().ClearTimer(changeStateDelayHandle);
	actor1->horizontalMoveDir = 0;
	currentState = RightIntro;
	GetWorldTimerManager().SetTimer(changeStateDelayHandle, this, &AFightCamera::SwapToPanRM, INTROTIME, false);
}

void AFightCamera::SwapToPanRM()
{
	GetWorldTimerManager().ClearTimer(changeStateDelayHandle);
	lerpAlpha = 0;
	originalPos = GetActorLocation();
	currentState = PanningRM;
	GetWorldTimerManager().SetTimer(changeStateDelayHandle, this, &AFightCamera::SwapToGameplay, PANSECONDS, false);
}

void AFightCamera::SwapToGameplay()
{
	GetWorldTimerManager().ClearTimer(changeStateDelayHandle);
	actor2->horizontalMoveDir = 0;

	// Allows input to affect Fighters only after intro is complete
	actor1->AllowInput();
	actor2->AllowInput();

	currentState = Gameplay;
}
