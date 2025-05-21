// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class MYPROJECT_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	void InitializeBullet();
	void DisableBullet();
	void Fire();

public:
	// �̵� ������Ʈ
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UProjectileMovementComponent* movementComp;
	// �浹 ������Ʈ
	UPROPERTY(VisibleAnywhere, Category = "Collision")
	class USphereComponent* collisionComp;
	// �ܰ� ������Ʈ
	UPROPERTY(VisibleAnywhere, Category = "BodyMesh")
	class UStaticMeshComponent* bodyMeshComp;

	// �Ѿ� Ÿ�̸�
	FTimerHandle lifeTimerHandle;
};
