// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerCamera.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UPlayerCamera : public UPlayerBaseComponent
{
	GENERATED_BODY()
	
public:
	UPlayerCamera();

	virtual void BeginPlay() override;

	USpringArmComponent* GetSpringArm() { return springArm; }
	UCameraComponent* GetCamera() { return tpsCamera; }
	void CameraInitialize(class USceneComponent* InParent, FVector RelativeLocation, float TargetArmLength);

private:
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* springArm;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* tpsCamera;
};
