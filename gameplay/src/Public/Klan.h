// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SphereComponent.h"
#include "Socket.h"
#include "Klan.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ATLAS_API UKlan : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UKlan();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Klan")
		void Setup(class AActor *parent, class USphereComponent *rangeSphere);

	UFUNCTION()
		void OnRangeEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnRangeExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(BlueprintReadWrite)
		float Energy;

	UPROPERTY(BlueprintReadWrite)
		bool ActionsEnabled;

	UFUNCTION(BlueprintCallable, Category = "Klan")
		void PushAction(class USocket *socket);

	UFUNCTION(BlueprintCallable, Category = "Klan")
		void RemoveAction(class USocket *socket);

	UFUNCTION(BlueprintCallable, Category = "Klan")
		void ClearActions();

protected:

	TArray<class USocket*> actions;
	
private:

	AActor *parent;
	USphereComponent *rangeSphere;
};
