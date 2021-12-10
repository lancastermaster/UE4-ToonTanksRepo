// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksAIController.h"
#include "Kismet/GameplayStatics.h"
#include "TowerMoving.h"

void AToonTanksAIController::BeginPlay()
{
    Super::BeginPlay();
    PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    EnemyTank = Cast<ATowerMoving>(GetPawn());

    SetFocus(PlayerPawn);
}

void AToonTanksAIController::Tick(float DeltaTime)
{
    if(PlayerPawn == nullptr)return;

    if(EnemyTank == nullptr)return;

    if(EnemyTank->InSightRange())
    {
        EnemyTank->RotateBase(PlayerPawn->GetActorLocation());
        MoveToActor(PlayerPawn, EnemyTank->AcceptanceRadius);
    }
}