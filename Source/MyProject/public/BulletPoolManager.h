// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.h"
#include "BulletPoolManager.generated.h"

UCLASS()
class MYPROJECT_API ABulletPoolManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletPoolManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// �Ѿ� ��������
	ABullet* GetBullet();

public:
	// �Ѿ�
	UPROPERTY(EditAnywhere, Category = "Pooling")
	TSubclassOf<ABullet> bulletFactory = nullptr;

	// �Ѿ� Ǯ
	UPROPERTY()
	TArray<ABullet*> bulletPool;

	// �Ѿ� Ǯ ũ��
	UPROPERTY(EditAnywhere, Category = "Pooling")
	int32 poolSize = 20;
};
