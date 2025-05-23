// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Bullet.h"
#include "BulletPoolManager.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PlayerMove.h"
#include "PlayerAttack.h"

// Sets default values
ATPSPlayer::ATPSPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
	playerAttack = CreateDefaultSubobject<UPlayerAttack>(TEXT("PlayerAttack"));

	// 1.���̷�Ż �޽� �ҷ�����
	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonWraith/Characters/Heroes/Wraith/Meshes/Wraith.Wraith'"));

	if (tempMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(tempMesh.Object);
		// mesh������Ʈ ��ġ ����
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));

		// ī�޶� ���̱�
		// springArm������Ʈ ����
		springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
		springArmComp->SetupAttachment(RootComponent);
		springArmComp->SetRelativeLocation(FVector(0, 70, 90));
		springArmComp->TargetArmLength = 400;
		springArmComp->bUsePawnControlRotation = true;

		// ī�޶� ������Ʈ ����
		tpsCamComp = CreateDefaultSubobject<UCameraComponent>(TEXT("TpsCamComp"));
		tpsCamComp->SetupAttachment(springArmComp);
		tpsCamComp->bUsePawnControlRotation = false;

		bUseControllerRotationYaw = true;
	}
}

// Called when the game starts or when spawned
void ATPSPlayer::BeginPlay()
{
	Super::BeginPlay();

	//if (!bulletPoolManager && bulletPoolManagerActor)
	//{
	//	FTransform spawnTransform = FTransform::Identity;
	//	FActorSpawnParameters spawnParams;
	//	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	//	// bulletPoolManagerActor�κ��� ���� ���� ����
	//	bulletPoolManager = GetWorld()->SpawnActor<ABulletPoolManager>(
	//		bulletPoolManagerActor,
	//		spawnTransform,
	//		spawnParams
	//	);

	//	if (bulletPoolManager && bulletFactory)
	//	{
	//		// �Ѿ� ���丮 ����
	//		bulletPoolManager->bulletFactory = bulletFactory;
	//	}
	//}
}

// Called every frame
void ATPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// �̵� ������Ʈ���� �Է� ���ε� ó���ϵ��� ȣ��
	playerMove->SetupInputBinding(PlayerInputComponent);
	// ���� ������Ʈ���� �Է� ���ε� ó���ϵ��� ȣ��
	playerAttack->SetupInputBinding(PlayerInputComponent);

	// �Ѿ� �߻� �̺�Ʈ ó�� �Լ� ���ε�
	//PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATPSPlayer::InputFire);

}

//void ATPSPlayer::InputFire()
//{
//	if (!bulletPoolManager)
//		return;
//
//	FTransform fireTransform = GetMesh()->GetSocketTransform(TEXT("FirePosition"));
//	ABullet* bullet = bulletPoolManager->GetBullet();
//
//	if (bullet)
//	{
//		bullet->SetActorTransform(fireTransform);
//		bullet->movementComp->Velocity = fireTransform.GetRotation().Vector() * bullet->movementComp->InitialSpeed;
//		bullet->Fire();
//	}
//}