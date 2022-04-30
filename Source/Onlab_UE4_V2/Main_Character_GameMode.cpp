// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_Character_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"

AMain_Character_GameMode::AMain_Character_GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AMain_Character_GameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &AMain_Character_GameMode::SpawnPlayerRecharge, FMath::RandRange(1, 2), true);

	
}

void AMain_Character_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMain_Character_GameMode::SpawnPlayerRecharge()
{
	FVector Position;
	TArray<AActor*> Bushes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABush::StaticClass(), Bushes);

	int32 NumberofBushes = Bushes.Num();
	int32 RandInt = FMath::RandRange(0, NumberofBushes - 1);
	if (Bushes.Num() != 0)
	{
		Position = Bushes[RandInt]->GetActorLocation();
		Position.Z;
		Bushes[RandInt]->Destroy();
	}
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	GetWorld()->SpawnActor(PlayerRecharge, &Position, &SpawnRotation);
	GetWorld()->SpawnActor(Berry, &Position, &SpawnRotation);
}


