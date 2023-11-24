// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Metronome.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class RESONANT_API UMetronome : public UObject
{
	GENERATED_BODY()
	
public:
	UMetronome();

	UFUNCTION(BlueprintCallable)
		void Initialize(int numberOfBeats, int desiredBPM);

	UFUNCTION(BlueprintCallable)
		void Play();

private:
	int numBeats;
	int bpm;
	USoundWave* beatSound;
};
