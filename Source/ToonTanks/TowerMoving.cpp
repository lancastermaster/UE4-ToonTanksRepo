// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerMoving.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

//subtract target location from current location
//turn resulting x and y values into floats
//addactorlocaloffset 

void ATowerMoving::Tick(float DeltaTime)
{
    if(Tank == nullptr)return;

    if(InFireRange())
    {
        Rotate(Tank->GetActorLocation());
        PursuePlayer(CalculateOffsets());
    }
}

void ATowerMoving::Rotate(FVector LookAtTarget)
{
    FVector ToTarget = LookAtTarget - GetActorLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);

    this->SetActorRotation(LookAtRotation);
}

float ATowerMoving::CalculateOffsets()
{
    //target - start location
    FVector EndLocation = Tank->GetActorLocation() - GetActorLocation();

    XOffset = FMath::Clamp(-EndLocation.X, -1.f, 1.f);
    return XOffset;
}

void ATowerMoving::PursuePlayer(float Offset)
{
    FVector DeltaLocation = FVector::ZeroVector;

    DeltaLocation.X = Offset * speed * UGameplayStatics::GetWorldDeltaSeconds(this);

    AddActorLocalOffset(DeltaLocation, true);
}