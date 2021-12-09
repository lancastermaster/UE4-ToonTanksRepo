// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksAIController.h"
#include "Kismet/GameplayStatics.h"

void AToonTanksAIController::BeginPlay()
{
    Super::BeginPlay();
    PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    SetFocus(PlayerPawn);
}

void AToonTanksAIController::Tick(float DeltaTime)
{
    MoveToActor(PlayerPawn, 200);
}