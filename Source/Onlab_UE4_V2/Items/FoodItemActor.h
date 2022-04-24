// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemActor.h"
#include "FoodItemActor.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ONLAB_UE4_V2_API AFoodItemActor : public AItemActor
{
	GENERATED_BODY()
	
protected:

	virtual void Use(class AMain_Character* Character) override;


};
