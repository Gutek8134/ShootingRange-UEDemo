// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "TargetMovementComponent.generated.h"

/**
 *
 */
UCLASS()
class SHOOTINGRANGE_API UTargetMovementComponent : public UMovementComponent
{
	GENERATED_BODY()

public:
	UTargetMovementComponent();

protected:
	virtual void TickComponent
	(
		float DeltaTime,
		enum ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float maxDistance = 10;

private:
	float travelledDistance;
};
