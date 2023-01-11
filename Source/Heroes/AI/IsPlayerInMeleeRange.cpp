// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "IsPlayerInMeleeRange.h"

#include "BaseAI.h"
#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Heroes/Other/Logger.h"
#include "Kismet/GameplayStatics.h"

UIsPlayerInMeleeRange::UIsPlayerInMeleeRange()
{
    bNotifyBecomeRelevant = true;
    NodeName = TEXT("Is Player In Melee Range");

    IsPlayerInMeleeRangeKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(UIsPlayerInMeleeRange, IsPlayerInMeleeRangeKey));
}

void UIsPlayerInMeleeRange::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::OnBecomeRelevant(OwnerComp, NodeMemory);

    const ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    if (!FLogger::CheckAndLogIsValidPtr(Controller, __FUNCTION__)) return;

    const ABaseAI* Agent = Controller->GetBaseAIPawn();
    const ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (!FLogger::CheckAndLogIsValidPtr(Player, __FUNCTION__)) return;

    OwnerComp.GetBlackboardComponent()->SetValueAsBool(IsPlayerInMeleeRangeKey.SelectedKeyName, Agent->GetDistanceTo(Player) <= MeleeRange);
}
