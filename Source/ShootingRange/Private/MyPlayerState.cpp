// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"

void AMyPlayerState::AddScore(float score) {
	this->SetScore(this->Score + score);
}