// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Onlab_UE4_V2 : ModuleRules
{
	public Onlab_UE4_V2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
