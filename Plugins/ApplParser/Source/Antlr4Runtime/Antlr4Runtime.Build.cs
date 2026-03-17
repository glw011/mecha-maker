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

    // antlr runtime source don't order included .h files correctly so unreal whines
    IWYUSupport = IWYUSupport.None;

    // this did something but ive looked at so much UBT docs at this point I don't remember what
    bUseUnity = false;

		// fix unreal errors from undef'd ANTLR4_USE_THREAD_LOCAL_CACHE
    PublicDefinitions.Add("ANTLR4_USE_THREAD_LOCAL_CACHE=0");
    
    // fix unreal errors from undef'd TRACE_ATN_SIM
    PublicDefinitions.Add("TRACE_ATN_SIM=0");

    // fix unreal link errors on windows
    PrivateDefinitions.Add("ANTLR4CPP_BUILD");

    bWarningsAsErrors = false; // stop 'warnings = errors'

    string publicPath = Path.Combine(ModuleDirectory, "Public");
    string privatePath = Path.Combine(ModuleDirectory, "Private");
    
    // add source files in public/private root to includes
    PublicIncludePaths.Add(publicPath);
    PrivateIncludePaths.Add(privatePath);

    foreach(string SubDir in 
      System.IO.Directory.EnumerateDirectories(publicPath, "*", System.IO.SearchOption.AllDirectories)){
        PublicIncludePaths.Add(SubDir);
    }
    foreach(string SubDir in 
      System.IO.Directory.EnumerateDirectories(privatePath, "*", System.IO.SearchOption.AllDirectories)){
        PrivateIncludePaths.Add(SubDir);
    }

    if(Target.Platform == UnrealTargetPlatform.Linux){
      PublicRuntimeLibraryPaths.Add(Path.Combine(PluginDirectory, "Binaries", "Linux"));
    }

    PublicDependencyModuleNames.AddRange(new string[]{"Core"});

  }
}