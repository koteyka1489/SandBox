// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Display, TEXT("HELLO PUBES"));
	UE_LOG(LogTemp, Warning, TEXT("HELLO PUBES"));
	UE_LOG(LogTemp, Error, TEXT("HELLO PUBES"));

	int killsNum = 4;
	int weaponNum = 5;
	float heals = 34.78956;
	bool isDead = false;
	bool isLox = true;

	UE_LOG(LogTemp, Display, TEXT("Kills Num - %i"), killsNum);
	UE_LOG(LogTemp, Display, TEXT("Weapon Num - %i"), weaponNum);
	UE_LOG(LogTemp, Display, TEXT("Heals Num - %f"), heals);
	UE_LOG(LogTemp, Display, TEXT("Heals Num - %.2f"), heals);
	UE_LOG(LogTemp, Display, TEXT("Is Dead - %i"), static_cast<int>(isDead));
	UE_LOG(LogTemp, Display, TEXT("Is LOX - %i"), isLox);

}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

