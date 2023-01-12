// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "ChasePlayer.h"

#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Heroes/Other/BlackBoardKeys.h"
#include "Heroes/Other/Logger.h"

UChasePlayer::UChasePlayer(const FObjectInitializer& ObjectInitializer)
{
    NodeName = TEXT("Chase Player");

    TargetLocationKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UChasePlayer, TargetLocationKey));
}

EBTNodeResult::Type UChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    ABaseAIController* Controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
    if (!FLogger::CheckAndLogIsValidPtr(Controller, __FUNCTION__)) return EBTNodeResult::Failed;

    const FVector PlayerLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(TargetLocationKey.SelectedKeyName);

    UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, PlayerLocation);

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}

void UChasePlayer::InitializeFromAsset(UBehaviorTree& Asset)
{
    Super::InitializeFromAsset(Asset);

    const UBlackboardData* BlackboardAsset = GetBlackboardAsset();
    TargetLocationKey.ResolveSelectedKey(*BlackboardAsset);
}
