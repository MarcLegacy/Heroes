// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#include "FindPlayerLocation.h"

#include "BaseAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Kismet/GameplayStatics.h"

UFindPlayerLocation::UFindPlayerLocation(FObjectInitializer const&)
{
    NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UFindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8*)
{
    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    const FVector PlayerLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();

    if (SearchRandom)
    {
        FNavLocation NavLocation;
        const UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());

        if (NavigationSystem->GetRandomPointInNavigableRadius(PlayerLocation, SearchRadius, NavLocation, nullptr))
        {
            Controller->GetBlackboard()->SetValueAsVector(BlackBoardKeys::TargetLocation, NavLocation.Location);
        }
    }
    else
    {
        Controller->GetBlackboard()->SetValueAsVector(BlackBoardKeys::TargetLocation, PlayerLocation);
    }

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}
