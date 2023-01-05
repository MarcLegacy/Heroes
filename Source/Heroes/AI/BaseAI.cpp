// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "BaseAI.h"

#include "PatrolPath.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Heroes/Other/Logger.h"

ABaseAI::ABaseAI()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseAI::MeleeAttack()
{
	if (Montage == nullptr)
	{
		FLogger::LogNullptr(this->StaticClass()->GetName(), UAnimMontage::StaticClass()->GetName());
		return;
	}
	PlayAnimMontage(Montage);
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();

	if (Montage == nullptr)
	{
		FLogger::LogObjectNotSet(this->GetActorNameOrLabel(), UAnimMontage::StaticClass()->GetName());
	}

	if (BehaviorTree == nullptr)
	{
		FLogger::LogObjectNotSet(this->GetActorNameOrLabel(), UBehaviorTree::StaticClass()->GetName());
	}
}

void ABaseAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

