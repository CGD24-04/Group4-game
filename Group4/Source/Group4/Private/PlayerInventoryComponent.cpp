// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInventoryComponent.h"


bool UPlayerInventoryComponent::IsInInventory(EInventoryItems itemType)
{
	for (int i = 0; i < ObjectsInInventory.Num(); i++)
	{
		if (ObjectsInInventory[i].itemClass == itemType)
		{
			return true;
		}
	}
	return false; 
}

void UPlayerInventoryComponent::AddToInventory(FInventoryObjectData inventoryObject)
{
	ObjectsInInventory.Add(inventoryObject);
}

void UPlayerInventoryComponent::RemoveFromInventory(FInventoryObjectData inventoryObject)
{
	//this is really ineffienct and there is very likely a better way to do it 
	for (int i = 0; i < ObjectsInInventory.Num(); i++)
	{
		//can't directly compare so comparing the two values that matter most.
		if (ObjectsInInventory[i].itemClass == inventoryObject.itemClass && ObjectsInInventory[i].usagesRemaining == inventoryObject.usagesRemaining)
		{
			ObjectsInInventory.RemoveAt(i);
		}
	}
	
}

FInventoryObjectData UPlayerInventoryComponent::GetInventoryItemByType(EInventoryItems objectType)
{
	for (int i = 0; i < ObjectsInInventory.Num(); i++)
	{
		if (ObjectsInInventory[i].itemClass == objectType)
		{
			return ObjectsInInventory[i];
		}
	}
	//this needs changing 
	return ObjectsInInventory[-1];
}


int UPlayerInventoryComponent::GetInventoryLength()
{
	return ObjectsInInventory.Num();
}

// Sets default values for this component's properties
UPlayerInventoryComponent::UPlayerInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UPlayerInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

