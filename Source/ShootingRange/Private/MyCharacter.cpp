// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorRotation(FRotator(GetControlRotation().Pitch, GetControlRotation().Yaw, 0));
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("RotateX", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("RotateY", this, &AMyCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Shoot", IE_Released, this, &AMyCharacter::Shoot);
}

void AMyCharacter::Shoot() {
	UE_LOG(LogTemp, Warning, TEXT("Shot!"));
	auto bullet = GetWorld()->SpawnActor<ABullet>(ProjectileType, this->GetActorLocation() + GetControlRotation().RotateVector(offset), this->GetControlRotation());
	bullet->movementComponent->UpdateScoreText.BindUFunction(this, "HitTarget");
}

void AMyCharacter::IncreaseScore(float value) {
	GetController()->GetPlayerState<AMyPlayerState>()->SetScore(GetController()->GetPlayerState<AMyPlayerState>()->GetScore() + value);
}