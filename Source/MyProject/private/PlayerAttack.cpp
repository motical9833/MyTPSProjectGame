// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAttack.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BulletPoolManager.h"

UPlayerAttack::UPlayerAttack()
{
	// Tcik �Լ��� ȣ��ǵ��� ó��
	PrimaryComponentTick.bCanEverTick = false;


}

void UPlayerAttack::BeginPlay()
{
	Super::BeginPlay();

	if (!bulletPoolManager && bulletPoolManagerActor)
	{
		FTransform spawnTransform = FTransform::Identity;
		FActorSpawnParameters spawnParams;
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		// bulletPoolManagerActor�κ��� ���� ���� ����
		bulletPoolManager = GetWorld()->SpawnActor<ABulletPoolManager>(
			bulletPoolManagerActor,
			spawnTransform,
			spawnParams
		);

		if (bulletPoolManager && bulletFactory)
		{
			// �Ѿ� ���丮 ����
			bulletPoolManager->bulletFactory = bulletFactory;
		}
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