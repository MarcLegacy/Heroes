// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "PatrolPath.h"

#include "Heroes/Other/Logger.h"

APatrolPath::APatrolPath()
{
	PrimaryActorTick.bCanEverTick = true;

}

FVector APatrolPath::GetPatrolPoint(const int Index) const
{
	if (Index >= PatrolPoints.Num())
	{
		FLogger::LogWarning("Patrol Points doesn't contain index: " + Index);
		return FVector(0, 0, 0);
	}

	return PatrolPoints[Index];
}


