// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetSpawner.h"

// Sets default values
ATargetSpawner::ATargetSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	std::random_device dev;
	this->rng = std::mt19937(dev());
}

// Called when the game starts or when spawned
void ATargetSpawner::BeginPlay()
{
	Super::BeginPlay();
	GetComponents<UBoxComponent>(SpawnVolumes, true);

}

// Called every frame
void ATargetSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->timeBuffer += DeltaTime;
	if (this->timeBuffer >= this->spawnInterval) {
		SpawnTarget();
		this->timeBuffer = 0;
	}
}

void ATargetSpawner::SpawnTarget() {
	auto box = SpawnVolumes[RandomNumber(0, SpawnVolumes.Num() - 1)];
	FVector location = box->GetComponentLocation();
	auto extent = box->GetScaledBoxExtent();
	location.X += RandomFloat(-extent.X / 2, extent.X / 2);
	location.Y += RandomFloat(-extent.Y / 2, extent.Y / 2);
	location.Z += RandomFloat(-extent.Z / 2, extent.Z / 2);

	GetWorld()->SpawnActor<AActor>(target, location, box->GetComponentRotation());
}

unsigned int ATargetSpawner::RandomNumber(unsigned int min, unsigned int max) {
	if (min == max)
		return min;
	auto dist = std::uniform_int_distribution<std::mt19937::result_type>(min, max);
	return dist(rng);
}

float ATargetSpawner::RandomFloat(float min, float max) {
	if (min == max)
		return min;
	auto dist = std::uniform_real_distribution<float>(min, max);
	return dist(rng);
}