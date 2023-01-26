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
	SafeMoveUpdatedComponent(UpdatedComponent->GetRelativeRotation().RotateVector(FVector(speed*DeltaTime, 0, 0)), UpdatedComponent->GetRelativeRotation(), true, Hit);
	if (Hit.IsValidBlockingHit()) {
		if (Hit.GetActor()->ActorHasTag("target")) {
			UE_LOG(LogTemp, Warning, TEXT("Hit a target!"));
			auto state = GetWorld()->GetFirstPlayerController()->GetPlayerState<APlayerState>();
			if (state != NULL) {
				state->SetScore(state->GetScore() + 5);
			}
			UpdateScoreText.ExecuteIfBound();
			Hit.GetActor()->Destroy();
		}
		UpdatedComponent->GetOwner()->Destroy();
	}
	travelledDistance += (speed * DeltaTime);
	if (travelledDistance > maxDistance) {
		UE_LOG(LogTemp, Warning, TEXT("Max distance reached"));
		UpdatedComponent->GetOwner()->Destroy();
	}
}