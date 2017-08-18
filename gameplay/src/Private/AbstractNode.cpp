// Fill out your copyright notice in the Description page of Project Settings.

#include "AbstractNode.h"


// Sets default values for this component's properties
UAbstractNode::UAbstractNode()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	this->Status = ENodeStatus::INVISIBLE;
}

// Called every frame
void UAbstractNode::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	switch (this->Status) {

	case ENodeStatus::INVISIBLE:
		this->InvisibleTickExec.ExecuteIfBound(DeltaTime, TickType);
		break;
	case ENodeStatus::VISIBLE:
		this->VisibleTickExec.ExecuteIfBound(DeltaTime, TickType);
		break;
	case ENodeStatus::AWAKEN:
		this->AwakenTickExec.ExecuteIfBound(DeltaTime, TickType);
		break;
	case ENodeStatus::REACTIVE:
		this->ReactiveTickExec.ExecuteIfBound(DeltaTime, TickType);
		break;
	}

	this->TickNode(DeltaTime, TickType);
}

void UAbstractNode::SetStatus(ENodeStatus Status) {

	this->Status = Status;
	this->StatusChangeEvent.Broadcast(Status);
}

