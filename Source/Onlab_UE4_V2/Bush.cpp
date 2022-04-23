// Fill out your copyright notice in the Description page of Project Settings.


#include "Bush.h"

// Sets default values
ABush::ABush()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABush::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABush::DestroyRandomBush, FMath::RandRange(1, 2), true);

}

// Called every frame
void ABush::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABush::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ABush::DestroyRandomBush()
{

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABush::StaticClass(), Bushes);

	int32 NumberofBushes = Bushes.Num();
	int32 RandInt = FMath::RandRange(0, NumberofBushes - 1);
	if (Bushes.Num() != 0)
	{
		Bushes[RandInt]->Destroy();
	}
}

