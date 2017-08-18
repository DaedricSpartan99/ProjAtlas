// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbstractNode.h"
#include "AbstractLink.generated.h"


UCLASS(abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ATLAS_API UAbstractLink : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbstractLink();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void TickLink(float DeltaTime, ELevelTick TickType) PURE_VIRTUAL(UAbstractLink::TickLink,);

	UFUNCTION(BlueprintImplementableEvent, Category = "Link")
		void Break();

	UFUNCTION(BlueprintCallable, Category = "Link")
		void Setup(UAbstractNode *Alpha, UAbstractNode *Beta);

	UFUNCTION(BlueprintCallable, Category = "Link")
		void TryBreak(float Energy);

	UPROPERTY(BlueprintReadOnly, Category = "Link")
		UAbstractNode * Alpha;
	
	UPROPERTY(BlueprintReadOnly, Category = "Link")
		UAbstractNode * Beta;

	UPROPERTY(BlueprintReadWrite, Category = "Link")
		float BreakEnergy;
};
