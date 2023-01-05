// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "FindPatrolPathPoint.h"

#include "BaseAI.h"
#include "BaseAIController.h"
#include "PatrolPath.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Heroes/Other/Logger.h"

UFindPatrolPathPoint::UFindPatrolPathPoint(const FObjectInitializer&)
{
    NodeName = TEXT("Find Path Path Point");
}

EBTNodeResult::Type UFindPatrolPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    if (Controller == nullptr)
    {
        FLogger::LogFailedCast(this->StaticClass()->GetName(), OwnerComp.GetAIOwner()->GetName(), ABaseAIController::StaticClass()->GetName());
        FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
        return EBTNodeResult::Succeeded;
    }

    const ABaseAI* Agent = Controller->GetBaseAIPawn();
    const APatrolPath* PatrolPath = Agent->GetPatrolPath();
    const int Index = OwnerComp.GetBlackboardComponent()->GetValueAsInt(GetSelectedBlackboardKey());

    const FVector PatrolPoint = PatrolPath->GetPatrolPoint(Index);
    const FVector PointPosition = PatrolPath->GetActorTransform().TransformPosition(PatrolPoint);

    OwnerComp.GetBlackboardComponent()->SetValueAsVector(PatrolPathVectorKey.SelectedKeyName, PointPosition);

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}

