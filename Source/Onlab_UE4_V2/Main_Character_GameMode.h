// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Bush.h"
#include "Onlab_UE4_V2/Items/FoodItemActor.h"
#include "Main_Character_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class ONLAB_UE4_V2_API AMain_Character_GameMode : public AGameMode
{
	GENERATED_BODY()
	
		AMain_Character_GameMode();


	

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AFoodItemActor> PlayerRecharge;

	float Spawn_Z = 200.0f;

	UPROPERTY(EditAnywhere)
		float Spawn_X_Min;

	UPROPERTY(EditAnywhere)
		float Spawn_X_Max;

	UPROPERTY(EditAnywhere)
		float Spawn_Y_Min;

	UPROPERTY(EditAnywhere)
		float Spawn_Y_Max;

	void SpawnPlayerRecharge();


};
