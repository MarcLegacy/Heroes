// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "FireArrow.h"

#include "Heroes/Other/Arrow.h"
#include "Heroes/Other/Logger.h"
#include "Kismet/KismetMathLibrary.h"

void UFireArrow::FireArrow(const FVector FromLocation, const FVector TargetLocation, const TSubclassOf<AArrow>& ArrowClass)
{
    if (ArrowClass.Get() == nullptr)
    {
        FLogger::LogWarning("ArrowClass not valid!");
        return;
    }

    const FRotator ArrowSpawnRotation = UKismetMathLibrary::MakeRotFromX(TargetLocation - FromLocation);

    FActorSpawnParameters ActorSpawnParameters;
    ActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
    //ActorSpawnParameters.Owner = this;
    //ActorSpawnParameters.Instigator = this;

    GEngine->GameViewport->GetWorld()->SpawnActor(ArrowClass.Get(), &FromLocation, &ArrowSpawnRotation, ActorSpawnParameters);
}
