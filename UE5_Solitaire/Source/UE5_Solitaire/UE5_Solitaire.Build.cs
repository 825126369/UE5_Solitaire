// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class UE5_Solitaire : ModuleRules
{
	public UE5_Solitaire(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" });

        PrivateDependencyModuleNames.AddRange(new string[] {
            
        });

		PublicIncludePaths.AddRange(new string[] {
			"UE5_Solitaire/Public/GameLogic/",
            "UE5_Solitaire/Public/SimpleFramework/",
        });

		PrivateIncludePaths.AddRange(new string[] {
            "UE5_Solitaire/Private/GameLogic/",
            "UE5_Solitaire/Private/SimpleFramework/",
        });

		//InternalIncludePaths.AddRange(new string[] {
		//           "GameLogic",
		//      });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
