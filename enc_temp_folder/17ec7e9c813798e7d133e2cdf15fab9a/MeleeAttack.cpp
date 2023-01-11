// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "MeleeAttack.h"

#include "BaseAI.h"
#include "BaseAIController.h"
#include "Heroes/Other/Logger.h"

UMeleeAttack::UMeleeAttack(const FObjectInitializer& ObjectInitializer)
{
    NodeName = TEXT("Melee Attack");
}

EBTNodeResult::Type UMeleeAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8*)
{
    if (ABaseAI* Agent = Cast<ABaseAI>(OwnerComp.GetAIOwner()->GetPawn()))
    {
        if (MontageHasFinished(Agent))  // Makes sure the montage is finished before playing again.
        {
            Agent->MeleeAttack();
        }
    }
    else
    {
        FLogger::LogWarning("Agent == nullptr");
    }

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}

bool UMeleeAttack::MontageHasFinished(const ABaseAI* Agent)
{
    return Agent->GetMesh()->GetAnimInstance()->Montage_GetIsStopped(Agent->GetMontage());
}
