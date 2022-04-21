// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter7777.h"

// Sets default values
AMyCharacter7777::AMyCharacter7777()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter7777::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter7777::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter7777::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

