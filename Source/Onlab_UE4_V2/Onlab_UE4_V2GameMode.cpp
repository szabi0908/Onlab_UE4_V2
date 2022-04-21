// Copyright Epic Games, Inc. All Rights Reserved.

#include "Onlab_UE4_V2GameMode.h"
#include "Onlab_UE4_V2HUD.h"
#include "Onlab_UE4_V2Character.h"
#include "UObject/ConstructorHelpers.h"

AOnlab_UE4_V2GameMode::AOnlab_UE4_V2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AOnlab_UE4_V2HUD::StaticClass();
}
