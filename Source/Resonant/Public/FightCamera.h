// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FightCamera.generated.h"

UCLASS()
class RESONANT_API AFightCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFightCamera();

	// Properties
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		APawn *leftChar;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		APawn *rightChar;

	UPROPERTY(EditAnywhere)
		float tweakCamDist;

	UPROPERTY(EditAnywhere)
		float tweakCamHeight;

	UPROPERTY(EditAnywhere)
		float minDistBack;

	UPROPERTY(BlueprintReadWrite)
		float fov;

	// Functions
	UFUNCTION()
		float GetDistBack();

	UFUNCTION()
		FVector GetCharMidpoint();

	UFUNCTION()
		FVector GetNewLocation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
