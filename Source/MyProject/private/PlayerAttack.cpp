// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAttack.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BulletPoolManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameManagerSubsystem.h"
#include "PlayerAnim.h"

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
}

void UPlayerAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPlayerAttack::SetupInputBinding(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &UPlayerAttack::NomalAttack);
	PlayerInputComponent->BindAction(TEXT("ShootingMode"), IE_Pressed, this, &UPlayerAttack::StartShootingMode);
	PlayerInputComponent->BindAction(TEXT("ShootingMode"), IE_Released, this, &UPlayerAttack::EndShootingMode);
}

void UPlayerAttack::NomalAttack()
{
	if (!bulletPoolManager)
		return;

	FTransform fireTransform = me->GetMesh()->GetSocketTransform(TEXT("FirePosition"));
	ABullet* bullet = bulletPoolManager->GetBullet();

	if (bullet)
	{
		bullet->SetActorTransform(fireTransform);
		bullet->movementComp->Velocity = fireTransform.GetRotation().Vector() * bullet->movementComp->InitialSpeed;
		bullet->Fire();
	}
}

void UPlayerAttack::SniperAttack()
{
	if (!bulletPoolManager)
		return;
}

void UPlayerAttack::ChangeToSniperMode()
{

}

void UPlayerAttack::ChangeToGunMode()
{

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