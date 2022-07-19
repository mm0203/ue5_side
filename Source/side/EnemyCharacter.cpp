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

	// 初期速度と初期位置の設定をする
	Velocity = 1.0f;                           // 追加
	StartLocation = this->GetActorLocation();  // 追加
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ここから追加
	FVector location = this->GetActorLocation();
	location.Y += Velocity;
	if (location.Y < StartLocation.Y || location.Y > StartLocation.Y + 500.0f)
	{
		Velocity = -Velocity;
	}
	this->SetActorLocation(location);
	// ここまで追加
	// 初期位置のZ+500まで上昇したら下降に転じて、0まで下がったらまた上昇させる

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
