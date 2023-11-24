// Fill out your copyright notice in the Description page of Project Settings.


#include "Metronome.h"

UMetronome::UMetronome()
{

}

void UMetronome::Initialize(int numberOfBeats, int desiredBPM)
{
	numBeats = numberOfBeats;
	bpm = desiredBPM;
	beatSound = LoadObject<USoundWave>(nullptr, TEXT("/Music/metronomeClick"));
}

void UMetronome::Play()
{
	for (int i = 0; i < numBeats; i++)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), beatSound, 1.0f, 1.0f, 0.0f);
	}
}