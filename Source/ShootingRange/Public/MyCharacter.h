// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "MyCharacter.generated.h"

UCLASS()
class SHOOTINGRANGE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	class USpringArmComponent *CameraBoom;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UCameraComponent *CameraComp;

	// Arrow Component for the Camera shoulder viewpoint location
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UArrowComponent *CameraRShoulderLocation;

	// Arrow Component for the Camera Origin viewpoint location
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UArrowComponent *CameraOriginLocation;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

};
