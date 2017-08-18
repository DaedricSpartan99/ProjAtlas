// Fill out your copyright notice in the Description page of Project Settings.

#include "Socket.h"

USocket::USocket() : UObject()
{
	this->intensity = 0.0f;
}

USocket::~USocket()
{
}

const TArray<AActor*>& USocket::GetDependencies() const {

	return this->dependencies;
}