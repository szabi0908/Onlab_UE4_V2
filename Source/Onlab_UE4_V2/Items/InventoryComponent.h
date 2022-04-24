// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONLAB_UE4_V2_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	virtual void BeginPlay() override;

	bool AddItem(class AItemActor* Item);
	bool RemoveItem(class AItemActor* Item);

	UPROPERTY(EditDefaultsOnly, Instanced)
		TArray<class AItemActor*> DefaultsItemActors;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
		int32 Capacity;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
		FOnInventoryUpdated OnInventoryUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
		TArray<class AItemActor*> Items;

		
};
