#pragma once


//#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Pawn.h"
#include "HexActor.h"
#include "Engine/World.h"
#include "MineralBuilding.h"
#include "EnergyBuilding.h"
#include "HouseBuilding.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CameraPawn.generated.h"


UCLASS()
/**
 * @brief 
 * 
 */
class PGTPROJECT_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	/**
	 * @brief Construct a new ACameraPawn object, sets default values for this pawn's properties
	 * 
	 */
	ACameraPawn();

protected:
	/**
	 * @brief Called when the game starts or when spawned
	 * 
	 */
	virtual void BeginPlay() override;

public:	
	/**
	 * @brief Called every frame
	 * 
	 * @param DeltaTime 
	 */
	virtual void Tick(float DeltaTime) override;
	/**
	 * @brief Called to bind functionality to input
	 * 
	 * @param PlayerInputComponent 
	 */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UWorld* WRLD;

	UPROPERTY()
	USceneComponent* RootScene;

	UPROPERTY(EditAnywhere)	
	int32 CameraArmHeight;

	USpringArmComponent* SpringArm;


	UCameraComponent* CameraComp;


	APlayerController* PC;

	AActor* SelectedActor;

	float margin;


	int32 screenSizeX;


	int32 screenSizeY;


	float camSpeed;

	float mouseAxisValue;

	float rotation;
	

	UFUNCTION()
	/**
	 * @brief Get the Camera Pan Direction object
	 * 
	 */
	void GetCameraPanDirection();

	/**
	 * @brief 
	 * 
	 * @param axisValue 
	 */
	void CameraZoom(float axisValue);

	/**
	 * @brief 
	 * 
	 * @param axisValue 
	 */
	void CameraRotationLeft(float axisValue);

	/**
	 * @brief 
	 * 
	 * @param axisValue 
	 */
	void CameraRotationRight(float axisValue);

	/**
	 * @brief Creates a Line Trace from screen to world
	 * 
	 */
	void OnClickRayCast();

	/**
	 * @brief Simple function to get the selected Actor
	 * 
	 * @param h 
	 * @return AActor* 
	 */
	AActor* SelectingActor(FHitResult h);
	
};
