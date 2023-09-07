// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterParryingState.h"
#include "StateMachine.h"

void UFighterParryingState::EnterState(AFighter* fighter)
{
	fighter->Parry();
}

void UFighterParryingState::UpdateState(AFighter* fighter)
{
	// Nothing yet
}

void UFighterParryingState::ExitState(AFighter* fighter)
{
	// Nothing yet
}
