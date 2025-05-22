// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseComponent.h"
#include "PlayerMove.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UPlayerMove : public UPlayerBaseComponent
{
	GENERATED_BODY()

public:
	UPlayerMove();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetupInputBinding(class UInputComponent* PlayerInputComponent) override;
public:
	// 좌우 회전 입력 처리
	void Turn(float value);
	//// 상하 회전 입력 처리
	void LookUp(float value);

	// 좌우 이동 입력 이벤트 처리 함수
	void InputHorizontal(float value);
	// 상하 이동 입력 이벤트 처리 함수
	void InputVertical(float value);

	// 이동 처리 함수
	void Move();
	// 점프 입력 이벤트 처리 함수
	void InputJump();

public:
	// 이동 속도
	UPROPERTY(EditAnywhere, Category = "PlayerSetting")
	float walkSpeed = 600;
	// 이동 방향
	FVector direction = FVector::ZeroVector;
};
