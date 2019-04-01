// Fill out your copyright notice in the Description page of Project Settings.

#include "ToolbarActor.h"

// Sets default values
AToolbarActor::AToolbarActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AToolbarActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AToolbarActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

