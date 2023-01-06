// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class SHOOTINGRANGE_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
		class UBulletMovementComponent* movementComponent;

	UPROPERTY(EditAnywhere)
		int speed = 10;

	UPROPERTY(EditAnywhere)
		int maxDistance = 500;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
