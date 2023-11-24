// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine.h"
#include "Fighter.h"

// Constructor
UStateMachine::UStateMachine()
{
	walkingState = CreateDefaultSubobject<UFighterWalkingState>(FName("WalkingState"));
	crouchingState = CreateDefaultSubobject<UFighterCrouchingState>(FName("CrouchingState"));
	jumpingState = CreateDefaultSubobject<UFighterJumpingState>(FName("JumpingState"));
	parryingState = CreateDefaultSubobject<UFighterParryingState>(FName("ParryingState"));
	dodgingState = CreateDefaultSubobject<UFighterDodgingState>(FName("DodgingState"));
	hitstunState = CreateDefaultSubobject<UFighterHitstunState>(FName("HitstunState"));
	attackingState = CreateDefaultSubobject<UFighterAttackingState>(FName("AttackingState"));

	currentState = walkingState;
	currentStateName = GetStateName(currentState);
}

FighterStateName UStateMachine::GetStateName(TScriptInterface<IFighterBaseState> state)
{
	if (state == crouchingState)
		return FighterStateName::Crouching;
	if (state == dodgingState)
		return FighterStateName::Dodging;
	if (state == hitstunState)
		return FighterStateName::Hitstun;
	if (state == jumpingState)
		return FighterStateName::Jumping;
	if (state == parryingState)
		return FighterStateName::Parrying;
	if (state == walkingState)
		return FighterStateName::Walking;
	if (state == attackingState)
		return FighterStateName::Attacking;
	return FighterStateName::Walking;
}

void UStateMachine::Initialize(AFighter* fighter)
{
	owner = fighter;
}

void UStateMachine::SwitchState(FighterStateName newStateName)
{
	TScriptInterface<IFighterBaseState> newState = ParseStateName(newStateName);

	currentState->ExitState(owner);
	currentState = newState;
	currentStateName = GetStateName(currentState);
	newState->EnterState(owner);
}

TScriptInterface<IFighterBaseState> UStateMachine::ParseStateName(FighterStateName stateName)
{
	switch (stateName)
	{
	case Walking:
		return walkingState;
	case Crouching:
		return crouchingState;
	case Jumping:
		return jumpingState;
	case Parrying:
		return parryingState;
	case Dodging:
		return dodgingState;
	case Attacking:
		return attackingState;
	default:
		return walkingState;
	}
}