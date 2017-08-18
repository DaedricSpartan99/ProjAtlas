// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Socket.generated.h"

struct Action {

	float energy;
	FVector force;
	float power;
	bool enough;

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

	virtual void TickSocket(float DeltaTime, struct Action& action) PURE_VIRTUAL(USocket::TickSocket,);

	UPROPERTY(BlueprintReadWrite)
	float intensity;
};
