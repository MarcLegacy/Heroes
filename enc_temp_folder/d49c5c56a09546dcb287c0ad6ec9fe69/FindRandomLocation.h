// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "AIModule/Classes/BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "FindRandomLocation.generated.h"

UCLASS(Blueprintable)
class HEROES_API UFindRandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UFindRandomLocation(FObjectInitializer const& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true")) // (EditAnywhere, Category = "Search", meta = (AllowPrivateAccess = "true"))
		float SearchRadius = 1500.0f;
};
