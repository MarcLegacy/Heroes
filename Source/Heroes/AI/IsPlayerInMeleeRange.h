// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.
// File made with help from Youtube account "MrCxx", series "UE4 C++ AI Series": https://www.youtube.com/playlist?list=PLWUvrI0mg8VLrvq3n2iu45lhCo69uluDK

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "IsPlayerInMeleeRange.generated.h"

/**
 * 
 */
UCLASS()
class HEROES_API UIsPlayerInMeleeRange : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UIsPlayerInMeleeRange();
	void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float MeleeRange = 25.0f;
	
};
