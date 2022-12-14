// Fill out your copyright notice in the Description page of Project Settings.

#include "P_Player.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"

// Sets default values
AP_Player::AP_Player()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CameraRShoulderLocation = CreateDefaultSubobject<UArrowComponent>(TEXT("CameraRShoulderLocation"));
	CameraOriginLocation = CreateDefaultSubobject<UArrowComponent>(TEXT("CameraOriginLocation"));

	// Initialize the Camera Boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));

	// Setup Camera Boom attachment to the Root component of the class
	CameraBoom->SetupAttachment(RootComponent);

	// Set the boolean to use the PawnControlRotation to true.
	CameraBoom->bUsePawnControlRotation = true;

	// Initialize the FollowCamera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));

	// Set FollowCamera attachment to the Camera Boom
	FollowCamera->SetupAttachment(CameraBoom);
}

// Called when the game starts or when spawned
void AP_Player::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AP_Player::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("RotateX", this, &AP_Player::AddControllerYawInput);
	PlayerInputComponent->BindAxis("RotateY", this, &AP_Player::AddControllerPitchInput);
}