// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MusicManager.generated.h"

UCLASS()
class RESONANT_API AMusicManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMusicManager();

	// Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float bpm;

	UPROPERTY(BlueprintReadWrite)
		float playbackTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float onBeatThreshold;

	UPROPERTY(BlueprintReadOnly)
		bool onBeat;

	// Functions
	UFUNCTION(BlueprintCallable)
		float GetNewPlayRate(UAnimMontage* attack);

	bool CheckBeat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
