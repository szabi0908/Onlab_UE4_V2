// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItemActor.h"
#include "Onlab_UE4_V2/Main_Character.h"

void AFoodItemActor::Use(class AMain_Character* Character)
{
	if (Character)
	{
		Character->Hunger += 10;
	}
}
