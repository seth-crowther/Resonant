// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Fighter.generated.h"

UCLASS()
class RESONANT_API AFighter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFighter();

	// Properties exposed to blueprints
	UPROPERTY(BlueprintReadWrite)
		int horizontalMoveDir;

	UPROPERTY(BlueprintReadWrite)
		bool immobilizeHorizontal;

	UPROPERTY(BlueprintReadWrite)
		int lastHorizontalDir;

	UPROPERTY(BlueprintReadOnly)
		int side;

	UPROPERTY(BlueprintReadWrite)
		float zSpeed;

	// Constants
	const float walkingSpeed = 100;
	const float gravity = -800;
	
	// Functions
	UFUNCTION(BlueprintCallable)
		void HandleGroundedMovement(float deltaTime);

	UFUNCTION(BlueprintCallable)
		void HandleAirborneMovement(float deltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
