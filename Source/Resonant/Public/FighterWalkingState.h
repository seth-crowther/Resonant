// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FighterBaseState.h"
#include "FighterWalkingState.generated.h"

/**
 * 
 */
UCLASS()
class RESONANT_API UFighterWalkingState : public UObject, public IFighterBaseState
{
	GENERATED_BODY()

public:
	void EnterState(AFighter* fighter);
	void UpdateState(AFighter* fighter);
	void ExitState(AFighter* fighter);
};
