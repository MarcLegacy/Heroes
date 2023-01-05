// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "IsPlayerInMeleeRange.h"

#include "BaseAI.h"
#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Kismet/GameplayStatics.h"

UIsPlayerInMeleeRange::UIsPlayerInMeleeRange()
{
    bNotifyBecomeRelevant = true;
    NodeName = TEXT("Is Player In Melee Range");
}

void UIsPlayerInMeleeRange::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::OnBecomeRelevant(OwnerComp, NodeMemory);

    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    const ABaseAI* Agent = Cast<ABaseAI>(Controller->GetPawn());
    const ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

    OwnerComp.GetBlackboardComponent()->SetValueAsBool(BlackBoardKeys::IsPlayerInMeleeRange, Agent->GetDistanceTo(Player) <= MeleeRange);
}
