// Fill out your copyright notice in the Description page of Project Settings.
//OWNED BY: JACK

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/SpotLightComponent.h"
#include "TorchComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GROUP4_API UTorchComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UTorchComponent() = default;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Torch")
	bool bIsEnabledByDefault;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Torch")
	bool bIsTorchOn;
	
	UFUNCTION(BlueprintCallable, Category = "Torch")
	void ToggleTorch(bool bState);
	
protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY()
	TObjectPtr<USpotLightComponent> LightComponent;

	float LightIntensity = 0;

	static void PrintDebug();
};
