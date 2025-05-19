// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TPSPlayer.generated.h"

UCLASS()
class MYPROJECT_API ATPSPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPSPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Move function
public:
	// 좌우 회전 입력 처리
	void Turn(float value);
	// 상하 회전 입력 처리
	void LookUp(float value);

	// 좌우 이동 입력 이벤트 처리 함수
	void InputHorizontal(float value);
	// 상하 이동 입력 이벤트 처리 함수
	void InputVertical(float value);

	// 이동 처리 함수
	void Move();
	// 점프 입력 이벤트 처리 함수
	void InputJump();

	// Attack function
public:
	void InputFire();



	//Camera variable
public:
	// 카메라 부모 스프링암 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* springArmComp;
	// 카메라 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* tpsCamComp;

	// Move variable
public:
	// 이동 속도
	UPROPERTY(EditAnywhere, Category = "PlayerSetting")
	float walkSpeed = 600;
	// 이동 방향
	FVector direction;
	
	// Attack variable
public:

	// 총알
	UPROPERTY(EditAnywhere, Category = "BulletFactory")
	TSubclassOf<class ABullet> bulletFactory;
};