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