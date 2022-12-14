// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.
// File made with help from Youtube account "MrCxx", series "UE4 C++ AI Series": https://www.youtube.com/playlist?list=PLWUvrI0mg8VLrvq3n2iu45lhCo69uluDK

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPath.generated.h"

UCLASS()
class HEROES_API APatrolPath : public AActor
{
	GENERATED_BODY()
	
public:	
	APatrolPath();

	FVector GetPatrolPoint(const int Index) const;

	int Num() const { return PatrolPoints.Num(); }

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeEditWidget = "true", AllowPrivateAccess = "true"))
		TArray<FVector> PatrolPoints;
};
