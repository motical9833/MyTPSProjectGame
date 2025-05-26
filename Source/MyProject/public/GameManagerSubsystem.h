// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UGameManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// 서브시스템이 생성되었을 때 호출되는 초기화 함수
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	// 게임 종료 또는 서브시스템이 제거될 때 호출되는 정리 함수
	virtual void Deinitialize() override;

public:
	void InitManagers(UWorld* World);
	class ABulletPoolManager* GetBulletManager() const;

private:
	UPROPERTY()
	class ABulletPoolManager* bulletPoolManager = nullptr;
};
