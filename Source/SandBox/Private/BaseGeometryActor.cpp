// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine\Engine.h"


DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometryActor, All, All);

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
	//PrintStringTypes();

	PrintType();
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGeometryActor::PrintType()
{


	UE_LOG(LogBaseGeometryActor, Warning, TEXT("%s"), *GetName());
	UE_LOG(LogBaseGeometryActor, Warning, TEXT("Kills Num - %i"), killsNum);
	UE_LOG(LogBaseGeometryActor, Warning, TEXT("Weapon Num - %i"), weaponNum);
	UE_LOG(LogBaseGeometryActor, Warning, TEXT("Heals Num - %f"), heals);
	UE_LOG(LogBaseGeometryActor, Warning, TEXT("Is Dead - %i"), static_cast<int>(isDead));
	UE_LOG(LogBaseGeometryActor, Warning, TEXT("Is LOX - %i"), isLox);

}

void ABaseGeometryActor::PrintStringTypes()
{
	FString name = "John Pubes";
	UE_LOG(LogBaseGeometryActor, Display, TEXT("name - %s"), *name);




	FString strWeaponNum = TEXT("WeaponNum = ") + FString::FromInt(weaponNum);
	FString strHeals = TEXT("Heals = ") + FString::SanitizeFloat(heals);
	FString strIsDead = TEXT("IsDEAD = ") + FString(isDead ? "True" : "False");

	FString stat = FString::Printf(TEXT("\nSTAT:\n %s \n %s \n %s \n"), *strWeaponNum, *strHeals, *strIsDead);

	UE_LOG(LogBaseGeometryActor, Warning, TEXT("%s"), *stat);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, name);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, stat, true, FVector2D(1.5f, 1.5f));
}

