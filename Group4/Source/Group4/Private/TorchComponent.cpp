// Fill out your copyright notice in the Description page of Project Settings.
//OWNED BY: JACK

#include "TorchComponent.h"

//TODO: Figure out how to make this appear in the inspector.

UTorchComponent::UTorchComponent()
{
	LightComponent = CreateDefaultSubobject<USpotLightComponent>(TEXT("Flashlight"));
	LightComponent->SetupAttachment(this);
	LightComponent->RegisterComponent();
}

void UTorchComponent::OnComponentCreated()
{
	//LightComponent->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void UTorchComponent::BeginPlay()
{
	Super::BeginPlay();
	
	ToggleFlashlight(bIsEnabledByDefault);
}

void UTorchComponent::ToggleFlashlight(bool bState)
{
	bIsTorchOn = bState;
	if(LightComponent)
		LightComponent->SetActive(bState);
}
