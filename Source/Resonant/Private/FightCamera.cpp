// Fill out your copyright notice in the Description page of Project Settings.


#include "FightCamera.h"

// Sets default values
AFightCamera::AFightCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

FVector AFightCamera::GetCharMidpoint()
{
	FVector leftPos = leftChar->GetActorLocation();
	FVector rightPos = rightChar->GetActorLocation();

	return ((leftPos + rightPos) / 2) + (FVector(0, 0, 1) * tweakCamHeight);
}

float AFightCamera::GetDistBack()
{
	float leftY = leftChar->GetActorLocation().Y;
	float rightY = rightChar->GetActorLocation().Y;

	float charDistToMidpoint = (abs(rightY - leftY) / 2) + tweakCamDist;

	// Convert degrees to radians for tan function
	return (charDistToMidpoint / tan((fov / 2) * 3.14159 / 180));
}

FVector AFightCamera::GetNewLocation()
{
	FVector midpoint = GetCharMidpoint();
	float newX = GetDistBack() < minDistBack ? minDistBack : GetDistBack();
	FVector newLocation = FVector(-newX, GetCharMidpoint().Y, GetCharMidpoint().Z);
	return newLocation;
}


