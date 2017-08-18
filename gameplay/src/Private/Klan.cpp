// Fill out your copyright notice in the Description page of Project Settings.

#include "Klan.h"


// Sets default values for this component's properties
UKlan::UKlan()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UKlan::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UKlan::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UKlan::Setup(class AActor *parent, class USphereComponent *rangeSphere) {

	this->parent = parent;
	this->rangeSphere = rangeSphere;
	this->rangeSphere->OnComponentBeginOverlap.AddDynamic(this, &UKlan::OnRangeEnter);
	this->rangeSphere->OnComponentEndOverlap.AddDynamic(this, &UKlan::OnRangeExit);
}

void UKlan::OnRangeEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

}

void UKlan::OnRangeExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {

}

void UKlan::PushAction(class USocket *socket) {

	this->actions.Add(socket);
}

void UKlan::RemoveAction(class USocket *socket) {

	this->actions.Remove(socket);
}

void UKlan::ClearActions() {

	this->actions.Empty();
}

