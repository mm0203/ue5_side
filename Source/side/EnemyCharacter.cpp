// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "sideCharacter.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);


}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	// �������x�Ə����ʒu�̐ݒ������
	Velocity = 1.0f;                           // �ǉ�
	StartLocation = this->GetActorLocation();  // �ǉ�
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ��������ǉ�
	FVector location = this->GetActorLocation();
	location.Y += Velocity;
	if (location.Y < StartLocation.Y || location.Y > StartLocation.Y + 500.0f)
	{
		Velocity = -Velocity;
	}
	this->SetActorLocation(location);
	// �����܂Œǉ�
	// �����ʒu��Z+500�܂ŏ㏸�����牺�~�ɓ]���āA0�܂ŉ���������܂��㏸������

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
