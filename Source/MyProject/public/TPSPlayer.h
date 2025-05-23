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

	// Attack function
public:
	//void InputFire();



	//Camera variable
public:
	// 카메라 부모 스프링암 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* springArmComp = nullptr;
	// 카메라 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* tpsCamComp = nullptr;

//	// Attack variable
//public:
//
//	// 총알
//	UPROPERTY(EditAnywhere, Category = "BulletFactory")
//	TSubclassOf<class ABullet> bulletFactory = nullptr;
//
//	UPROPERTY(EditAnywhere, Category = "BulletPool")
//	class ABulletPoolManager* bulletPoolManager = nullptr;
//
//	UPROPERTY(EditAnywhere, Category = "BulletPool")
//	TSubclassOf<class ABulletPoolManager> bulletPoolManagerActor = nullptr;


public:

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UPlayerBaseComponent* playerMove = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UPlayerBaseComponent* playerAttack = nullptr;
};