// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Resonant.generated.h"

UENUM(BlueprintType)
enum AttackHeight
{
	None,
	Low,
	High,
	Aerial
};

USTRUCT(BlueprintType)
struct FAttack
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* animation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName targetBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool immobilizeHorizontal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool immobilizeVertical;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<AttackHeight> height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInputAction* inputAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float beatsToStun;
};
