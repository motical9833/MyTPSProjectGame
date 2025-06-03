// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnim.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UPlayerAnim : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	// 매 프레임 갱신되는 함수
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void SetShootingReady(bool isShooting)
	{
		isShootingReady = isShooting;
	}

	void SetSniperModeReady(bool isSniper)
	{
		isSniperMode = isSniper;
	}

	// 플레이어 애니메이션 변수
public:

	// 플레이어 이동속도
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "PlayerAnim")
	float speed = 0;
	// 플레이어 좌우 이동 속도
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "PlayerAnim")
	float direction = 0;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "PlayerAnim")
	float pitch = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerAnim")
	float yaw = 0;

	// 플레이어가 공중에 있는지 여부
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "PlayerAnim")
	bool isinAir = false;
	// 사격 준비 자세 인지 아닌지
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerAnim")
	bool isShootingReady = false;
	// 저격총 모드 인지 아닌지
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "PlayerAnim")
	bool isSniperMode = false;
};