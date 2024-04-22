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
	UTorchComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsEnabledByDefault;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsTorchOn;

	UFUNCTION(BlueprintCallable)
	void ToggleFlashlight(bool bState);
	
protected:
	virtual void BeginPlay() override;
	virtual void OnComponentCreated() override;
	
private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpotLightComponent> LightComponent;
};
