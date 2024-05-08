// Fill out your copyright notice in the Description page of Project Settings.
//OWNED BY: JACK

#include "IsometricCameraComponent.h"

#include "GameFramework/Character.h"

// Sets default values for this component's properties
UIsometricCameraComponent::UIsometricCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->bDoCollisionTest = false;
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
	if (ACharacter* _ = Cast<ACharacter>(Owner))
		bIsOwnerCharacter = true;
	else
		bIsOwnerCharacter = false;
	
	UpdateSpringArm();
	UpdateCamera();
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

	UpdateSpringArm();
	UpdateCamera();
}

void UIsometricCameraComponent::UpdateCamera()
{
	if (!Camera)
		return;

	Camera->FieldOfView = CameraFieldOfView;
	Camera->SetWorldRotation(FRotator::MakeFromEuler(RotationOffset));
}

void UIsometricCameraComponent::UpdateSpringArm()
{
	if (!SpringArm)
		return;

	SpringArm->TargetOffset = PositionOffset;
	
	bool bInherit = bAutomaticallyDetermineActorType && bIsOwnerCharacter ? true : bInheritRotation;
	
	SpringArm->bInheritPitch = bInherit;
	SpringArm->bInheritRoll = bInherit;
	SpringArm->bInheritYaw = bInherit;
}
