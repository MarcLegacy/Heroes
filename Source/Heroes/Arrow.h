// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Arrow.generated.h"

class UProjectileMovementComponent;
class UBoxComponent;
UCLASS()
class HEROES_API AArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	AArrow();

	UPROPERTY(EditAnywhere)
		USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere)
	    UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxCollider;

	UPROPERTY(EditAnywhere)
		UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere)
		UParticleSystem* HitParticle;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
