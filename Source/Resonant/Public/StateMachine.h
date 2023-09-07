// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "FighterBaseState.h"
#include "FighterWalkingState.h"
#include "FighterCrouchingState.h"
#include "FighterJumpingState.h"
#include "FighterParryingState.h"
#include "FighterDodgingState.h"
#include "FighterHitstunState.h"

#include "StateMachine.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum FighterStateName
{
	Walking,
	Crouching,
	Jumping,
	Parrying,
	Dodging,
	Hitstun
};

UCLASS(Blueprintable)
class RESONANT_API UStateMachine : public UObject
{
	GENERATED_BODY()
	
public: 
	UStateMachine();

	// Properties
	UPROPERTY()
		AFighter* owner;

	UPROPERTY(BlueprintReadOnly)
		TEnumAsByte<FighterStateName> currentStateName;


	// Important all states are UPROPERTY so they aren't garbage collected by UE
	UPROPERTY()
		TScriptInterface<IFighterBaseState> currentState;

	UPROPERTY()
		UFighterWalkingState* walkingState;

	UPROPERTY()
		UFighterCrouchingState* crouchingState;

	UPROPERTY()
		UFighterJumpingState* jumpingState;

	UPROPERTY()
		UFighterParryingState* parryingState;

	UPROPERTY()
		UFighterDodgingState* dodgingState;

	UPROPERTY()
		UFighterHitstunState* hitstunState;

	// Functions
	UFUNCTION(BlueprintCallable)
		void SwitchState(FighterStateName newStateName);

	UFUNCTION(BlueprintCallable)
		void Initialize(AFighter* fighter);

	TScriptInterface<IFighterBaseState> ParseStateName(FighterStateName stateName);
	FighterStateName GetStateName(TScriptInterface<IFighterBaseState> state);
};
