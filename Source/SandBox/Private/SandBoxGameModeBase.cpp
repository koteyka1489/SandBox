// Fill out your copyright notice in the Description page of Project Settings.


#include "SandBoxGameModeBase.h"
#include "SandBoxPawn.h"
#include "SandBoxPlayerController.h"

ASandBoxGameModeBase::ASandBoxGameModeBase()
{
	DefaultPawnClass = ASandBoxPawn::StaticClass();
	PlayerControllerClass = ASandBoxPlayerController::StaticClass();
}
