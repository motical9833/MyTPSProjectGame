// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseComponent.h"
#include "PlayerAttack.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UPlayerAttack : public UPlayerBaseComponent
{
	GENERATED_BODY()
	

public:
	UPlayerAttack();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetupInputBinding(class UInputComponent* PlayerInputComponent) override;

	// Attack function
public:
	void NomalAttack();


	// Attack variable
public:

	// ÃÑ¾Ë
	UPROPERTY(EditAnywhere, Category = "BulletFactory")
	TSubclassOf<class ABullet> bulletFactory = nullptr;

	UPROPERTY(EditAnywhere, Category = "BulletPool")
	class ABulletPoolManager* bulletPoolManager = nullptr;

	UPROPERTY(EditAnywhere, Category = "BulletPool")
	TSubclassOf<class ABulletPoolManager> bulletPoolManagerActor = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UPlayerBaseComponent* playerMove = nullptr;
};
