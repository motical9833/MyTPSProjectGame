// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyMainFSM.h"
#include "EnemyAnim.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UEnemyAnim : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	// 상태머신 변수
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FSM")
	EEnemyState animState;
	// 공격 애니메이션 재생할지 여부
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FSM")
	bool bAttackPlay = false;

public:
	// 공격 애니메이션이 끝나면 실행되는 이벤트 함수
	UFUNCTION(BlueprintCallable, Category = "FSMEvent")
	void OnEndAttackAnimaiton();

};
