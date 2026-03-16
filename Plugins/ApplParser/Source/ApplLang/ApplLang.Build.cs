using UnrealBuildTool;
using System.IO;

public class ApplLang : ModuleRules{
  public ApplLang(ReadOnlyTargetRules Target) : base(Target){
    Type = ModuleType.CPlusPlus;

    PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

    // antlr needs dynamic cast
    bUseRTTI = true;
    // antlr needs exceptions
    bEnableExceptions = true;

    // project standard *(? need to confirm/set in MM build file) 
    CppStandard = CppStandardVersion.Cpp20;

    PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
    PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

    PublicDependencyModuleNames.AddRange(new string[]{"Core", "Antlr4Runtime"});
    //PrivateDependencyModuleNames.AddRange(new string[]{"Antlr4Runtime"});

    bWarningsAsErrors = false; // stop 'warnings = errors'
  }
}