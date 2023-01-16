// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.
// File made with help from Youtube account "MrCxx", series "UE4 C++ AI Series": https://www.youtube.com/playlist?list=PLWUvrI0mg8VLrvq3n2iu45lhCo69uluDK

#pragma once

#include "CoreMinimal.h"
#include "BaseAI.h"
#include "AIModule/Classes/AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "BaseAIController.generated.h"

class UAISenseConfig_Sight;
class UAISenseConfig_Hearing;

UCLASS()
class HEROES_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

public:
	ABaseAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    ABaseAI* GetBaseAIPawn() const { return BaseAIPawn; }

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:
	UFUNCTION()
		void OnTargetDetected(AActor* Actor, FAIStimulus Stimulus);

	UFUNCTION()
		void OnUpdated(const TArray<AActor*>& UpdatedActors);

	void SetupPerceptionSystem();

	UPROPERTY()
    UBlackboardComponent* BlackboardComponent;
    UAISenseConfig_Sight* SightConfig;
	UAISenseConfig_Hearing* HearingConfig;
	ABaseAI* BaseAIPawn;
};
