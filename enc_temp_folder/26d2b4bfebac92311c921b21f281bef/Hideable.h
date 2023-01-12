// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hideable.generated.h"

UCLASS()
class HEROES_API AHideable : public AActor
{
	GENERATED_BODY()
	
public:	
	AHideable();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
        UStaticMeshComponent* StaticMeshComponent;
};
