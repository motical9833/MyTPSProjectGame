// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnim.h"
#include "TPSPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyProject.h"

void UPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	// 플레이어의 이동속도를 가져와 speed에 할당
	// 소유 폰 얻어오기
	auto ownerPawn = TryGetPawnOwner();
	// 플레이어로 캐스팅
	auto player = Cast<ATPSPlayer>(ownerPawn);

	// 캐스팅 성공
	if (player)
	{
		// 이동 속도 필요
		FVector velocity = player->GetVelocity();
		// 플레이어의 전방 벡터 구하기
		FVector forwardVector = player->GetActorForwardVector();
		// speed에 값(내적) 할당
		speed = FVector::DotProduct(forwardVector, velocity);
		// 좌우 속도 할당하기
		FVector rightVector = player->GetActorRightVector();
		direction = FVector::DotProduct(rightVector, velocity);
		// 플레이어가 현재 공중에 있는지 여부 체크
		auto movement = player->GetCharacterMovement();
		isinAir = movement->IsFalling();

		// 플레이어가 바라보는 각도 구하기
		FRotator aimRotation = player->GetBaseAimRotation();
		FRotator movementRotation = player->GetActorRotation();
		FRotator deltarot = (aimRotation - movementRotation).GetNormalized();
		pitch = deltarot.Pitch;
		yaw = deltarot.Yaw;
	}
}