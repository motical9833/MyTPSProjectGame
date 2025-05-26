// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAttack.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BulletPoolManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameManagerSubsystem.h"

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
}

void UPlayerAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}

void UPlayerAttack::SetupInputBinding(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &UPlayerAttack::NomalAttack);
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