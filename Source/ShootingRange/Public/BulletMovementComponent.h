// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BulletMovementComponent.generated.h"

/**
 *
 */
UCLASS()
class SHOOTINGRANGE_API UBulletMovementComponent : public UProjectileMovementComponent
{
	GENERATED_BODY()

public:
	UBulletMovementComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int speed = 10;

	int maxDistance = 500;

	float travelledDistance;

protected:
	virtual void TickComponent
	(
		float DeltaTime,
		enum ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;

};
