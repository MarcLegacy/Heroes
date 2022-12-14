// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "IncrementPathIndex.generated.h"

/**
 * 
 */
UCLASS()
class HEROES_API UIncrementPathIndex : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UIncrementPathIndex(const FObjectInitializer& ObjectInitializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	enum class EDirectionType
	{
	    Forward,
		Reverse,
	};

	EDirectionType Direction = EDirectionType::Forward;
};
