// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "IncrementPathIndex.h"

#include "BaseAI.h"
#include "BaseAIController.h"
#include "PatrolPath.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Heroes/Other/Logger.h"

UIncrementPathIndex::UIncrementPathIndex(const FObjectInitializer&)
{
    NodeName = TEXT("Increment Path Index");

    PatrolPathIndexKey.AddIntFilter(this, GET_MEMBER_NAME_CHECKED(UIncrementPathIndex, PatrolPathIndexKey));
}

EBTNodeResult::Type UIncrementPathIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    if (!FLogger::CheckAndLogIsValidPtr(Controller, __FUNCTION__)) return EBTNodeResult::Failed;

    const APatrolPath* PatrolPath = Controller->GetBaseAIPawn()->GetPatrolPath();
    if (!FLogger::CheckAndLogIsValidPtr(PatrolPath, __FUNCTION__)) return EBTNodeResult::Failed;

    int Index = OwnerComp.GetBlackboardComponent()->GetValueAsInt(PatrolPathIndexKey.SelectedKeyName);

    if (BiDirectional)
    {
        if (Index >= PatrolPath->Num() - 1 && Direction == EDirectionType::Forward)
        {
            Direction = EDirectionType::Reverse;
        }
        else if (Index == 0 && Direction == EDirectionType::Reverse)
        {
            Direction = EDirectionType::Forward;
        }
    }

    OwnerComp.GetBlackboardComponent()->SetValueAsInt(PatrolPathIndexKey.SelectedKeyName, Direction == EDirectionType::Forward ? std::abs(++Index) : std::abs(--Index));

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}

void UIncrementPathIndex::InitializeFromAsset(UBehaviorTree& Asset)
{
    Super::InitializeFromAsset(Asset);

    const UBlackboardData* BlackboardAsset = GetBlackboardAsset();
    PatrolPathIndexKey.ResolveSelectedKey(*BlackboardAsset);
}
