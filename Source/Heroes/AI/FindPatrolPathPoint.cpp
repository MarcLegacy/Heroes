// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "FindPatrolPathPoint.h"

#include "BaseAI.h"
#include "BaseAIController.h"
#include "PatrolPath.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/BlackBoardKeys.h"

UFindPatrolPathPoint::UFindPatrolPathPoint(const FObjectInitializer& ObjectInitializer)
{
    NodeName = TEXT("Find Path Path Point");
}

EBTNodeResult::Type UFindPatrolPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    const ABaseAI* Agent = Cast<ABaseAI>(Controller->GetPawn());
    const APatrolPath* PatrolPath = Agent->GetPatrolPath();
    const int Index = Controller->GetBlackboard()->GetValueAsInt(BlackBoardKeys::PatrolPathIndex);

    const FVector PatrolPoint = PatrolPath->GetPatrolPoint(Index);
    const FVector PointPosition = PatrolPath->GetActorTransform().TransformPosition(PatrolPoint);

    Controller->GetBlackboard()->SetValueAsVector(BlackBoardKeys::PatrolPathVector, PointPosition);

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}
