// Fill out your copyright notice in the Description page of Project Settings.

#include "Testing_ToolbarGraphics.h"
#include "ToolbarGraphics.h"

// Sets default values
ATesting_ToolbarGraphics::ATesting_ToolbarGraphics()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATesting_ToolbarGraphics::BeginPlay()
{
	Super::BeginPlay();
	ToolbarGraphics tb;
	
}

// Called every frame
void ATesting_ToolbarGraphics::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

