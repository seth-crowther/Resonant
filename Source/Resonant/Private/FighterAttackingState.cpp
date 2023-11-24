// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterAttackingState.h"
#include "StateMachine.h"

void UFighterAttackingState::EnterState(AFighter* fighter)
{
	fighter->SetCanAttack(false);
}

void UFighterAttackingState::UpdateState(AFighter* fighter)
{
	// Nothing yet
}

void UFighterAttackingState::ExitState(AFighter* fighter)
{
	fighter->SetCanAttack(true);
}