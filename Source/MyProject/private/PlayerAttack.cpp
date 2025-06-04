// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAttack.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BulletPoolManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameManagerSubsystem.h"
#include "PlayerAnim.h"
#include "PlayerCamera.h"
#include "Kismet/GameplayStatics.h"

UPlayerAttack::UPlayerAttack()
{
	// Tcik 함수가 호출되도록 처리
	PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerAttack::BeginPlay()
{
	Super::BeginPlay();

	// bulletPoolManager 가져오기
	UGameManagerSubsystem* manager = GetWorld()->GetGameInstance()->GetSubsystem<UGameManagerSubsystem>();
	if (manager)
	{
		bulletPoolManager = manager->GetBulletManager();
	}

	 mePlayerAnim = Cast<UPlayerAnim>(me->GetMesh()->GetAnimInstance());

	 ChangeToGunMode();
}

void UPlayerAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPlayerAttack::SetupInputBinding(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &UPlayerAttack::NomalAttack);

	PlayerInputComponent->BindAction(TEXT("RifleGun"), IE_Pressed, this, &UPlayerAttack::ChangeToGunMode);
	PlayerInputComponent->BindAction(TEXT("SniperGun"), IE_Pressed, this, &UPlayerAttack::ChangeToSniperMode);

	PlayerInputComponent->BindAction(TEXT("ShootingMode"), IE_Pressed, this, &UPlayerAttack::StartShootingMode);
	PlayerInputComponent->BindAction(TEXT("ShootingMode"), IE_Released, this, &UPlayerAttack::EndShootingMode);

}

void UPlayerAttack::NomalAttack()
{
	if (!bReadyShootingMode || !bulletPoolManager)
		return;

	if (!bUsingSniperMode)
	{
		FTransform fireTransform = me->GetMesh()->GetSocketTransform(TEXT("FirePosition"));
		ABullet* bullet = bulletPoolManager->GetBullet();

		if (bullet)
		{
			bullet->SetActorTransform(fireTransform);
			bullet->movementComp->Velocity = fireTransform.GetRotation().Vector() * bullet->movementComp->InitialSpeed;
			bullet->Fire();
		}
	}
	else
	{
		// LineTrace의 시작 위치
		FVector startPos = me->playerCamera->GetCamera()->GetComponentLocation();
		// LineTrace의 종료 위치
		FVector endPos = me->playerCamera->GetCamera()->GetComponentLocation() +
			me->playerCamera->GetCamera()->GetForwardVector() * 5000;
		// LineTrace의 충돌 정보를 담을 변수
		FHitResult hitInfo;
		// 충돌 옵션 설정 변수
		FCollisionQueryParams params;
		// 자기 자신은 충돌에서 제외
		params.AddIgnoredActor(me);
		// Channel 필터를 이용한 LineTrace 충돌 검출(충돌 정보, 시작 위치, 종료 위치, 검출 채널, 충돌 옵션)
		bool bHit = GetWorld()->LineTraceSingleByChannel(hitInfo, startPos, endPos, ECC_Visibility, params);
		// LineTrace가 부딪혔을 때
		if (bHit)
		{
			// 충돌 처리
			
			// 이펙트 위치
			FTransform bulletTrans;
			// 부딪힌 위치 할당
			bulletTrans.SetLocation(hitInfo.ImpactPoint);
			// 총알 파편 효과 인스턴스 생성
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), bulletEffectFactory, bulletTrans);
		}
	}
}

void UPlayerAttack::SniperAttack()
{
	if (!bulletPoolManager)
		return;
}

void UPlayerAttack::ChangeToSniperMode()
{
	bUsingSniperMode = true;

	if (mePlayerAnim)
	{
		mePlayerAnim->SetSniperModeReady(true);
	}
}

void UPlayerAttack::ChangeToGunMode()
{
	bUsingSniperMode = false;

	if (mePlayerAnim)
	{
		mePlayerAnim->SetSniperModeReady(false);
	}
}

void UPlayerAttack::StartShootingMode()
{
	bReadyShootingMode = true;

	if (mePlayerAnim)
	{
		mePlayerAnim->SetShootingReady(true);
	}
}

void UPlayerAttack::EndShootingMode()
{
	bReadyShootingMode = false;

	if (mePlayerAnim)
	{
		mePlayerAnim->SetShootingReady(false);
	}
}

void UPlayerAttack::SniperAim()
{

}
