// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Bullet.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraRShoulderLocation = CreateDefaultSubobject<UArrowComponent>(TEXT("CameraRShoulderLocation"));
	CameraOriginLocation = CreateDefaultSubobject<UArrowComponent>(TEXT("CameraOriginLocation"));
	BulletSpawnLocation = CreateDefaultSubobject<UArrowComponent>(TEXT("BulletSpawnLocation"));

	// Initialize the Camera Boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));

	// Setup Camera Boom attachment to the Root component of the class
	CameraBoom->SetupAttachment(GetMesh());

	// Set the boolean to use the PawnControlRotation to true.
	CameraBoom->bUsePawnControlRotation = true;

	// Initialize the FollowCamera
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));

	// Set FollowCamera attachment to the Camera Boom
	CameraComp->SetupAttachment(CameraBoom);
	CameraRShoulderLocation->SetupAttachment(GetMesh());
	CameraOriginLocation->SetupAttachment(GetMesh());
	offset = FVector(0);
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
	SetActorRotation(FRotator(0, GetControlRotation().Yaw, 0));
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("RotateX", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("RotateY", this, &AMyCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Shoot", IE_Released, this, &AMyCharacter::Shoot);
}

void AMyCharacter::Shoot() {
	GetWorld()->SpawnActor<ABullet>(GetActorLocation() + offset, GetController()->GetControlRotation());
	UE_LOG(LogTemp, Warning, TEXT("Shot!"))
}