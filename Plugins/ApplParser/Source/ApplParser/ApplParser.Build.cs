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

		string AntlrPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "antlr4runtime");
		string IncludePath = Path.Combine(AntlrPath, "Include");
		
		PublicIncludePaths.AddRange(
			new string[]{
				Path.Combine(ModuleDirectory, "Public"),
				// ... add public include paths required here ...
			}
		);
				
		
		PrivateIncludePaths.AddRange(
			new string[]{
				Path.Combine(ModuleDirectory, "Private")
				// ... add other private include paths required here ...
			}
		);
			
		
		PublicDependencyModuleNames.AddRange(new string[]{"Core"});
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
		);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]{
				// ... add any modules that your module loads dynamically here ...
			}
		);
	}
}
