// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HeroesCharacter.h"
#include "ArcherCharacter.generated.h"

/**
 *
 */
UCLASS()
class HEROES_API AArcherCharacter : public AHeroesCharacter
{
	GENERATED_BODY()

public:
	AArcherCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UClass* ArrowClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* AnimMontage;

protected:
	void FireArrow();

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	FVector CrosshairWorldLocation;
	FVector ImpactPoint;
	FVector ArrowSpawnLocation;
	FRotator ArrowSpawnRotation;
};
