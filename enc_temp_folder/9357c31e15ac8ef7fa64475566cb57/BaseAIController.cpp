// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "BaseAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Heroes/Other/HeroesCharacter.h"
#include "Heroes/Other/Logger.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ABaseAIController::ABaseAIController(const FObjectInitializer& ObjectInitializer)
{
    SetupPerceptionSystem();
}

void ABaseAIController::BeginPlay()
{
    Super::BeginPlay();

    if (FLogger::CheckAndLogIsValidPtr(BaseAIPawn->GetBehaviorTree(),  __FUNCTION__))
    {
        UseBlackboard(BaseAIPawn->GetBehaviorTree()->BlackboardAsset, BlackboardComponent);
    }
}

void ABaseAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    BaseAIPawn = GetPawn<ABaseAI>();

    if (FLogger::CheckAndLogIsValidPtr(BaseAIPawn, __FUNCTION__))
    {
        RunBehaviorTree(BaseAIPawn->GetBehaviorTree());
    }
}

void ABaseAIController::OnTargetDetected(AActor* Actor, FAIStimulus Stimulus)
{
    if (Cast<AHeroesCharacter>(Actor) != nullptr)
    {
        BlackboardComponent->SetValueAsBool(BlackBoardKeys::CanSeePlayer, Stimulus.WasSuccessfullySensed());    // TODO: find another way to retrieve the Blackboard key.
    }
}

void ABaseAIController::SetupPerceptionSystem()
{
    //TODO: Try to set the variable inside the blueprint.
    
    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
    SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
    SightConfig->SightRadius = 500.0f;
    SightConfig->LoseSightRadius = SightConfig->SightRadius + 25.0f;
    SightConfig->PeripheralVisionAngleDegrees = 90.0f;
    SightConfig->SetMaxAge(5.0f);
    SightConfig->AutoSuccessRangeFromLastSeenLocation = 520.0f;
    SightConfig->DetectionByAffiliation.bDetectEnemies = true;
    SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
    SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

    GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
    GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseAIController::OnTargetDetected);
    GetPerceptionComponent()->ConfigureSense(*SightConfig);

}


