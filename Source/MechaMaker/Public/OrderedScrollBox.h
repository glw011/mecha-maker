#pragma once

#include "CoreMinimal.h"
#include "Components/ScrollBox.h"
#include "OrderedScrollBox.generated.h"

UCLASS()
class MECHAMAKER_API UOrderedScrollBox : public UScrollBox{
  GENERATED_BODY()

  public:

    UFUNCTION(BlueprintCallable, meta=(DisplayName="Insert Child At", Keywords="Insert Child At"), Category = "Blocks")
    UPanelSlot* InsertChildAt(int32 Index, UWidget* Content){
      return UPanelWidget::InsertChildAt(Index, Content);
    }
};
