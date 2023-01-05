// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "IncrementPathIndex.h"

#include "BaseAI.h"
#include "BaseAIController.h"
#include "PatrolPath.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/BlackBoardKeys.h"

UIncrementPathIndex::UIncrementPathIndex(const FObjectInitializer&)
{
    NodeName = TEXT("Increment Path Index");
}

EBTNodeResult::Type UIncrementPathIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    const ABaseAI* Agent = Controller->GetBaseAIPawn();

    int Index = OwnerComp.GetBlackboardComponent()->GetValueAsInt(BlackBoardKeys::PatrolPathIndex);

    if (BiDirectional)
    {
        if (Index >= Agent->GetPatrolPath()->Num() - 1 && Direction == EDirectionType::Forward)
        {
            Direction = EDirectionType::Reverse;
        }
        else if (Index == 0 && Direction == EDirectionType::Reverse)
        {
            Direction = EDirectionType::Forward;
        }
    }

    OwnerComp.GetBlackboardComponent()->SetValueAsInt(BlackBoardKeys::PatrolPathIndex, Direction == EDirectionType::Forward ? std::abs(++Index) : std::abs(--Index));

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}
