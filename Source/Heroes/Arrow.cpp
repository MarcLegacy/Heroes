// Fill out your copyright notice in the Description page of Project Settings.


#include "Arrow.h"

#include "Logger.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AArrow::AArrow()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(DefaultSceneRoot);
	Mesh->SetRelativeLocationAndRotation(FVector(100, 0, 0), FRotator(90, 0, 0));
	Mesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Ignore);

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(Mesh);
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AArrow::OnHit);
	BoxCollider->SetRelativeTransform(FTransform(FRotator(180, -90, 180), FVector(0, 0, -30), FVector(0.25, 0.25, 0.25)));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 6500.f;
	ProjectileMovement->MaxSpeed = 6500.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
}

void AArrow::BeginPlay()
{
	Super::BeginPlay();

	if (HitParticle == nullptr)
	{
		FLogger::LogWarning("HitParticle not set!");
	}
}

void AArrow::OnHit(UPrimitiveComponent*, AActor* OtherActor, UPrimitiveComponent*, int32, bool, const FHitResult&)
{
	if (OtherActor == this) return;

	ProjectileMovement->StopMovementImmediately();
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	AttachToActor(OtherActor, FAttachmentTransformRules::KeepWorldTransform);

	BoxCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	if (HitParticle != nullptr)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitParticle, BoxCollider->GetComponentLocation());
	}
	else
	{
		FLogger::LogWarning("HitParticle not set!");
	}

}


