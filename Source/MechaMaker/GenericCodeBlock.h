#pragma once

#include "CoreMinimal.h"

//UCLASS(Blueprintable) <= Makes a class accessable within blueprints
/**
 * 
 */
class MECHAMAKER_API GenericCodeBlock{

public:
	// UFUNCTION(BlueprintCallable) <= Makes a function callable from blueprints
	GenericCodeBlock();
	void setOpenStr();
	~GenericCodeBlock();
};
