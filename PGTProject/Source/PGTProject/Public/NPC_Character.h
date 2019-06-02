// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterController.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "NPC_Character.generated.h"

UCLASS()
class PGTPROJECT_API ANPC_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* CharacterCapsule;

	UPROPERTY(VisibleAnywhere, Category = SkeletalMesh)
	class USkeletalMesh* MeshContainer;

	UPROPERTY(VisibleAnywhere, Category = SkeletalMesh)
	class USkeletalMeshComponent* CharacterMesh;

	UFUNCTION(BlueprintImplementableEvent, Category = "MoveCharacterEvent")
	void MoveToLocation(const FVector& newLocation);

	UFUNCTION(BlueprintNativeEvent)
	void TEST();
private:
	// Load character mesh and attach to this character
	void LoadMesh();
	void MoveTo(FVector place);
};
