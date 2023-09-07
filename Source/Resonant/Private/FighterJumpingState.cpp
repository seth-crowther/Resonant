// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterJumpingState.h"
#include "StateMachine.h"

void UFighterJumpingState::EnterState(AFighter* fighter)
{
	fighter->SetZSpeed(400);
}

void UFighterJumpingState::UpdateState(AFighter* fighter)
{
	// Nothing yet
}

void UFighterJumpingState::ExitState(AFighter* fighter)
{
	// Nothing yet
}
