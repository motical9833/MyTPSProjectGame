// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTPSGameModeBase.h"
#include "MyProject.h"
#include "GameManagerSubsystem.h"

AMyTPSGameModeBase::AMyTPSGameModeBase()
{
	PRINT_LOG(TEXT("My Log : %s"), TEXT("TPS project!!"));
}

void AMyTPSGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// UGameManagerSubsystem ÃÊ±âÈ­
	if (UGameManagerSubsystem* manager = GetGameInstance()->GetSubsystem<UGameManagerSubsystem>())
	{
		manager->InitManagers(GetWorld());
	}
}
