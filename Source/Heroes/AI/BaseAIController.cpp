// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "BaseAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/AITags.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Heroes/Other/HeroesCharacter.h"
#include "Heroes/Other/Logger.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Hearing.h"
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

void ABaseAIController::OnUpdated(const TArray<AActor*>& UpdatedActors)
{
    for (size_t i = 0; i < UpdatedActors.Num(); i++)
    {
        FActorPerceptionBlueprintInfo Info;
        GetPerceptionComponent()->GetActorsPerception(UpdatedActors[i], Info);

        for (size_t j = 0; j < Info.LastSensedStimuli.Num(); j++)
        {
            const FAIStimulus Stimulus = Info.LastSensedStimuli[j];
            if (Stimulus.Tag == AITags::NoiseTag)
            {
                BlackboardComponent->SetValueAsBool(BlackBoardKeys::IsInvestigating, Stimulus.WasSuccessfullySensed());
                BlackboardComponent->SetValueAsVector(BlackBoardKeys::TargetLocation, Stimulus.StimulusLocation);
            }
            else
            {
                //BlackboardComponent->SetValueAsBool(BlackBoardKeys::CanSeePlayer, Stimulus.WasSuccessfullySensed());
            }
        }
    }
}

void ABaseAIController::SetupPerceptionSystem()
{
    SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
    GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
    GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseAIController::OnTargetDetected);
    GetPerceptionComponent()->ConfigureSense(*SightConfig);

    HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing Config"));
    GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ABaseAIController::OnUpdated);
    GetPerceptionComponent()->ConfigureSense(*HearingConfig);
}


