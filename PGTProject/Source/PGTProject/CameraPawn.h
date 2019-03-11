// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CameraPawn.generated.h"


UCLASS()
class PGTPROJECT_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	USceneComponent* RootScene;


	USpringArmComponent* SpringArm;


	UCameraComponent* CameraComp;


	APlayerController* PC;

	float margin;


	int32 screenSizeX;


	int32 screenSizeY;


	float camSpeed = 3;

	float mouseAxisValue;

	float rotation;
	

	UFUNCTION()
	void GetCameraPanDirection();

	void CameraZoom(float axisValue);

	void CameraRotationLeft(float axisValue);

	void CameraRotationRight(float axisValue);



	
	
};
