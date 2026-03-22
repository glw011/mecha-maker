
#pragma once

#include "Modules/ModuleManager.h"

class FAntlr4RuntimeModule : public IModuleInterface{
	public:
		virtual void StartupModule() override;
		virtual void ShutdownModule() override;
};
