// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Bullet.h"
#include "BulletPoolManager.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PlayerMove.h"
#include "PlayerAttack.h"
#include "PlayerCamera.h"

// Sets default values
ATPSPlayer::ATPSPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
	playerAttack = CreateDefaultSubobject<UPlayerAttack>(TEXT("PlayerAttack"));
	playerCamera = CreateDefaultSubobject<UPlayerCamera>(TEXT("PlayerCamera"));
	// 1.스켈레탈 메쉬 불러오기
	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonWraith/Characters/Heroes/Wraith/Meshes/Wraith.Wraith'"));

	if (tempMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(tempMesh.Object);
		// mesh컴포넌트 위치 설정
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));

		playerCamera->springArm->SetupAttachment(RootComponent);
		playerCamera->springArm->SetRelativeLocation(FVector(0, 70, 90));
		playerCamera->springArm->TargetArmLength = 400;
		playerCamera->springArm->bUsePawnControlRotation = true;

		playerCamera->tpsCamera->SetupAttachment(playerCamera->springArm);
		playerCamera->tpsCamera->bUsePawnControlRotation = false;
	}
}

// Called when the game starts or when spawned
void ATPSPlayer::BeginPlay()
{
	Super::BeginPlay();
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

	// 이동 컴포넌트에서 입력 바인딩 처리하도록 호출
	playerMove->SetupInputBinding(PlayerInputComponent);
	// 공격 컴포넌트에서 입력 바인딩 처리하도록 호출
	playerAttack->SetupInputBinding(PlayerInputComponent);
}