// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "FindPatrolPathPoint.h"

#include "BaseAI.h"
#include "BaseAIController.h"
#include "PatrolPath.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Heroes/Other/Logger.h"

UFindPatrolPathPoint::UFindPatrolPathPoint(const FObjectInitializer& ObjectInitializer)
{
    NodeName = TEXT("Find Patrol Path Point");

    PatrolPathPointKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UFindPatrolPathPoint, PatrolPathPointKey));
    PatrolPathIndexKey.AddIntFilter(this, GET_MEMBER_NAME_CHECKED(UFindPatrolPathPoint, PatrolPathIndexKey));
}

EBTNodeResult::Type UFindPatrolPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    if (!FLogger::CheckAndLogIsValidPtr(Controller, __FUNCTION__))
    {
        return EBTNodeResult::Failed;
    }

    const APatrolPath* PatrolPath = Controller->GetBaseAIPawn()->GetPatrolPath();
    if (!FLogger::CheckAndLogIsValidPtr(PatrolPath, __FUNCTION__))
    {
        return EBTNodeResult::Failed;
    }

    UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
    const int Index = BlackboardComponent->GetValueAsInt(GetSelectedBlackboardKey());
    const FVector PatrolPoint = PatrolPath->GetPatrolPoint(Index);
    const FVector PointPosition = PatrolPath->GetActorTransform().TransformPosition(PatrolPoint);

    BlackboardComponent->SetValueAsVector(PatrolPathPointKey.SelectedKeyName, PointPosition);

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}

void UFindPatrolPathPoint::InitializeFromAsset(UBehaviorTree& Asset)
{
    Super::InitializeFromAsset(Asset);

    const UBlackboardData* BlackboardAsset = GetBlackboardAsset();
    PatrolPathPointKey.ResolveSelectedKey(*BlackboardAsset);   // Only this line is needed for added Blackboard Keys, it's purely for extra safety checks.
    PatrolPathIndexKey.ResolveSelectedKey(*BlackboardAsset);
}

