// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine\Engine.h"


DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometryActor, All, All);

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("Base Mesh");
	SetRootComponent(BaseMesh);
	
}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitLocation = GetActorLocation();

	SetColor(GeometryData.Color);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABaseGeometryActor::TimerOnFire, GeometryData.TimerRate, true);

	//PrintStringTypes();
	//PrintType();
	//PrintTransform();
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (GeometryData.MoveType)
	{
		case EMoveType::Sin:
		{
			SetZAmplitudeTransform();
			break;
		}
		case EMoveType::Static:
		{
			break;
		}
			
	}
		
	
	

	

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

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, name);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, stat, true, FVector2D(1.5f, 1.5f));
	}
	
}

void ABaseGeometryActor::PrintTransform()
{
	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotator = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();

	UE_LOG(LogBaseGeometryActor, Warning, TEXT("Actor NAme - %s"), *GetName());
	UE_LOG(LogBaseGeometryActor, Warning, TEXT("Transform - %s"), *Transform.ToString());
	UE_LOG(LogBaseGeometryActor, Warning, TEXT("Location - %s"), *Location.ToString());
	UE_LOG(LogBaseGeometryActor, Warning, TEXT("Rotator - %s"), *Rotator.ToString());
	UE_LOG(LogBaseGeometryActor, Warning, TEXT("Scale - %s"), *Scale.ToString());

	UE_LOG(LogBaseGeometryActor, Error, TEXT("Transform - %s"), *Transform.ToHumanReadableString());
}

void ABaseGeometryActor::SetZAmplitudeTransform()
{
	FVector CurentLocation = GetActorLocation();
	float Time = GetWorld()->GetTimeSeconds();
	CurentLocation.Z = InitLocation.Z + GeometryData.Amplitude * FMath::Sin(GeometryData.Frequency * Time);
	SetActorLocation(CurentLocation);
}

void ABaseGeometryActor::SetColor(FLinearColor color)
{
	if (!BaseMesh) return;
	UMaterialInstanceDynamic* DynMaterial = BaseMesh->CreateAndSetMaterialInstanceDynamic(0);
	if (DynMaterial)
	{
		DynMaterial->SetVectorParameterValue("Color", color);
	}
}

void ABaseGeometryActor::TimerOnFire()
{

	if (++TimerCount < MaxTimerCount)
	{
		FLinearColor NewColor = FLinearColor::MakeRandomColor();
		UE_LOG(LogBaseGeometryActor, Warning, TEXT("New Color - %s"), *NewColor.ToString());
		SetColor(NewColor);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(TimerHandle);
		UE_LOG(LogBaseGeometryActor, Error, TEXT("Timer Done - %s"), *GetName());
	}

}

