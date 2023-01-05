// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseAI.generated.h"

class UBehaviorTree;
class APatrolPath;

UCLASS()
class HEROES_API ABaseAI : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseAI();

	APatrolPath* GetPatrolPath() const { return PatrolPath; }

	void MeleeAttack();

    UAnimMontage* GetMontage() const { return Montage; }

	UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; };

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		APatrolPath* PatrolPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UAnimMontage* Montage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UBehaviorTree* BehaviorTree;
};
