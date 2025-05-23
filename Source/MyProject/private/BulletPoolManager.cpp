// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletPoolManager.h"
#include "MyProject.h"

// Sets default values
ABulletPoolManager::ABulletPoolManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABulletPoolManager::BeginPlay()
{
	Super::BeginPlay();
	
	if (!bulletFactory)
	{
		PRINT_LOG(TEXT("My Log : %s"), TEXT("null BulletFactory!!"));
		return;
	}

	// ÃÑ¾Ë »ý¼º
	for (int32 i = 0; i < poolSize; i++)
	{
		ABullet* newBullet = GetWorld()->SpawnActor<ABullet>(bulletFactory, FVector::ZeroVector, FRotator::ZeroRotator);
		newBullet->InitializeBullet();
		bulletPool.Add(newBullet);
	}

}

// Called every frame
void ABulletPoolManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ABullet* ABulletPoolManager::GetBullet()
{
	for (ABullet* bullet : bulletPool)
	{
		if (!bullet->IsActorTickEnabled())
		{
			return bullet;
		}
	}

	return nullptr;
}

