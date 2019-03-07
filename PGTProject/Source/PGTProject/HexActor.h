// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LayoutHelper.h"
#include "IntPoint.h"
#include "GameFramework/Actor.h"
#include "HexActor.generated.h"

UCLASS()
class PGTPROJECT_API AHexActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHexActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float deltaTime) override;

	template <typename Number>
	struct _Hex {
		union {
			const Number v[3];
			struct { const Number q, r, s; };
		};

		_Hex(Number q, Number r);
		_Hex(Number q, Number r, Number s);
	};
};