// Fill out your copyright notice in the Description page of Project Settings.


#include "FightCamera.h"

// Sets default values
AFightCamera::AFightCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFightCamera::Initialize(AActor* first, AActor* second)
{
	actor1 = first;
	actor2 = second;
}

// Called when the game starts or when spawned
void AFightCamera::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFightCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetNewLocation());
}

FVector AFightCamera::GetCharMidpoint(AActor* first, AActor* second)
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

float AFightCamera::GetDistBack(AActor* first, AActor* second)
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
	return (charDistToMidpoint / tan((fov / 2) * 3.14159 / 180));
}

FVector AFightCamera::GetNewLocation()
{
	FVector midpoint = GetCharMidpoint(actor1, actor2);
	float newX = GetDistBack(actor1, actor2) < minDistBack ? minDistBack : GetDistBack(actor1, actor2);
	FVector newLocation = FVector(-newX, midpoint.Y, midpoint.Z);
	return newLocation;
}


