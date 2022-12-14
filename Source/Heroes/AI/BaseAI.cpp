// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "BaseAI.h"

ABaseAI::ABaseAI()
{
	PrimaryActorTick.bCanEverTick = true;
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

