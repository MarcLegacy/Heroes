// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.
// File made with help from Youtube account "MrCxx", series "UE4 C++ AI Series": https://www.youtube.com/playlist?list=PLWUvrI0mg8VLrvq3n2iu45lhCo69uluDK

#pragma once

#include "CoreMinimal.h"
#include "AIModule/Classes/AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "BaseAIController.generated.h"

UCLASS()
class HEROES_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

public:
	ABaseAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintGetter)
		UBlackboardComponent* GetBlackboard() const { return BlackboardComponent; }

protected:
	void BeginPlay() override;
	void OnPossess(APawn* InPawn) override;

private:
	UFUNCTION()
	void OnTargetDetected(AActor* Actor, FAIStimulus Stimulus);

	void SetupPerceptionSystem();

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))//(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		class UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))//(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		UBehaviorTree* BehaviorTree;

    UBlackboardComponent* BlackboardComponent;
	class UAISenseConfig_Sight* SightConfig;
};
