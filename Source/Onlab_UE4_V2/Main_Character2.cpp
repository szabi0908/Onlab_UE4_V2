// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_Character2.h"

// Sets default values
AMain_Character2::AMain_Character2()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMain_Character2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMain_Character2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMain_Character2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

