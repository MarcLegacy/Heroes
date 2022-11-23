// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcherCharacter.h"

#include "Logger.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/HUD.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

AArcherCharacter::AArcherCharacter()
{
    GetCameraBoom()->SocketOffset.Set(0.0, 120.0, 75.0);
    bUseControllerRotationYaw = true;
    GetCharacterMovement()->bOrientRotationToMovement = false;
    GetMesh()->SetWorldLocationAndRotation(FVector(0.0, 0.0, -90), FRotator(0.0, 270.0, 0.0));
    bCanFire = true;
}

void AArcherCharacter::FireArrow()
{
    if (!bCanFire) return;

    bCanFire = false;

    const APlayerCameraManager* PlayerCameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
    CrosshairWorldLocation = PlayerCameraManager->K2_GetActorLocation();
    ImpactPoint = CrosshairWorldLocation + PlayerCameraManager->GetActorForwardVector() * FVector(15000.f, 15000.f, 15000.f);

    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    if (GetWorld()->LineTraceSingleByChannel(HitResult, CrosshairWorldLocation, ImpactPoint, ECC_Visibility, Params)) ImpactPoint = HitResult.ImpactPoint;

    ArrowSpawnLocation = GetMesh()->GetSocketTransform("arrow_socket").GetLocation();
    ArrowSpawnRotation = UKismetMathLibrary::MakeRotFromX(ImpactPoint - ArrowSpawnLocation);

    FActorSpawnParameters ActorSpawnParameters;
    ActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
    ActorSpawnParameters.Owner = this;
    ActorSpawnParameters.Instigator = this;

    if (ArrowClass != nullptr)
    {
        GetWorld()->SpawnActor(ArrowClass, &ArrowSpawnLocation, &ArrowSpawnRotation, ActorSpawnParameters);
    }
    else
    {
        FLogger::LogWarning("ArrowClass not set!");
    }

    if (AnimMontage != nullptr)
    {
        PlayAnimMontage(AnimMontage);
    }
    else
    {
        FLogger::LogWarning("AnimMontage not set!");
    }
}

void AArcherCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (ArrowClass == nullptr)
    {
        FLogger::LogWarning("ArrowClass not set!");
    }
    if (AnimMontage == nullptr)
    {
        FLogger::LogWarning("AnimMontage not set!");
    }
}

void AArcherCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AArcherCharacter::FireArrow);
}
