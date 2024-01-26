// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "Fighter.h"
#include "FightCamera.generated.h"

UENUM()
enum CameraState {
	LeftIntro,
	PanningLR,
	RightIntro,
	PanningRM,
	Gameplay,
	PanningML,
	PanningMR
};

UCLASS()
class RESONANT_API AFightCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFightCamera();

	// Properties
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		AFighter* actor1;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		AFighter* actor2;

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
		float GetDistBack(AFighter* first, AFighter* second);

	UFUNCTION()
		FVector GetCharMidpoint(AFighter* first, AFighter* second);

	UFUNCTION()
		FVector GetNewLocation(CameraState target, float DeltaTime);

	UFUNCTION(BlueprintCallable)
		void Initialize(AFighter* left, AFighter* right);

	UFUNCTION(BlueprintCallable)
		void LeftPlayerWin();

	UFUNCTION(BlueprintCallable)
		void RightPlayerWin();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	CameraState currentState;

	FTimerHandle changeStateDelayHandle;

	FVector originalPos;

	float lerpAlpha;

	void SwapToPanLR();

	void SwapToRightIntro();

	void SwapToPanRM();

	void SwapToGameplay();
};
