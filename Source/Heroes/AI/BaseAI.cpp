// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "BaseAI.h"

#include "PatrolPath.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Heroes/Other/Logger.h"

ABaseAI::ABaseAI()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseAI::MeleeAttack()
{
	if (FLogger::CheckAndLogIsValidPtr<UAnimMontage>(Montage, __FUNCTION__))
	{
		PlayAnimMontage(Montage);
	}
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();

	FLogger::CheckAndLogIsObjectSet<UAnimMontage>(Montage, this);
	FLogger::CheckAndLogIsObjectSet<UBehaviorTree>(BehaviorTree,this);
}

