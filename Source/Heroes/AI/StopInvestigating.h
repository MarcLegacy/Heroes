// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "StopInvestigating.generated.h"

/**
 * 
 */
UCLASS()
class HEROES_API UStopInvestigating : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UStopInvestigating(const FObjectInitializer& ObjectInitializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
