// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Klan.h"
#include "AbstractNode.h"
#include "Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ATLAS_API IInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Klan")
		void GetNodes(TArray<UAbstractNode*> &List);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Klan")
		void SetAllNodesStatus(ENodeStatus Status);
};
