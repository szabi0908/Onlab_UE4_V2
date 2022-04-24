// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Bush.generated.h"

UCLASS(Blueprintable)
class ONLAB_UE4_V2_API ABush : public APawn
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<APawn> BushBerries;

	UPROPERTY(EditAnywhere)
		TSubclassOf<APawn> PlayerRecharge;

public:
	// Sets default values for this pawn's properties
	ABush();
	TArray<AActor*> Bushes;


	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void DestroyRandomBush();

	void SpawnPlayerRecharge();

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bush")
		class UStaticMeshComponent* BushMesh;


	UFUNCTION()
		void ChangeBushMesh();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bush")
		class UStaticMesh* Bush_Plain;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bush")
		class UStaticMesh* Bush_Berries;*/

};
