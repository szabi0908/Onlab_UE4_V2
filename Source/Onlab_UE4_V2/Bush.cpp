// Fill out your copyright notice in the Description page of Project Settings.

#include "Bush.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Components/InputComponent.h"


// Sets default values
ABush::ABush()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	//BushMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUSH"));

	//BushMesh->SetupAttachment(GetRootComponent());

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> Bush(TEXT("'/Game/StarterContent/Props/SM_Bush'"));

	//if (Bush.Succeeded())
	//{
	//	
	//	BushMesh->SetStaticMesh(Bush.Object);
	//	
	//	BushMesh->SetRelativeLocation(FVector(70.f, 0.f, 0.f));
	//}

	//Bush_Plain = CreateDefaultSubobject<UStaticMesh>("Bush_Plain");
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> BushA(TEXT("'/Game/StarterContent/Props/SM_Bush'"));

	//
	//if (BushA.Succeeded())
	//{
	//	Bush_Plain = BushA.Object;
	//}

	//Bush_Berries = CreateDefaultSubobject<UStaticMesh>("Bush_Berries");
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> BushB(TEXT("'/Game/StarterContent/Props/SM_Chair'"));


	//if (BushB.Succeeded())
	//{
	//	Bush_Berries = BushB.Object;
	//}
}

// Called when the game starts or when spawned
void ABush::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	//GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABush::SpawnPlayerRecharge, FMath::RandRange(1, 2), true);

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

void ABush::SpawnPlayerRecharge()
{
	FVector Position;
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABush::StaticClass(), Bushes);

	int32 NumberofBushes = Bushes.Num();
	int32 RandInt = FMath::RandRange(0, NumberofBushes - 1);
	if (Bushes.Num() != 0)
	{
		//Position = Bushes[RandInt]->GetActorLocation();
		//Bushes[RandInt]->Destroy();
	}
	Position = FVector(80, -670, 300);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

	GetWorld()->SpawnActor(PlayerRecharge, &Position, &SpawnRotation);
}

//void ABush::ChangeBushMesh()
//{
//		BushMesh->SetStaticMesh(Bush_Berries);
//}

