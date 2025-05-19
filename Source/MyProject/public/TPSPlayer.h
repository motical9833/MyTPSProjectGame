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
	// �¿� ȸ�� �Է� ó��
	void Turn(float value);
	// ���� ȸ�� �Է� ó��
	void LookUp(float value);

	// �¿� �̵� �Է� �̺�Ʈ ó�� �Լ�
	void InputHorizontal(float value);
	// ���� �̵� �Է� �̺�Ʈ ó�� �Լ�
	void InputVertical(float value);

	// �̵� ó�� �Լ�
	void Move();
	// ���� �Է� �̺�Ʈ ó�� �Լ�
	void InputJump();

	// Attack function
public:
	void InputFire();



	//Camera variable
public:
	// ī�޶� �θ� �������� ������Ʈ
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* springArmComp;
	// ī�޶� ������Ʈ
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* tpsCamComp;

	// Move variable
public:
	// �̵� �ӵ�
	UPROPERTY(EditAnywhere, Category = "PlayerSetting")
	float walkSpeed = 600;
	// �̵� ����
	FVector direction;
	
	// Attack variable
public:

	// �Ѿ�
	UPROPERTY(EditAnywhere, Category = "BulletFactory")
	TSubclassOf<class ABullet> bulletFactory;
};