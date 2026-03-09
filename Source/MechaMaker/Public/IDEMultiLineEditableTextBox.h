// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/MultiLineEditableTextBox.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "IDEMultiLineEditableTextBox.generated.h"

/**
 * 
 */
UCLASS()
class MECHAMAKER_API UIDEMultiLineEditableTextBox : public UMultiLineEditableTextBox
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintPure, meta=(DisplayName="Get Caret Position", Keywords="Get Caret Position"), Category="IDE")
		bool getCursorPosition(int& linePos, int& charPos){
			auto slateWidget = StaticCastSharedRef<SMultiLineEditableTextBox>(TakeWidget());
			auto currPos = slateWidget->GetCursorLocation();
			linePos = currPos.GetLineIndex();
			charPos = currPos.GetOffset();
			return currPos.IsValid();
		}
		
		UFUNCTION(BlueprintCallable, meta=(DisplayName="Go To Position", Keywords="Go To Position"), Category="IDE")
		void goToPosition(int linePos, int charPos){
			auto slateWidget = StaticCastSharedRef<SMultiLineEditableTextBox>(TakeWidget());
			auto textPos = FTextLocation(linePos, charPos);
			slateWidget->GoTo(textPos);
		}
		
		
		UFUNCTION(BlueprintCallable, meta=(DisplayName="Insert Text", Keywords="Insert Text"), Category="IDE")
		void insertTextAtCurrPos(FText inTxt){
			auto slateWidget = StaticCastSharedRef<SMultiLineEditableTextBox>(TakeWidget());
			slateWidget->InsertTextAtCursor(inTxt);
		}

		UFUNCTION(BlueprintCallable, meta=(DisplayName="Insert String", Keywords="Insert String"), Category="IDE")
		void insertStrAtCurrPos(FString inString){
			auto slateWidget = StaticCastSharedRef<SMultiLineEditableTextBox>(TakeWidget());
			slateWidget->InsertTextAtCursor(inString);
		}

};
