using UnrealBuildTool;
using System.IO;

public class Antlr4Runtime : ModuleRules{
  public Antlr4Runtime(ReadOnlyTargetRules Target) : base(Target){
    Type = ModuleType.CPlusPlus;

    PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

    // Antlr runtime needs these:
    bUseRTTI = true;
    bEnableExceptions = true;

    // Match your project standard (UE 5.7 uses C++20 in many configs)
    CppStandard = CppStandardVersion.Cpp20;

    // antlr runtime source don't include .h files not ordered correctly
    IWYUSupport = IWYUSupport.None;

    // just going in circles...
    bUseUnity = false;

		// fix unreal errors from undef'd ANTLR4_USE_THREAD_LOCAL_CACHE
    PublicDefinitions.Add("ANTLR4_USE_THREAD_LOCAL_CACHE=0");

    // fix unreal errors from undef'd TRACE_ATN_SIM
    PublicDefinitions.Add("TRACE_ATN_SIM=0");

    //bTreatAsEngineModule = false; // something to test
    bWarningsAsErrors = false; // stop 'warnings = errors'

    string publicPath = Path.Combine(ModuleDirectory, "Public");
    string privatePath = Path.Combine(ModuleDirectory, "Private");
    
    // add source files in public/private root to includes
    PublicIncludePaths.Add(publicPath);
    PrivateIncludePaths.Add(privatePath);

    PublicDependencyModuleNames.AddRange(new string[]{"Core"});

  }
}