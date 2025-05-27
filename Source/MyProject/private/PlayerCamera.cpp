// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCamera.h"

UPlayerCamera::UPlayerCamera()
{
	PrimaryComponentTick.bCanEverTick = false;

	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	tpsCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TpsCamComp"));
}

void UPlayerCamera::BeginPlay()
{
	Super::BeginPlay();
}

// 플레이어 카메라 세팅
void UPlayerCamera::CameraInitialize(class USceneComponent* InParent,FVector RelativeLocation,float TargetArmLength)
{
	springArm->SetupAttachment(InParent);
	springArm->SetRelativeLocation(RelativeLocation);
	springArm->TargetArmLength = TargetArmLength;
	springArm->bUsePawnControlRotation = true;

	tpsCamera->SetupAttachment(springArm);
	tpsCamera->bUsePawnControlRotation = false;
}