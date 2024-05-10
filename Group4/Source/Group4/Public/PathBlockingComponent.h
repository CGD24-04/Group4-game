// Fill out your copyright notice in the Description page of Project Settings.
//OWNED BY: JACK
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PathBlockingComponent.generated.h"

class ABlockingVolume;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GROUP4_API UPathBlockingComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly)
	TArray<TObjectPtr<ABlockingVolume>> Volumes;

	UPROPERTY(VisibleInstanceOnly)
	bool bActive = true;
	
public:	
	UPathBlockingComponent();

	UFUNCTION(BlueprintCallable)
	void Disable();

	UFUNCTION(BlueprintCallable)
	void Enable();

	UFUNCTION(BlueprintCallable)
	bool GetActiveState() const;
	
protected:
	virtual void BeginPlay() override;
};
