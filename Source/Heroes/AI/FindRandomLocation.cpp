// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "FindRandomLocation.h"

#include "BaseAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/BlackBoardKeys.h"

UFindRandomLocation::UFindRandomLocation(FObjectInitializer const& ObjectInitializer)
{
    NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UFindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    const APawn* NPC = Controller->GetPawn();
    const FVector Origin = NPC->GetActorLocation();
    FNavLocation NavLocation;

    const UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
    if (NavigationSystem->GetRandomPointInNavigableRadius(Origin, SearchRadius, NavLocation, nullptr))
    {
        Controller->GetBlackboard()->SetValueAsVector(BlackBoardKeys::TargetLocation, NavLocation.Location);
    }

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}
