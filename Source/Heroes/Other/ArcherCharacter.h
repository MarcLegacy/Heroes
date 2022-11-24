// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "HeroesCharacter.h"
#include "ArcherCharacter.generated.h"

UCLASS()
class HEROES_API AArcherCharacter : public AHeroesCharacter
{
	GENERATED_BODY()

public:
	AArcherCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class AArrow> ArrowClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* AnimMontage;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> Crosshair;

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void FireArrow();

	FVector CrosshairWorldLocation;
	FVector ImpactPoint;
	FVector ArrowSpawnLocation;
	FRotator ArrowSpawnRotation;
};
