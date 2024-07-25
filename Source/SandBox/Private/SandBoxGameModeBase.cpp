// Fill out your copyright notice in the Description page of Project Settings.


#include "SandBoxGameModeBase.h"
#include "SandBoxPawn.h"

ASandBoxGameModeBase::ASandBoxGameModeBase()
{
	DefaultPawnClass = ASandBoxPawn::StaticClass();
}
