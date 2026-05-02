using UnrealBuildTool;
using System.IO;

public class ApplParser : ModuleRules{
	public ApplParser(ReadOnlyTargetRules Target) : base(Target){
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;


		//string ThirdPartyPath = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", "ThirdParty"));
		//string AntlrPath = Path.Combine(ThirdPartyPath, "antlr4runtime");

		PublicIncludePaths.AddRange(
			new string[]{
				Path.Combine(ModuleDirectory, "Public"),
				//Path.Combine(AntlrPath, "Include"),
				//Path.Combine(AntlrPath, "Include", "antlr4-runtime"),
			}
		);
				
		
		PrivateIncludePaths.AddRange(
			new string[]{
				Path.Combine(ModuleDirectory, "Private"),
			}
		);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]{
				"Core", "CoreUObject", "Engine", "Antlr4Runtime", "ApplLang", "Movement"
			}
		);

		/*
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
		*/
		
	}
}
