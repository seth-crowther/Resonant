// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterDodgingState.h"
#include "StateMachine.h"

void UFighterDodgingState::EnterState(AFighter* fighter)
{
	fighter->Dodge();
}

void UFighterDodgingState::UpdateState(AFighter* fighter)
{
	// Nothing yet
}

void UFighterDodgingState::ExitState(AFighter* fighter)
{
	// Nothing yet
}
