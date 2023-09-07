// Fill out your copyright notice in the Description page of Project Settings.

#include "FighterWalkingState.h"
#include "StateMachine.h"

void UFighterWalkingState::EnterState(AFighter* fighter)
{
	fighter->SetZSpeed(0);
	// Set attack manager can attack again true
	FVector curr = fighter->GetActorLocation();
	fighter->SetActorLocation(FVector(0, curr.Y, 90));
}

void UFighterWalkingState::UpdateState(AFighter* fighter)
{
	// Nothing yet
}

void UFighterWalkingState::ExitState(AFighter* fighter)
{
	fighter->SetLastHorizontalDir();
}
