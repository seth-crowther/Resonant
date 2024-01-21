// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Fighter.generated.h"

class UStateMachine;


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

	UPROPERTY(BlueprintReadWrite)
		UStateMachine* stateMachine;

	// Constants
	const float walkingSpeed = 100;
	const float gravity = -800;
	
	// Functions
	UFUNCTION(BlueprintCallable)
		void HandleGroundedMovement(float deltaTime);

	UFUNCTION(BlueprintCallable)
		void HandleAirborneMovement(float deltaTime);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void Dodge();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void Parry();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void Stun(float stunBeats);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void Die();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void SetCanAttack(bool value);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void PlayIntroAnimation();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void StartGameplay();

	void SetZSpeed(float value);
	void SetLastHorizontalDir();
	void PlayIntro();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
