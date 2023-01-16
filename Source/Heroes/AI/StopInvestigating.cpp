// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "StopInvestigating.h"

#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Heroes/Other/Logger.h"

UStopInvestigating::UStopInvestigating(const FObjectInitializer& ObjectInitializer)
{
    NodeName = TEXT("Stop Investigating");
}

EBTNodeResult::Type UStopInvestigating::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    if (!FLogger::CheckAndLogIsValidPtr(Controller, __FUNCTION__)) return EBTNodeResult::Failed;

    OwnerComp.GetBlackboardComponent()->SetValueAsBool(BlackBoardKeys::IsInvestigating, false);

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}
