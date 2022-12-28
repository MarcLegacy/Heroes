// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Heroes/Interfaces/CombatInterface.h"
#include "BaseAI.generated.h"

class APatrolPath;

UCLASS()
class HEROES_API ABaseAI : public ACharacter, public ICombatInterface
{
	GENERATED_BODY()

public:
	ABaseAI();

	APatrolPath* GetPatrolPath() const { return PatrolPath; }

	int MeleeAttack_Implementation() override;

    UAnimMontage* GetMontage() const { return Montage; }

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		APatrolPath* PatrolPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UAnimMontage* Montage;
};
