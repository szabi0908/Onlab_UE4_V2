// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Onlab_UE4_V2HUD.generated.h"

UCLASS()
class AOnlab_UE4_V2HUD : public AHUD
{
	GENERATED_BODY()

public:
	AOnlab_UE4_V2HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

