// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"

// Sets default values
ATarget::ATarget()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	movement = CreateDefaultSubobject<UTargetMovementComponent>(TEXT("Target Movement Component"));
	movement->UpdatedComponent = RootComponent;
}

void ATarget::SetVelocity(FVector velocity) {
	this->movement->Velocity = velocity;
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

