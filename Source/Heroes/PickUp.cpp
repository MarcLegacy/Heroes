// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#include "PickUp.h"

#include "Components/BoxComponent.h"

APickUp::APickUp()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(DefaultSceneRoot);

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(Mesh);
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &APickUp::OnComponentBeginOverlap);
}

void APickUp::BeginPlay()
{
	Super::BeginPlay();
}

void APickUp::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Destroy();
}


