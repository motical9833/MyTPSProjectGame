// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMainFSM.h"

// Sets default values for this component's properties
UEnemyMainFSM::UEnemyMainFSM()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyMainFSM::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEnemyMainFSM::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	switch (mState)
	{
	case EEnemyState::Idle:
		IdleState();
		break;
	case EEnemyState::Move:
		MoveState();
		break;
	case EEnemyState::Attack:
		AttackState();
		break;
	case EEnemyState::Damage:
		DamageState();
		break;
	case EEnemyState::Die:
		DieState();
		break;
	default:
		break;
	}
}

void UEnemyMainFSM::IdleState()
{

}

void UEnemyMainFSM::MoveState()
{

}

void UEnemyMainFSM::AttackState()
{

}

void UEnemyMainFSM::DamageState()
{

}

void UEnemyMainFSM::DieState()
{

}

