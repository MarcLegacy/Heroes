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
	if (FLogger::CheckAndLogIsValidPtr(Montage, __FUNCTION__, GET_MEMBER_NAME_CHECKED(ABaseAI, Montage)))
	{
		PlayAnimMontage(Montage);
	}
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();

	FLogger::CheckAndLogIsPropertySet(this, Montage, GET_MEMBER_NAME_CHECKED(ABaseAI, Montage));
	FLogger::CheckAndLogIsPropertySet(this, BehaviorTree, GET_MEMBER_NAME_CHECKED(ABaseAI, BehaviorTree));
	FLogger::CheckAndLogIsPropertySet(this, PatrolPath, GET_MEMBER_NAME_CHECKED(ABaseAI, PatrolPath));
}

