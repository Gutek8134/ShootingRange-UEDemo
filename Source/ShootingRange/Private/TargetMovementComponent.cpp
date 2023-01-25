// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetMovementComponent.h"

UTargetMovementComponent::UTargetMovementComponent() {
	this->travelledDistance = 0;
	this->Velocity = FVector(1000, 0, 0);
}

void UTargetMovementComponent::TickComponent
(
	float DeltaTime,
	enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction
) {
	FHitResult Hit;
	SafeMoveUpdatedComponent(UpdatedComponent->GetRelativeRotation().RotateVector(Velocity) * DeltaTime, UpdatedComponent->GetRelativeRotation(), true, Hit);
	if (Hit.IsValidBlockingHit()) {
		UpdatedComponent->GetOwner()->Destroy();
	}
	this->travelledDistance += float(this->Velocity.Size()) * DeltaTime;
	if (this->travelledDistance >= this->maxDistance) {
		UpdatedComponent->GetOwner()->Destroy();
	}
}