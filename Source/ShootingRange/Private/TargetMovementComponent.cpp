// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetMovementComponent.h"

UTargetMovementComponent::UTargetMovementComponent() {
	this->travelledDistance = 0;
}

void UTargetMovementComponent::TickComponent
(
	float DeltaTime,
	enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction
) {
	MoveUpdatedComponent(FVector(speed, 0, 0), UpdatedComponent->GetRelativeRotation(), true);
	this->travelledDistance += speed * DeltaTime;
	if (this->travelledDistance >= this->maxDistance) {
		UpdatedComponent->GetOwner()->Destroy();
	}

}