// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.
// File made with help from Youtube account "MrCxx", series "UE4 C++ AI Series": https://www.youtube.com/playlist?list=PLWUvrI0mg8VLrvq3n2iu45lhCo69uluDK

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "ChasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class HEROES_API UChasePlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UChasePlayer(const FObjectInitializer& ObjectInitializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	void InitializeFromAsset(UBehaviorTree& Asset) override;

	UPROPERTY(EditAnywhere, Category = Blackboard, meta = (AllowPrivateAccess = "true"))
		FBlackboardKeySelector TargetLocationKey;
};
