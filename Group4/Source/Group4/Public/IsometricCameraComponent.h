// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "IsometricCameraComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GROUP4_API UIsometricCameraComponent : public USceneComponent
{
	GENERATED_BODY()

	UPROPERTY()
	UCameraComponent* Camera;
	UPROPERTY()
	USpringArmComponent* SpringArm;

	UPROPERTY()
	AActor* Owner;

	bool bIsOwnerCharacter;

	void UpdateCamera();
	void UpdateSpringArm();
public:	
	// Sets default values for this component's properties
	UIsometricCameraComponent();

	//If true, ignores bInheritRotation - will determine that value automatically
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Isometric Camera|Spring Arm")
	bool bAutomaticallyDetermineActorType = true;
	//Determines if the Camera inherits rotation from the parent Actor.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Isometric Camera|Spring Arm")
	bool bInheritRotation = false;

	//Camera Field of View
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Isometric Camera|Camera", meta = (ClampMin = "20", ClampMax = "170", UIMin = "20", UIMax = "170"))
	float CameraFieldOfView = 90.0f;
	
	//The Camera Position relative to the Actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Isometric Camera|Camera")
	FVector PositionOffset = {-500, -500, 750};
	//The Camera Rotation relative to the Actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Isometric Camera|Camera")
	FVector RotationOffset = {0, -45, 45};
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
