// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "MeleeAttack.h"

#include "BaseAI.h"
#include "BaseAIController.h"
#include "Heroes/Other/Logger.h"

UMeleeAttack::UMeleeAttack(const FObjectInitializer& ObjectInitializer)
{
    NodeName = TEXT("Melee Attack");
}

EBTNodeResult::Type UMeleeAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    if (!FLogger::CheckAndLogIsValidPtr(Controller, __FUNCTION__)) return EBTNodeResult::Failed;

    ABaseAI* Agent = Controller->GetBaseAIPawn();
    if (Agent->GetMesh()->GetAnimInstance()->Montage_GetIsStopped(Agent->GetMontage()))  // Makes sure the montage is finished before playing again.
    {
        Agent->MeleeAttack();
    }

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}

