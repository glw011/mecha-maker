
#include "ApplParser.h"
#include "Modules/ModuleManager.h"
#include "Logging/LogMacros.h"

// define log for parser plugin module
DEFINE_LOG_CATEGORY_STATIC(ApplParserLog, Log, All);

#define LOCTEXT_NAMESPACE "FApplParserModule"

void FApplParserModule::StartupModule(){
	UE_LOG(ApplParserLog, Log, TEXT("ApplParser Plugin Module Start..."));
}

void FApplParserModule::ShutdownModule(){
		UE_LOG(ApplParserLog, Log, TEXT("ApplParser Plugin Module Exit!"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FApplParserModule, ApplParser)