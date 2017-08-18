// Fill out your copyright notice in the Description page of Project Settings.

#include "AbstractLink.h"


// Sets default values for this component's properties
UAbstractLink::UAbstractLink()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	this->Alpha = 0;
	this->Beta = 0;
	this->BreakEnergy = 1.0f;
}


// Called when the game starts
void UAbstractLink::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAbstractLink::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	this->TickLink(DeltaTime, TickType);
}


void UAbstractLink::Setup(UAbstractNode *Alpha, UAbstractNode *Beta) {

	this->Alpha = Alpha;
	this->Beta = Beta;
}

void UAbstractLink::TryBreak(float Energy) {

	if (Energy >= this->BreakEnergy)
		this->Break();
}
