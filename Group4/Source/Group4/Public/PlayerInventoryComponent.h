// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryObject.h"
#include "Components/ActorComponent.h"
#include "PlayerInventoryComponent.generated.h"

//script by: Robyn Botham
//this component is put onto the player to hold their inventory items
//when an inventory item is picked up it will store a struct of data in an FInventoryObjectData
//which it will then pass to this class to add to the inventory list

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GROUP4_API UPlayerInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FInventoryObjectData> ObjectsInInventory;

	//function to check if an object is in the inventory
	UFUNCTION(BlueprintCallable)
	bool IsInInventory(EInventoryItems itemType);

	//function to add items to inventory
	UFUNCTION(BlueprintCallable)
	void AddToInventory(FInventoryObjectData inventoryObject);

	//function to remove items from inventory
	UFUNCTION(BlueprintCallable)
	void RemoveFromInventory(FInventoryObjectData inventoryObject);

	//function to get items from inventory
	UFUNCTION(BlueprintCallable)
	FInventoryObjectData GetInventoryItemByType(EInventoryItems objectType);
	
	UFUNCTION(BlueprintCallable)
	int GetInventoryLength();
	
	// Sets default values for this component's properties
	UPlayerInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
