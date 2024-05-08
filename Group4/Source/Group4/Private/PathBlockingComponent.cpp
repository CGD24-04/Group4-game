// Fill out your copyright notice in the Description page of Project Settings.
//OWNED BY: JACK

#include "PathBlockingComponent.h"

#include "Engine/BlockingVolume.h"

UPathBlockingComponent::UPathBlockingComponent()
{
}

void UPathBlockingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPathBlockingComponent::Enable()
{
	bActive = true;
	for (TObjectPtr<ABlockingVolume> Volume : Volumes)
	{
		Volume->SetActorEnableCollision(true);
	}
}

void UPathBlockingComponent::Disable()
{
	bActive = false;
	for (TObjectPtr<ABlockingVolume> Volume : Volumes)
	{
		Volume->SetActorEnableCollision(false);
	}
}

bool UPathBlockingComponent::GetActiveState() const
{
	return bActive;
}
