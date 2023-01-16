// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "Hideable.h"

AHideable::AHideable()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(GET_MEMBER_NAME_CHECKED(AHideable, DefaultSceneRoot));

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(GET_MEMBER_NAME_CHECKED(AHideable, StaticMeshComponent));
	StaticMeshComponent->SetupAttachment(DefaultSceneRoot);
    StaticMeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	StaticMeshComponent->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	StaticMeshComponent->SetHiddenInGame(true);
}

void AHideable::BeginPlay()
{
	Super::BeginPlay();
}


