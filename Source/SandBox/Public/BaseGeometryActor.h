// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGeometryActor.generated.h"

UCLASS()
class SANDBOX_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Stat")
	int32 killsNum = 4;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	int32 weaponNum = 5;

	UPROPERTY(EditInstanceOnly, Category = "Stat")
	float heals = 34.78956;

	UPROPERTY(EditAnywhere, Category = "Stat")
	bool isDead = false;

	UPROPERTY(VisibleAnywhere, Category = "Stat")
	bool isLox = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	void PrintType();
	void PrintStringTypes();
};
