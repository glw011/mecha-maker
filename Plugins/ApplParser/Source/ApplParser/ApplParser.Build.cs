// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ApplParser : ModuleRules{
	public ApplParser(ReadOnlyTargetRules Target) : base(Target){
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		// antlr needs exceptions and typically needs RTTI for dynamic cast
		bEnableExceptions = true;
		bUseRTTI = true;

		// project too small to be crazy strict about headers...
    bEnforceIWYU = false;
    IWYUSupport = IWYUSupport.None;


		string ThirdPartyPath = Path.Combine(ModuleDirectory, "..", "ThirdParty");
		string AntlrPath = Path.Combine(ThirdPartyPath, "antlr4runtime");
		

		PublicIncludePaths.AddRange(
			new string[]{
				Path.Combine(ModuleDirectory, "Public"),
				Path.Combine(AntlrPath, "Include", "antlr4-runtime"),
			}
		);
				
		
		PrivateIncludePaths.AddRange(
			new string[]{
				Path.Combine(ModuleDirectory, "Private"),
			}
		);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]{
				"Core", "CoreUObject", "Engine"							
			}
		);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]{
				"Slate",
				"SlateCore",
			}
		);


		// include static antlr4 lib according to platform
		if(Target.Platform == UnrealTargetPlatform.Win64){
			PublicAdditionalLibraries.Add(Path.Combine(AntlrPath, "Lib", "Windows", "antlr4-runtime-static.lib"));
		}
		else if(Target.Platform == UnrealTargetPlatform.Linux){
			PublicAdditionalLibraries.Add(Path.Combine(AntlrPath, "Lib", "Linux", "libantlr4-runtime.a"));
		}
		else if(Target.Platform == UnrealTargetPlatform.Mac){
			PublicAdditionalLibraries.Add(Path.Combine(AntlrPath, "Lib", "MacOS", "libantlr4-runtime.a"));
		}
		
		
		DynamicallyLoadedModuleNames.AddRange(new string[]{});
	}
}
