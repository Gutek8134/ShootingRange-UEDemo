// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "BulletMovementComponent.h"

// Sets default values
ABullet::ABullet()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

	movementComponent = CreateDefaultSubobject<UBulletMovementComponent>(TEXT("MovementComponent"));
	movementComponent->SetUpdatedComponent(RootComponent);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

