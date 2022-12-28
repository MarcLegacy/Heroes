// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "BaseAI.h"

#include "Heroes/Other/Logger.h"

ABaseAI::ABaseAI()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseAI::MeleeAttack()
{
	if (Montage == nullptr)
	{
		FLogger::LogWarning("Montage == nullptr");
		return;
	}

	PlayAnimMontage(Montage);
}

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

