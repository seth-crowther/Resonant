// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FighterBaseState.h"
#include "FighterDodgingState.generated.h"

/**
 * 
 */
UCLASS()
class RESONANT_API UFighterDodgingState : public UObject, public IFighterBaseState
{
	GENERATED_BODY()

public:
	void EnterState(AFighter* fighter);
	void UpdateState(AFighter* fighter);
	void ExitState(AFighter* fighter);
};
