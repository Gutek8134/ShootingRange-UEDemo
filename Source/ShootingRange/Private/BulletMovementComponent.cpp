// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletMovementComponent.h"

UBulletMovementComponent::UBulletMovementComponent() {
	InitialSpeed = speed;
	ProjectileGravityScale = 0;
}

void UBulletMovementComponent::TickComponent
(
	float DeltaTime,
	enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction
) {
	FHitResult Hit;
	SafeMoveUpdatedComponent(FVector(0, speed, 0), UpdatedComponent->GetComponentRotation(), false, Hit);
	if (!Hit.IsValidBlockingHit()) {
		UE_LOG(LogTemp, Warning, TEXT("Hit!"));
		UpdatedComponent->GetOwner()->Destroy();
	}
}