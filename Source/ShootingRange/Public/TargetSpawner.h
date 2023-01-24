// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>
#include <random>
#include "Components/BoxComponent.h"
#include "Target.h"
#include "TargetSpawner.generated.h"

UCLASS()
class SHOOTINGRANGE_API ATargetSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	FVector maximumVelocity = FVector(10, 0, 0);

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ATarget> target;

	UPROPERTY(EditAnywhere)
		TArray<class UBoxComponent*> SpawnVolumes = {};


	float spawnInterval = 5;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float timeBuffer = 0;

	void SpawnTarget();
	
	std::mt19937 rng;

	unsigned int RandomNumber(unsigned int min, unsigned int max);

	float RandomFloat(float min, float max);
};