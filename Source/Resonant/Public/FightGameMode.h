// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Fighter.h"
#include "FightGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RESONANT_API AFightGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		void EnforceFighterStartPos(AFighter* fighter);

	UPROPERTY(BlueprintReadWrite)
		bool hasGameplayStarted;

private:
	const float fighterStartY = 150;
};
