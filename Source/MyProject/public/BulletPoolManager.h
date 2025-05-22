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
	// ÃÑ¾Ë °¡Á®¿À±â
	ABullet* GetBullet();

public:
	// ÃÑ¾Ë
	UPROPERTY(EditAnywhere, Category = "Pooling")
	TSubclassOf<ABullet> bulletFactory = nullptr;

	// ÃÑ¾Ë Ç®
	UPROPERTY()
	TArray<ABullet*> bulletPool;

	// ÃÑ¾Ë Ç® Å©±â
	UPROPERTY(EditAnywhere, Category = "Pooling")
	int32 poolSize = 20;
};
