// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "ChasePlayer.h"

#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Heroes/Other/BlackBoardKeys.h"

UChasePlayer::UChasePlayer(const FObjectInitializer& ObjectInitializer)
{
    NodeName = TEXT("Chase Player");
}

EBTNodeResult::Type UChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    //TODO: Change player location to either directly the player location or set the target to the target actor.

    ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    const FVector PlayerLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(GetSelectedBlackboardKey());

    UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, PlayerLocation);

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}
