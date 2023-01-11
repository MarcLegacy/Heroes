// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#include "FindPlayerLocation.h"

#include "BaseAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Heroes/Other/Logger.h"
#include "Kismet/GameplayStatics.h"

UFindPlayerLocation::UFindPlayerLocation(FObjectInitializer const&)
{
    NodeName = TEXT("Find Player Location");

    TargetLocationKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UFindPlayerLocation, TargetLocationKey));
}

EBTNodeResult::Type UFindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    if (!FLogger::CheckAndLogIsValidPtr(Controller, __FUNCTION__)) return EBTNodeResult::Failed;

    const ACharacter* PlayerCharacter =  UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (!FLogger::CheckAndLogIsValidPtr(PlayerCharacter, __FUNCTION__)) return EBTNodeResult::Failed;

    const FVector PlayerLocation = PlayerCharacter->GetActorLocation();


    if (SearchRandom)
    {
        FNavLocation NavLocation;
        const UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
        if (!FLogger::CheckAndLogIsValidPtr(NavigationSystem, __FUNCTION__)) return EBTNodeResult::Failed;

        if (NavigationSystem->GetRandomPointInNavigableRadius(PlayerLocation, SearchRadius, NavLocation, nullptr))
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsVector(TargetLocationKey.SelectedKeyName, NavLocation.Location);
        }
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(TargetLocationKey.SelectedKeyName, PlayerLocation);
    }

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}

void UFindPlayerLocation::InitializeFromAsset(UBehaviorTree& Asset)
{
    Super::InitializeFromAsset(Asset);

    const UBlackboardData* BlackboardAsset = GetBlackboardAsset();
    TargetLocationKey.ResolveSelectedKey(*BlackboardAsset);
}
