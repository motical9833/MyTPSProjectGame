// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyMainFSM.generated.h"

// 에너미 상태 정의
UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Idle,
	Move,
	Attack,
	Damage,
	Die,
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UEnemyMainFSM : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyMainFSM();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
public:

	// 상태 변수
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FSM")
	EEnemyState mState = EEnemyState::Idle;

	// 대기 상태
	void IdleState();
	// 이동 상태
	void MoveState();
	// 공격 상태
	void AttackState();
	// 피격 상태
	void DamageState();
	// 죽음 상태
	void DieState();

	// 피격 알림 이벤트 함수
	void OnDamageProcess();

	// Idle 변수
public:

	// 대기 시간
	UPROPERTY(EditDefaultsOnly, Category = "FSM")
	float idleDelayTime = 2;
	// 경과 시간
	float currentTime = 0;

	// Move 변수
public:
	// 타깃
	UPROPERTY(VisibleAnywhere, Category = "FSM")
	class ATPSPlayer* target = nullptr;
	// 소유 액터
	UPROPERTY()
	class AEnemy* me = nullptr;

	// Attack 변수
public:
	// 공격 범위
	UPROPERTY(EditAnywhere, Category = "FSM")
	float attackRange = 150.0f;

	// 공격 대기 시간
	UPROPERTY(EditAnywhere, Category = "FSM")
	float attackDelayTime = 2.0f;
	
public:
	// 체력 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FSM")
	int32 hp = 100;
	// 피격 딜레이 시간
	float damageDelayTime = 2.0f;


	// Die 상태 변수
public:
	// 아래로 사라지는 속도
	UPROPERTY(EditAnywhere, Category = "FSM")
	float dieSpeed = 50.0f;

	// Anim 변수
public:
	UPROPERTY()
	class UEnemyAnim* anim;
};
