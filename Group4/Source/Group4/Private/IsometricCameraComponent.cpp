// Fill out your copyright notice in the Description page of Project Settings.


#include "IsometricCameraComponent.h"

// Sets default values for this component's properties
UIsometricCameraComponent::UIsometricCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;
	SpringArm->TargetOffset = PositionOffset;
	SpringArm->TargetArmLength = 0;
	SpringArm->SetupAttachment(this);
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetWorldRotation(FRotator::MakeFromEuler(RotationOffset));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts
void UIsometricCameraComponent::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	Owner->AddInstanceComponent(SpringArm);
	Owner->AddInstanceComponent(Camera);
}

void UIsometricCameraComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	if (SpringArm)
		SpringArm->DestroyComponent();
	
	if (Camera)
		Camera->DestroyComponent();
}

// Called every frame
void UIsometricCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (SpringArm)
		SpringArm->TargetOffset = PositionOffset;

	if (Camera)
		Camera->SetWorldRotation(FRotator::MakeFromEuler(RotationOffset));
}