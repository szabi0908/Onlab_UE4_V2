// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ONLAB_UE4_V2_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//virtual class UWorld* GetWorld() const { return World; };

	UPROPERTY(Transient)
		class UWorld* World;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ItemActor")
		FText UseActionText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ItemActor")
		class UStaticMesh* PickupMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ItemActor")
		class UTexture2D* Thumbnail;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ItemActor")
		FText ItemDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ItemActor", meta = (Multiline = true))
		FText ItemDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ItemActor", meta = (ClampMin = 0.0))
		float Weight;

	UPROPERTY()
		class UInventoryComponent* OwingInventory;

	virtual void Use(class AMain_Character* Character);

	UFUNCTION(BlueprintImplementableEvent)
		void OnUse(class AMain_Character* Character);

};
