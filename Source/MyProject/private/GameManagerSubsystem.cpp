// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManagerSubsystem.h"
#include "BulletPoolManager.h"

void UGameManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

}

void UGameManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UGameManagerSubsystem::InitManagers(UWorld* World)
{
	if (!World) return;

	// 액터를 SpawnActor할 때 사용하느 설정 구조체
	// 충돌 처리,소유자,템플릿,인스턴스 이름등을 설정할 수 있음
	FActorSpawnParameters params;
	// SpawnCollisionHandlingOverride 스폰 시 충돌이 발생할 경우 어떻게 처리할지 지정
	// ESpawnActorCollisionHandlingMethod::AlwaysSpawn -> 충돌 여부와 무관하게 무조건 스폰
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// bulletPoolManager 생성
	bulletPoolManager = World->SpawnActor<ABulletPoolManager>(
		ABulletPoolManager::StaticClass(),
		FTransform::Identity,
		params);
}

ABulletPoolManager* UGameManagerSubsystem::GetBulletManager() const
{
	return bulletPoolManager;
}