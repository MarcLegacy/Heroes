#pragma once

#include "Runtime/Core/Public/UObject/NameTypes.h"

namespace BlackBoardKeys
{
    // TCHAR* used instead of FName& is because VS shows errors using the latter.
    // inline used to avoid having variables being defined by different classes.

    inline const TCHAR* TargetLocation = TEXT("TargetLocation");
    inline const TCHAR* CanSeePlayer = TEXT("CanSeePlayer");
    inline const TCHAR* PatrolPathVector = TEXT("PatrolPathVector");
    inline const TCHAR* PatrolPathIndex = TEXT("PatrolPathIndex");
    inline const TCHAR* IsPlayerInMeleeRange = TEXT("IsPlayerInMeleeRange");
}