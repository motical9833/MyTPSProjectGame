// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TPSPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerBaseComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UPlayerBaseComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerBaseComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// 사용자 입력 맵핑 처리 함수
	virtual void SetupInputBinding(class UInputComponent* PlayerInputComponent) {};

public:
	// 컴포넌트를 소유한 액터
	ATPSPlayer* me = nullptr;

	UPROPERTY()
	UCharacterMovementComponent* moveComp = nullptr;
};