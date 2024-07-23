// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnColorChange, const FLinearColor, Color, const FString, Name);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnTimerFinished, AActor*);

UENUM(BlueprintType)
enum class EMoveType : uint8
{
	Static UMETA(DisplayName = "Static"),
	Sin UMETA(DisplayName = "Sin")
};

USTRUCT(BlueprintType)
struct FGeometryData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Amplitude = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Frequency = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	EMoveType MoveType = EMoveType::Static;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Design")
	FLinearColor Color = FLinearColor::Black;

	UPROPERTY(EditAnywhere, Category = "Design")
	float TimerRate = 3.0f;
};


UCLASS()
class SANDBOX_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	void SetGeometryData(const FGeometryData& data) { GeometryData = data; }

	UFUNCTION(BlueprintCallable)
	FGeometryData GetGeometryData() const { return GeometryData; }

	UPROPERTY(BlueprintAssignable)
	FOnColorChange OnColorChange;

	FOnTimerFinished OnTimerFinished;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry Data")
	FGeometryData GeometryData;

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
	FVector InitLocation;
	FTimerHandle TimerHandle;

	const int32 MaxTimerCount = 10;
	int32 TimerCount = 0;


	void PrintType();
	void PrintStringTypes();
	void PrintTransform();
	void SetZAmplitudeTransform();
	void SetColor(FLinearColor color);
	void TimerOnFire();
};
