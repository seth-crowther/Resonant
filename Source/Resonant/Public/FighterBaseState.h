// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fighter.h"
#include "UObject/Interface.h"
#include "FighterBaseState.generated.h"

/**
 * 
 */
UINTERFACE()
class UFighterBaseState : public UInterface
{
	GENERATED_BODY()
};

class RESONANT_API IFighterBaseState
{
	GENERATED_BODY()

public:
	virtual void EnterState(AFighter* fighter) = 0;
	virtual void UpdateState(AFighter* fighter) = 0;
	virtual void ExitState(AFighter* fighter) = 0;
};
