// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicManager.h"

// Sets default values
AMusicManager::AMusicManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMusicManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMusicManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	onBeat = CheckBeat();
}

bool AMusicManager::CheckBeat()
{
	float period = 60 / bpm;
	float beat = fmod(playbackTime, period);
	return (beat < onBeatThreshold || beat > period - onBeatThreshold);
}

float AMusicManager::GetNewPlayRate(UAnimMontage  *attack)
{
	float period = 60 / bpm;
	float numPeriodsInAnimation = attack->CalculateSequenceLength() / period;
	return (attack->CalculateSequenceLength() / (round(numPeriodsInAnimation) * period));
}