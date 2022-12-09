#pragma once

#include "Runtime/Core/Public/UObject/NameTypes.h"

namespace BlackBoardKeys
{
    const TCHAR* TargetLocation = TEXT("TargetLocation");   // TCHAR* used instead of FName& is because VS shows errors using the latter.
}