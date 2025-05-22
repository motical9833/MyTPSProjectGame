// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMove.h"

UPlayerMove::UPlayerMove()
{
	// Tcik �Լ��� ȣ��ǵ��� ó��
	PrimaryComponentTick.bCanEverTick = true;
}

void UPlayerMove::BeginPlay()
{
	Super::BeginPlay();
}

void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Move();
}

void UPlayerMove::SetupInputBinding(UInputComponent* PlayerInputComponent)
{
	// ���콺 ī�޶� ȸ�� �̺�Ʈ ó�� �Լ� ���ε�
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &UPlayerMove::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &UPlayerMove::LookUp);

	// �̵� �Է� �̺�Ʈ ó�� �Լ� ���ε�
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &UPlayerMove::InputHorizontal);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &UPlayerMove::InputVertical);
	
	// ���� �Է� �̺�Ʈ ó�� �Լ� ���ε�
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &UPlayerMove::InputJump);
}

void UPlayerMove::Turn(float value)
{
	me->AddControllerYawInput(value);
}

void UPlayerMove::LookUp(float value)
{
	me->AddControllerPitchInput(value);
}

void UPlayerMove::InputHorizontal(float value)
{
	direction.Y = value;
}

void UPlayerMove::InputVertical(float value)
{
	direction.X = value;
}

void UPlayerMove::Move()
{
	// �÷��̾� �̵� ó��
	direction = FTransform(me->GetControlRotation()).TransformVector(direction);
	me->AddMovementInput(direction);
	direction = FVector::ZeroVector;
}

void UPlayerMove::InputJump()
{
	me->Jump();
}
