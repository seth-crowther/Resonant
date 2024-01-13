// Fill out your copyright notice in the Description page of Project Settings.

#include "Fighter.h"
#include "StateMachine.h"

// Sets default values
AFighter::AFighter()
{
	PrimaryActorTick.bCanEverTick = true;
	immobilizeHorizontal = false;
	horizontalMoveDir = 0;

	lastHorizontalDir = 0;
	zSpeed = 0;
	side = 0;

	stateMachine = CreateDefaultSubobject<UStateMachine>(FName("fighterStateMachine"));
	stateMachine->Initialize(this);
}

void AFighter::SetZSpeed(float value)
{
	zSpeed = value;
}

void AFighter::SetLastHorizontalDir()
{
	lastHorizontalDir = horizontalMoveDir;
	horizontalMoveDir = 0;
}

// Called when the game starts or when spawned
void AFighter::BeginPlay()
{
	// This is a bit of a hack since a collider is the fighter's root component
	side = GetActorLocation().Y < 0 ? 1 : -1;
	Super::BeginPlay();
}

// Called every frame
void AFighter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFighter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AFighter::HandleGroundedMovement(float deltaTime)
{
	if (!immobilizeHorizontal)
	{
		FVector curr = GetActorLocation();
		float change = deltaTime * walkingSpeed * horizontalMoveDir;

		FVector newLocation = FVector(0, curr.Y + change, curr.Z);

		SetActorLocation(newLocation, true);
	}
}

void AFighter::HandleAirborneMovement(float deltaTime)
{
	zSpeed += gravity * deltaTime;
	FVector curr = GetActorLocation();
	float horizontalChange = deltaTime * walkingSpeed * lastHorizontalDir;

	FVector newLocation = FVector(0, curr.Y + horizontalChange, curr.Z + (deltaTime * zSpeed));
	SetActorLocation(newLocation, true);
}
