// Fill out your copyright notice in the Description page of Project Settings.

#include "HexActor.h"

// Sets default values
AHexActor::AHexActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

template <typename Number>
struct _Hex { // Both storage types, both constructors
	union {
		const Number v[3];
		struct { const Number q, r, s; };
	};

	_Hex(Number q_, Number r_) : v{ q_, r_, -q_ - r_ } {}
	_Hex(Number q_, Number r_, Number s_) : v{ q_, r_, s_ } {}
};
typedef _Hex<int> Hex;

// Called when the game starts or when spawned
void AHexActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHexActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
