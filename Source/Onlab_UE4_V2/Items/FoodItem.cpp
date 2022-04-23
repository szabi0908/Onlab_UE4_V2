// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "Onlab_UE4_V2/Main_Character.h"

void UFoodItem::Use(class AMain_Character* Character)
{
	if (Character)
	{
		Character->Hunger += 10;
	}
}

