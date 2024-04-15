// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryObject.generated.h"

//all the item types that are currently planned to be in the game
//which can be added to inventory 
UENUM(BlueprintType)
enum EInventoryItems
{
	Screwdriver,
	Notebook,
	Torch,
	Revolver
};

USTRUCT(BlueprintType)
struct FInventoryObjectData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	TEnumAsByte<EInventoryItems> itemClass; //what type of object the item is

	UPROPERTY(BlueprintReadWrite)
	bool bHasUsageLimit; //if it has a usage limit before it is removed from inventory

	UPROPERTY(BlueprintReadWrite)
	int usagesRemaining; //how many usages it has left, should be checked after each use 

};