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
	//float RandX = FMath::RandRange(Spawn_X_Min, Spawn_X_Max);
	//float Randy = FMath::RandRange(Spawn_Y_Min, Spawn_Y_Max);

	//FVector SpawnPosition = FVector(80, -670, 300);;
	//FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	//GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);

	FVector Position;
	TArray<AActor*> Bushes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABush::StaticClass(), Bushes);

	int32 NumberofBushes = Bushes.Num();
	int32 RandInt = FMath::RandRange(0, NumberofBushes - 1);
	if (Bushes.Num() != 0)
	{
		Position = Bushes[RandInt]->GetActorLocation();
		Position.Z += 21;
		Bushes[RandInt]->Destroy();
	}
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	/*Position = FVector(80, -670, 370);*/
	GetWorld()->SpawnActor(PlayerRecharge, &Position, &SpawnRotation);
}


