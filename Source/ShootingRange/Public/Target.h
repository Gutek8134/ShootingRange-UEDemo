// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetMovementComponent.h"
#include "Target.generated.h"

UCLASS()
class SHOOTINGRANGE_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

	void SetVelocity(FVector velocity);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UTargetMovementComponent* movement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
