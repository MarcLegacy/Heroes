// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "ChangeSpeed.h"

#include "AIController.h"
#include "BaseAI.h"
#include "GameFramework/CharacterMovementComponent.h"

UChangeSpeed::UChangeSpeed()
{
    NodeName = TEXT("Change Speed");
    bNotifyBecomeRelevant = true;   // Otherwise 'OnBecomeRelevant' isn't called.
}

void UChangeSpeed::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::OnBecomeRelevant(OwnerComp, NodeMemory);

    const AAIController* Controller = OwnerComp.GetAIOwner();
    const ABaseAI* Agent = Cast<ABaseAI>(Controller->GetPawn());
    Agent->GetCharacterMovement()->MaxWalkSpeed = Speed;

}

FString UChangeSpeed::GetStaticServiceDescription() const
{
    return FString("Change the Agent's speed");
}
