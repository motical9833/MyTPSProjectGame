// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseComponent.h"
#include "PlayerAttack.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UPlayerAttack : public UPlayerBaseComponent
{
	GENERATED_BODY()
public:
	UPlayerAttack();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetupInputBinding(class UInputComponent* PlayerInputComponent) override;

	// Attack function
private:
	void NomalAttack();
	void SniperAttack();
	// 스나이퍼 모드로 전환
	void ChangeToSniperMode();
	// 기본 총으로 전환
	void ChangeToGunMode();
	// 사격 준비 상태 전환
	void StartShootingMode();
	// 사격 종료 상태 전환
	void EndShootingMode();
	// 스나이퍼 조준
	void SniperAim();
public:

	bool GetShootingMode() { return bReadyShootingMode; }

	// Attack variable
public:

	// 총알
	UPROPERTY(EditAnywhere, Category = "BulletFactory")
	TSubclassOf<class ABullet> bulletFactory = nullptr;

	UPROPERTY(EditAnywhere, Category = "BulletPool")
	class ABulletPoolManager* bulletPoolManager = nullptr;

	// 스나이퍼 모드인지 아닌지
	bool bUsingSniperMode = false;

	// 공격 준비 상태인지 아닌지
	bool bReadyShootingMode = false;

	UPROPERTY()
	class UPlayerAnim* mePlayerAnim = nullptr;
};
