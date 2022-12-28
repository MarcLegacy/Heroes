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
    const AAIController* Controller = OwnerComp.GetAIOwner();
    ABaseAI* Agent = Cast<ABaseAI>(Controller->GetPawn());
    const ICombatInterface* CombatInterface = Cast<ICombatInterface>(Agent);

    if (Agent == nullptr)
    {
        FLogger::LogWarning("Agent == nullptr");
    }

    if (CombatInterface == nullptr)
    {
        FLogger::LogWarning("CombatInterface == nullptr");
    }

    if (Agent != nullptr && CombatInterface != nullptr && MontageHasFinished(Agent))
    {
        CombatInterface->Execute_MeleeAttack(Agent);    // Execute is added to MeleeAttack since it comes from an interface.
    }

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}

bool UMeleeAttack::MontageHasFinished(const ABaseAI* Agent)
{
    return Agent->GetMesh()->GetAnimInstance()->Montage_GetIsStopped(Agent->GetMontage());
}
