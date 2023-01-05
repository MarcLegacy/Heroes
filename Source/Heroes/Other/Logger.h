// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class HEROES_API FLogger
{
public:
	FLogger() = default;
	~FLogger() = default;

	static void LogMessage(const FString& Message, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);
	static void LogWarning(const FString& Message, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);
	static void LogError(const FString& Message, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);
	static void LogFatal(const FString& Message, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);

	static void LogObjectNotSet(const FString& OwnerName, const FString& ObjectName, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);
	static void LogObjectNotSet(const FString& ObjectName, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);
	static void LogNullptr(const FString& OwnerName, const FString& ObjectName, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);
	static void LogNullptr(const FString& ObjectName, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);
    static void LogFailedCast(const FString& OldObjectName, const FString& NewObjectName, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);
	static void LogFailedCast(const FString& OwnerName, const FString& OldObjectName, const FString& NewObjectName, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);

private:
	// 'static' is needed because the variable is used in static functions.
	// 'constexpr' is added so that the variable is evaluated at compile-time.
	static constexpr uint64 DEFAULT_SLOT = -1;	
	static constexpr float STANDARD_DISPLAY_TIME = 5.0f;
};
