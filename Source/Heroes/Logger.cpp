// Fill out your copyright notice in the Description page of Project Settings.


#include "Logger.h"

void FLogger::LogMessage(const FString& Message, bool bToScreen, float DisplayTime)
{
    if (bToScreen)
    {
        GEngine->AddOnScreenDebugMessage(DEFAULT_SLOT, DisplayTime, FColor::White, Message);
    }

    UE_LOG(LogTemp, Display, TEXT("%s"), *Message);
}

void FLogger::LogWarning(const FString& Message, bool bToScreen, float DisplayTime)
{
    if (bToScreen)
    {
        GEngine->AddOnScreenDebugMessage(DEFAULT_SLOT, DisplayTime, FColor::Yellow, Message);
    }

    UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
}

void FLogger::LogError(const FString& Message, bool bToScreen, float DisplayTime)
{
    if (bToScreen)
    {
        GEngine->AddOnScreenDebugMessage(DEFAULT_SLOT, DisplayTime, FColor::Red, Message);
    }

    UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
}

void FLogger::LogFatal(const FString& Message, bool bToScreen, float DisplayTime)
{
    if (bToScreen)
    {
        GEngine->AddOnScreenDebugMessage(DEFAULT_SLOT, DisplayTime, FColor::Red, Message);
    }

    UE_LOG(LogTemp, Fatal, TEXT("%s"), *Message);
}



