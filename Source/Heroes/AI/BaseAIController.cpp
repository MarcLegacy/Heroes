// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "BaseAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Heroes/Other/HeroesCharacter.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ABaseAIController::ABaseAIController(const FObjectInitializer& ObjectInitializer)
{
    static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("BehaviorTree'/Game/AI/BT_BaseAI.BT_BaseAI'"));

    if (BTObject.Succeeded())
    {
        BehaviorTree = BTObject.Object;
    }

    BehaviorTreeComponent = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("Behavior Tree Component"));
    BlackboardComponent = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackBoard Component"));

    SetupPerceptionSystem();
}

void ABaseAIController::BeginPlay()
{
    Super::BeginPlay();
    RunBehaviorTree(BehaviorTree);
    BehaviorTreeComponent->StartTree(*BehaviorTree);
}

void ABaseAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (BlackboardComponent)
    {
        BlackboardComponent->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
    }
}

void ABaseAIController::OnTargetDetected(AActor* Actor, FAIStimulus Stimulus)
{
    if (Cast<AHeroesCharacter>(Actor))
    {
        BlackboardComponent->SetValueAsBool(BlackBoardKeys::CanSeePlayer, Stimulus.WasSuccessfullySensed());
    }
}

void ABaseAIController::SetupPerceptionSystem()
{
    //TODO: Try to set the variable inside the blueprint.
    
    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
    SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
    SightConfig->SightRadius = 500.0f;
    SightConfig->LoseSightRadius = SightConfig->SightRadius + 50.0f;
    SightConfig->PeripheralVisionAngleDegrees = 90.0f;
    SightConfig->SetMaxAge(5.0f);
    SightConfig->AutoSuccessRangeFromLastSeenLocation = 900.0f;
    SightConfig->DetectionByAffiliation.bDetectEnemies = true;
    SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
    SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

    GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
    GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseAIController::OnTargetDetected);
    GetPerceptionComponent()->ConfigureSense(*SightConfig);

}


