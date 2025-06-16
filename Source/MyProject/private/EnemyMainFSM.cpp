// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMainFSM.h"
#include "TPSPlayer.h"
#include "Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "MyProject.h"
#include "Components/CapsuleComponent.h"
#include "EnemyAnim.h"

// Sets default values for this component's properties
UEnemyMainFSM::UEnemyMainFSM()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyMainFSM::BeginPlay()
{
	Super::BeginPlay();

	// ...

	// 월드에서 플레이어 가져오기
	auto actor = UGameplayStatics::GetActorOfClass(GetWorld(), ATPSPlayer::StaticClass());
	// ATPSPlayer 타입으로 캐스팅
	target = Cast<ATPSPlayer>(actor);
	// 소유 객체 가져오기
	me = Cast<AEnemy>(GetOwner());

	// UEnemyAnim* 변수 할당
	anim = Cast<UEnemyAnim>(me->GetMesh()->GetAnimInstance());
}


// Called every frame
void UEnemyMainFSM::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	switch (mState)
	{
	case EEnemyState::Idle:
		IdleState();
		break;
	case EEnemyState::Move:
		MoveState();
		break;
	case EEnemyState::Attack:
		AttackState();
		break;
	case EEnemyState::Damage:
		DamageState();
		break;
	case EEnemyState::Die:
		DieState();
		break;
	default:
		break;
	}
}

// 대기 상태
void UEnemyMainFSM::IdleState()
{
	//시간 흐름
	currentTime += GetWorld()->DeltaTimeSeconds;

	if (currentTime > idleDelayTime)
	{
		// 상태 전환
		mState = EEnemyState::Move;
		// 시간 초기화
		currentTime = 0;

		// 애니메이션 상태 동기화
		anim->animState = mState;
	}
}

// 이동 상태
void UEnemyMainFSM::MoveState()
{
	// 목적지
	FVector destination = target->GetActorLocation();
	// 방향 구하기
	FVector dir = destination - me->GetActorLocation();
	// 방향으로 이동
	me->AddMovementInput(dir.GetSafeNormal());

	// 타겟과 일정 거리만큼 가까워 지면 상태 전환
	if (dir.Size() < attackRange)
	{
		// 상태 전환
		mState = EEnemyState::Attack;

		// 애니메이션 상태 동기화
		anim->animState = mState;
		// 공격 애니메이션 재생 활성화
		anim->bAttackPlay = true;
		// 공격 상태 전환 시 대기 시간이 바로 끝나도록 처리
		currentTime = attackDelayTime;
	}
}

// 공격 상태
void UEnemyMainFSM::AttackState()
{
	// 시간
	currentTime += GetWorld()->DeltaTimeSeconds;

	// 공격
	if (currentTime > attackDelayTime)
	{
		// 공격
		PRINT_LOG(TEXT("ATTACK"));
		// 경과 시간 초기화
		currentTime = 0;
		anim->bAttackPlay = true;
	}

	// 타깃과의 거리 구하기
	float distance = FVector::Distance(target->GetActorLocation(), me->GetActorLocation());
	// 타깃과의 거리 체크 -> 거리가 멀어졌다면
	if (distance > attackRange)
	{
		// 상태 전환
		mState = EEnemyState::Move;

		// 애니메이션 상태 동기화
		anim->animState = mState;
	}
}

// 피격 상태
void UEnemyMainFSM::DamageState()
{
	// 시간 흐름
	currentTime += GetWorld()->DeltaTimeSeconds;

	// 대기 시간을 초과했다면
	if (currentTime > damageDelayTime)
	{
		// 상태 전환
		mState = EEnemyState::Idle;
		// 경과 시간 초기화
		currentTime = 0;
		// 애니메이션 상태 동기화
		anim->animState = mState;
	}
}

// 사망 상태
void UEnemyMainFSM::DieState()
{
	PRINT_LOG(TEXT("DIE!!!"));

	// 시체가 아래로 사라지도록 구현
	// 등속 운동
	FVector p0 = me->GetActorLocation();
	FVector vt = FVector::DownVector * dieSpeed * GetWorld()->DeltaTimeSeconds;
	FVector p = p0 + vt;
	me->SetActorLocation(p);

	if (p.Z < -200.0f)
	{
		// 제거
		me->Destroy();
	}

	// 애니메이션 상태 동기화
	anim->animState = mState;
}

void UEnemyMainFSM::OnDamageProcess()
{
	// 체력 감소
	hp--;

	if (hp > 0)
	{
		// 상태를 피격으로 전환
		mState = EEnemyState::Damage;
	}
	else
	{
		// 상태를 죽음으로 전환
		mState = EEnemyState::Die;
		// 캡슐 콜라이더 비활성화
		me->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}
