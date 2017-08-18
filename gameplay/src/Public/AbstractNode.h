// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AbstractNode.generated.h"

UENUM(BlueprintType)
enum class ENodeStatus : uint8 {

	INVISIBLE	UMETA(DisplayName = "Invisible"),
	VISIBLE		UMETA(DisplayName = "Visible"),
	AWAKEN		UMETA(DisplayName = "Awaken"),
	REACTIVE	UMETA(DisplayName = "Reactive")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNodeStatusChangeEvent, ENodeStatus, Status);

DECLARE_DELEGATE_TwoParams(FNodeInvisibleTick, float, ELevelTick);
DECLARE_DELEGATE_TwoParams(FNodeVisibleTick, float, ELevelTick);
DECLARE_DELEGATE_TwoParams(FNodeAwakenTick, float, ELevelTick);
DECLARE_DELEGATE_TwoParams(FNodeReactiveTick, float, ELevelTick);

UCLASS(abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ATLAS_API UAbstractNode : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbstractNode();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void TickNode(float DeltaTime, ELevelTick TickType) PURE_VIRTUAL(UAbstractNode::TickNode, );

	UFUNCTION(BlueprintCallable, Category = "Node")
		void SetStatus(ENodeStatus Status);

	UPROPERTY(BlueprintAssignable)
		FNodeStatusChangeEvent StatusChangeEvent;

	FNodeInvisibleTick InvisibleTickExec;

	FNodeVisibleTick VisibleTickExec;

	FNodeAwakenTick AwakenTickExec;

	FNodeReactiveTick ReactiveTickExec;

	UPROPERTY(BlueprintReadOnly)
		ENodeStatus Status;
};
