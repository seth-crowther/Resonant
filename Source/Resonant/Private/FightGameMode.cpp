// Fill out your copyright notice in the Description page of Project Settings.


#include "FightGameMode.h"

void AFightGameMode::EnforceFighterStartPos(AFighter* fighter)
{
	FVector fighterPos = fighter->GetActorLocation();
	if (!hasGameplayStarted && FMath::Abs(fighterPos.Y) < fighterStartY)
	{
		fighter->SetActorLocation(FVector(fighterPos.X, fighterStartY * -(fighter->side), fighterPos.Z));
		fighter->horizontalMoveDir = 0;
	}
}
