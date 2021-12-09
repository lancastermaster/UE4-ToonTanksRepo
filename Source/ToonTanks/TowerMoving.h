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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	void Rotate(FVector LookAtTarget);



private:
	void PursuePlayer(float Offset);

	float CalculateOffsets();

	float XOffset;
	float YawOffset;
};
