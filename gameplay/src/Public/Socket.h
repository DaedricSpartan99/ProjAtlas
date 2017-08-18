// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Socket.generated.h"

struct ActionFeedback {

	float energy;
};

/**
 * 
 */
UCLASS(abstract, ClassGroup = (Custom))
class ATLAS_API USocket : public UObject
{

	GENERATED_BODY()

public:

	USocket();
	~USocket();

	virtual void TickSocket(float DeltaTime, struct ActionFeedback& action) PURE_VIRTUAL(USocket::TickSocket,);

	UPROPERTY(BlueprintReadWrite)
	float intensity;

	UFUNCTION(BlueprintCallable, Category = "Socket")
		const TArray<AActor*>& GetDependencies() const;

protected:

	TArray<AActor*> dependencies;
};
