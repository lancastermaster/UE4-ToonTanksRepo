// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "TowerMoving.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATowerMoving : public ATower
{
	GENERATED_BODY()

public:

protected:

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed;
};
