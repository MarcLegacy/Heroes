// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class HEROES_API FLogger
{
public:
	FLogger() = default;
	~FLogger() = default;

	static void LogMessage(const FString& Message, bool bToScreen = true, float DisplayTime = 1.f);
	static void LogWarning(const FString& Message, bool bToScreen = true, float DisplayTime = 1.f);
	static void LogError(const FString& Message, bool bToScreen = true, float DisplayTime = 1.f);
	static void LogFatal(const FString& Message, bool bToScreen = true, float DisplayTime = 1.f);

private:
	static constexpr uint64 DEFAULT_SLOT = -1;
};
