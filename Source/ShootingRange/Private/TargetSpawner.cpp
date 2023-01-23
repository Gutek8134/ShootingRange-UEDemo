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
	FVector location = FVector(0);
	auto box = SpawnVolumes[RandomNumber(0, SpawnVolumes.Num())];
	auto extent = box->GetScaledBoxExtent();
	
	GetWorld()->SpawnActor<AActor>(target, location, GetActorRotation());
}

unsigned int ATargetSpawner::RandomNumber(unsigned int min, unsigned int max) {
	auto dist = std::uniform_int_distribution<std::mt19937::result_type>(min, max);
	return dist(rng);
}

float ATargetSpawner::RandomFloat(float min, float max) {
	return 0;
}