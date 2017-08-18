// Fill out your copyright notice in the Description page of Project Settings.

#include "Klan.h"
#include "Interactable.h"


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

	if (this->ActionsEnabled) {

		for (auto& entry : this->SocketMap)
		{
			FSocketCaller * caller = &entry.Value;

			ActionFeedback feedback;

			caller->Execute(DeltaTime, feedback);

			this->Energy -= feedback.energy;

			if (this->Energy < 0.0f) {
				this->Energy = 0.0f;
				break;
			}
		}
	}
}

void UKlan::Setup(class AActor *parent, class USphereComponent *rangeSphere) {

	this->parent = parent;
	this->rangeSphere = rangeSphere;
	this->rangeSphere->OnComponentEndOverlap.AddDynamic(this, &UKlan::OnRangeExit);
}

void UKlan::OnRangeExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {

	IInteractable * inter = Cast<IInteractable>(OtherActor);

	//if (inter != 0)
		//inter->SetKlanNotAllowed(this);
}

void UKlan::SwitchControlMode(bool Value) {

	this->CtrlEvent.ExecuteIfBound(Value);
	this->ControlMode = Value;
	this->SetComponentTickEnabled(Value);
}

void UKlan::PushAction(class USocket *Socket) {

	FSocketCaller caller;
	caller.BindUObject(Socket, &USocket::TickSocket);
	this->SocketMap.Emplace(Socket, caller);
}

void UKlan::RemoveAction(class USocket *Socket) {

	FSocketCaller * caller = this->SocketMap.Find(Socket);

	if (caller != 0)
	{
		caller->Unbind();
		this->SocketMap.Remove(Socket);
	}
}

void UKlan::ClearActions() {

	for (auto& entry : this->SocketMap)
		entry.Value.Unbind();

	this->SocketMap.Empty();
}

