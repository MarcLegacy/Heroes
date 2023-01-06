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

    /**
     * @brief 
     * @param CurrentActor: pass in 'this'.
     */
    template <typename T>
	static void LogObjectNotSet(const AActor* CurrentActor = nullptr, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);

	/**
	 * @brief
	 * @param FunctionName: Pass in '__FUNCTION__' to get the class and function.
	 */
	template <typename T>
	static void LogNullptr(const FString& FunctionName = "", const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);

    /**
     * @brief
     * @param CurrentActor: Pass in 'this'.
     */
    template <typename T>
	static bool CheckAndLogIsObjectSet(const T* ObjectToCheck, const AActor* CurrentActor = nullptr, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);

    /**
     * @brief 
     * @param FunctionName: Pass in '__FUNCTION__' to get the class and function.
     */
    template <typename T>
	static bool CheckAndLogIsValidPtr(const T* ObjectToCheck, const FString& FunctionName = "", const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);

private:
	// 'static' is needed because the variable is used in static functions.
	// 'constexpr' is added so that the variable is evaluated at compile-time.
	static constexpr uint64 DEFAULT_SLOT = -1;	
	static constexpr float STANDARD_DISPLAY_TIME = 5.0f;
};

template <typename T>
void FLogger::LogObjectNotSet(const AActor* CurrentActor, const bool bToScreen, const float DisplayTime)
{
	if (CurrentActor == nullptr)
	{
		LogWarning(T::StaticClass()->GetName() + " is not set!", bToScreen, DisplayTime);
	}
	else
	{
		LogWarning(CurrentActor->GetActorNameOrLabel() + ": " + T::StaticClass()->GetName() + " is not set!", bToScreen, DisplayTime);
	}
}

template <typename T>
void FLogger::LogNullptr(const FString& FunctionName, const bool bToScreen, const float DisplayTime)
{
	if (FunctionName == "")
	{
		LogError(T::StaticClass()->GetName() + " is a nullptr!", bToScreen, DisplayTime);
	}
	else
	{
		LogError(FunctionName + ": " + T::StaticClass()->GetName() + " is a nullptr!", bToScreen, DisplayTime);
	}
}

template <typename T>
bool FLogger::CheckAndLogIsObjectSet(const T* ObjectToCheck, const AActor* CurrentActor, const bool bToScreen,
    const float DisplayTime)
{
	if (ObjectToCheck == nullptr)
	{
		LogObjectNotSet<T>(CurrentActor, bToScreen, DisplayTime);
		return false;
	}

	return true;
}

template <typename T>
bool FLogger::CheckAndLogIsValidPtr(const T* ObjectToCheck, const FString& FunctionName, const bool bToScreen,
    const float DisplayTime)
{
	if (ObjectToCheck == nullptr)
	{
		LogNullptr<T>(FunctionName, bToScreen, DisplayTime);
		return false;
	}

	return true;
}





