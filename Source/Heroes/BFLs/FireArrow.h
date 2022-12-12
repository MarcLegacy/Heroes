// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FireArrow.generated.h"

class AArrow;

UCLASS()
class HEROES_API UFireArrow : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /// <summary>
    /// Fires the ArrowClass from FromLocation towards TargetLocation.
    /// </summary>
    UFUNCTION(BlueprintCallable, Category = "Fire Arrow")
        static void FireArrow(const FVector FromLocation, const FVector TargetLocation, const TSubclassOf<AArrow>& ArrowClass);
};

