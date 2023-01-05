// Fill out your copyright notice in the Description page of Project Settings.


#include "Logger.h"


void FLogger::LogMessage(const FString& Message, const bool bToScreen, const float DisplayTime)
{
    if (bToScreen)
    {
        GEngine->AddOnScreenDebugMessage(DEFAULT_SLOT, DisplayTime, FColor::White, Message);
    }

    UE_LOG(LogTemp, Display, TEXT("%s"), *Message);
}

void FLogger::LogWarning(const FString& Message, const bool bToScreen, const float DisplayTime)
{
    if (bToScreen)
    {
        GEngine->AddOnScreenDebugMessage(DEFAULT_SLOT, DisplayTime, FColor::Yellow, Message);
    }

    UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
}

void FLogger::LogError(const FString& Message, const bool bToScreen, const float DisplayTime)
{
    if (bToScreen)
    {
        GEngine->AddOnScreenDebugMessage(DEFAULT_SLOT, DisplayTime, FColor::Red, Message);
    }

    UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
}

void FLogger::LogFatal(const FString& Message, const bool bToScreen, const float DisplayTime)
{
    if (bToScreen)
    {
        GEngine->AddOnScreenDebugMessage(DEFAULT_SLOT, DisplayTime, FColor::Red, Message);
    }

    UE_LOG(LogTemp, Fatal, TEXT("%s"), *Message);
}

void FLogger::LogObjectNotSet(const FString& OwnerName, const FString& ObjectName, const bool bToScreen, const float DisplayTime)
{
    LogWarning(OwnerName + ": " + ObjectName + " is not set!", bToScreen, DisplayTime);
}

void FLogger::LogObjectNotSet(const FString& ObjectName, const bool bToScreen, const float DisplayTime)
{
    LogWarning(ObjectName + " is not set!", bToScreen, DisplayTime);
}

void FLogger::LogNullptr(const FString& OwnerName, const FString& ObjectName, const bool bToScreen, const float DisplayTime)
{
    LogWarning(OwnerName + ": " + ObjectName + " == nullptr!", bToScreen, DisplayTime);
}

void FLogger::LogNullptr(const FString& ObjectName, const bool bToScreen, const float DisplayTime)
{
    LogWarning(ObjectName + " == nullptr!", bToScreen, DisplayTime);
}

void FLogger::LogFailedCast(const FString& OldObjectName, const FString& NewObjectName, const bool bToScreen,
    const float DisplayTime)
{
    LogWarning("Failed to cast " + OldObjectName + " to " + NewObjectName + "!", bToScreen, DisplayTime);
}

void FLogger::LogFailedCast(const FString& OwnerName, const FString& OldObjectName, const FString& NewObjectName,
    const bool bToScreen, const float DisplayTime)
{
    LogWarning(OwnerName + ": Failed to cast " + OldObjectName + " to " + NewObjectName + "!", bToScreen, DisplayTime);
}




