// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_MusicManager.h"

// Sets default values
ABP_MusicManager::ABP_MusicManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABP_MusicManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_MusicManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	onBeat = CheckBeat();
}

bool ABP_MusicManager::CheckBeat()
{
	float period = 60 / bpm;
	float beat = fmod(playbackTime, period);
	return (beat < onBeatThreshold || beat > period - onBeatThreshold);
}

float ABP_MusicManager::GetNewPlayRate(UAnimMontage* attack)
{
	float period = 60 / bpm;
	float numPeriodsInAnimation = attack->CalculateSequenceLength() / period;
	return (attack->CalculateSequenceLength() / (round(numPeriodsInAnimation) * period));
}

