// Fill out your copyright notice in the Description page of Project Settings.


#include "GeometryHubActor.h"

DEFINE_LOG_CATEGORY_STATIC(GeometryHub, All, All);

// Sets default values
AGeometryHubActor::AGeometryHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGeometryHubActor::BeginPlay()
{
	Super::BeginPlay();
	
	//SpawnActor1();
	//SpawnActor2();
	SpawnActor3();

}

// Called every frame
void AGeometryHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGeometryHubActor::SpawnActor1()
{
	UWorld* World = GetWorld();
	if (World)
	{
		for (int32 i = 0; i < 10; i++)
		{
			const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, FVector(0.f, 300.f * i, 600.f));
			ABaseGeometryActor* Geometry = World->SpawnActorDeferred<ABaseGeometryActor>(GeometryClass, GeometryTransform);

			if (Geometry)
			{
				FGeometryData NewGeometryData;
				NewGeometryData.MoveType = FMath::RandBool() ? EMoveType::Static : EMoveType::Sin;
				NewGeometryData.Color = FLinearColor::MakeRandomColor();
				Geometry->SetGeometryData(NewGeometryData);
				Geometry->FinishSpawning(GeometryTransform);
			}
		}
	}
}

void AGeometryHubActor::SpawnActor2()
{
	UWorld* World = GetWorld();
	if (World)
	{
		for (int32 i = 0; i < 10; i++)
		{
			const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, FVector(0.f, 300.f * i, 300.f));
			ABaseGeometryActor* Geometry = World->SpawnActor<ABaseGeometryActor>(GeometryClass, GeometryTransform);

			if (Geometry)
			{
				FGeometryData NewGeometryData;
				NewGeometryData.MoveType = FMath::RandBool() ? EMoveType::Static : EMoveType::Sin;
				Geometry->SetGeometryData(NewGeometryData);
			}
		}
	}
}

void AGeometryHubActor::SpawnActor3()
{
	UWorld* World = GetWorld();
	if (World)
	{
		for (const FGeometryDataPayLoad& PayLoadTemp : PayLoads)
		{
			
			ABaseGeometryActor* Geometry = World->SpawnActorDeferred<ABaseGeometryActor>(PayLoadTemp.GeometryClass, PayLoadTemp.InitialTransform);
			if (Geometry)
			{
				Geometry->SetGeometryData(PayLoadTemp.Data);
				Geometry->OnColorChange.AddDynamic(this, &AGeometryHubActor::OnColorChange);
				Geometry->OnTimerFinished.AddUObject(this, &AGeometryHubActor::OnTimerFinished);
				Geometry->FinishSpawning(PayLoadTemp.InitialTransform);
			}
		}
	}
}

void AGeometryHubActor::OnColorChange(const FLinearColor Color, const FString Name)
{
	UE_LOG(GeometryHub, Warning, TEXT("Name - %s Color - %s"), *Name, *Color.ToString());
}

void AGeometryHubActor::OnTimerFinished(AActor* Actor)
{
	if (!Actor) return;
	UE_LOG(GeometryHub, Error, TEXT("TIMER FINISHED %s"), *Actor->GetName());


	ABaseGeometryActor* Geometry = Cast<ABaseGeometryActor>(Actor);
	if (Geometry)
	{
		UE_LOG(GeometryHub, Error, TEXT("CAST IS WORKINGGGGG %s"), *Geometry->GetName());
	}
}

