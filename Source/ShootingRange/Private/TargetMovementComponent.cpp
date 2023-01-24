// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetMovementComponent.h"

UTargetMovementComponent::UTargetMovementComponent() {
	this->travelledDistance = 0;
	this->Velocity = FVector(10, 0, 0);
}

void UTargetMovementComponent::TickComponent
(
	float DeltaTime,
	enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction
) {
	FHitResult Hit;
	SafeMoveUpdatedComponent(UpdatedComponent->GetRelativeRotation().RotateVector(this->Velocity)*DeltaTime, UpdatedComponent->GetRelativeRotation(), false, Hit);
	if (Hit.IsValidBlockingHit()) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Hit.GetActor()->GetActorLabel())
		if(Hit.GetActor()->ActorHasTag("Border"))
		UpdatedComponent->GetOwner()->Destroy();
	}
	this->travelledDistance += float(this->Velocity.Size()) * DeltaTime;
	if (this->travelledDistance >= this->maxDistance) {
		UpdatedComponent->GetOwner()->Destroy();
	}
}