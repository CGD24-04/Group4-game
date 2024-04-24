// Fill out your copyright notice in the Description page of Project Settings.
//OWNED BY: JACK

#include "TorchComponent.h"

#include "Logging/StructuredLog.h"

void UTorchComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<USceneComponent*> Components;
	GetChildrenComponents(false, Components);
	for (auto Component : Components)
	{
		if (auto SpotLightComponent = Cast<USpotLightComponent>(Component))
		{
			LightComponent = SpotLightComponent;
			break;
		}
	}
	
	if (LightComponent)
	{
		LightIntensity = LightComponent->Intensity;
		ToggleTorch(bIsEnabledByDefault);
	}
	else
	{
		PrintDebug();
	}
}

void UTorchComponent::ToggleTorch(bool bState)
{
	bIsTorchOn = bState;
	if(LightComponent)
	{
		LightComponent->SetIntensity(bState ? LightIntensity : 0.0f);
	}
	else
	{
		PrintDebug();
	}
}

void UTorchComponent::PrintDebug()
{
#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT || UE_BUILD_SHIPPING_WITH_EDITOR
	UE_LOGFMT(LogCore, Warning, "No Spotlight Component on Torch - Will not work!");
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Orange,
		   TEXT("No Spotlight Component on Torch - Will not work!"));
	}
#endif
}