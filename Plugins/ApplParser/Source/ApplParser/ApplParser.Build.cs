using UnrealBuildTool;
using System.IO;

public class ApplParser : ModuleRules{
	public ApplParser(ReadOnlyTargetRules Target) : base(Target){
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		// antlr needs exceptions and typically needs RTTI for dynamic cast
		bEnableExceptions = true;
		bUseRTTI = true;

		// fix unreal errors from undef'd ANTLR4_USE_THREAD_LOCAL_CACHE
    PublicDefinitions.Add("ANTLR4_USE_THREAD_LOCAL_CACHE=0");

    // fix unreal errors from undef'd TRACE_ATN_SIM
    PublicDefinitions.Add("TRACE_ATN_SIM=0");


		string ThirdPartyPath = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", "ThirdParty"));
		string AntlrPath = Path.Combine(ThirdPartyPath, "antlr4runtime");
		

		PublicIncludePaths.AddRange(
			new string[]{
				Path.Combine(ModuleDirectory, "Public"),
				Path.Combine(AntlrPath, "Include"),
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
		
		
	}
}
