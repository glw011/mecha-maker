// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;

public class MechaMaker : ModuleRules{
	public MechaMaker(ReadOnlyTargetRules Target) : base(Target){
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		// CodeBlocks pure-C++ backend (compiled as part of this module)
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "CodeBlocks/Public"));
		PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "CodeBlocks/Private"));

		// Allow exceptions and RTTI needed by the CodeBlocks backend
		bEnableExceptions = true;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Slate", "SlateCore", "UMG"});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
