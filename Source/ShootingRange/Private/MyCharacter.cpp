// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Bullet.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraRShoulderLocation = CreateDefaultSubobject<UArrowComponent>(TEXT("CameraRShoulderLocation"));
	CameraOriginLocation = CreateDefaultSubobject<UArrowComponent>(TEXT("CameraOriginLocation"));
	// Initialize the FollowCamera
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));

	// Set FollowCamera attachment to the Camera Boom
	CameraComp->SetupAttachment(RootComponent);
	CameraRShoulderLocation->SetupAttachment(GetMesh());
	CameraOriginLocation->SetupAttachment(GetMesh());
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
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("RotateX", this, &AMyCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("RotateY", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAction("Shoot", IE_Released, this, &AMyCharacter::Shoot);
}

void AMyCharacter::Shoot() {
	GetWorld()->SpawnActor<ABullet>(bulletPos, GetActorRotation());
}