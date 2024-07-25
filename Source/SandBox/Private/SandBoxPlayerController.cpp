// Fill out your copyright notice in the Description page of Project Settings.


#include "SandBoxPlayerController.h"
#include "Components/InputComponent.h"
#include "Kismet\GameplayStatics.h"
#include "SandBoxPawn.h"

DEFINE_LOG_CATEGORY_STATIC(SandBoxPlayerControllerLog, All, All);

void ASandBoxPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("ChangePawn", IE_Pressed, this, &ASandBoxPlayerController::ChangePawn);

}

void ASandBoxPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASandBoxPawn::StaticClass(), Pawns);
}

void ASandBoxPlayerController::ChangePawn()
{
	if (Pawns.Num() <= 1) return;

	ASandBoxPawn* CurentPAwn = Cast<ASandBoxPawn>(Pawns[CurentPawnsIndex]);
	CurentPawnsIndex = (CurentPawnsIndex + 1) % Pawns.Num();

	if (!CurentPAwn) return;

	UE_LOG(SandBoxPlayerControllerLog, Warning, TEXT("change PAWN"));
	Possess(CurentPAwn);


}
