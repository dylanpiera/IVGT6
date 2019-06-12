#pragma once


//#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Pawn.h"
#include "HexActor.h"
#include "Engine/World.h"
#include "EconomyManager.h"
#include "MineralBuilding.h"
#include "EnergyBuilding.h"
#include "HouseBuilding.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CameraPawn.generated.h"


UCLASS()
/**
 * @brief Camera Class that handles input, raycasting and building placement.
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
	 * @brief Zoom in and out using scrollwheel
	 * 
	 * @param axisValue 
	 */
	void CameraZoom(float axisValue);

	/**
	 * @brief RotateLeft using the "Q" key
	 * 
	 * @param axisValue 
	 */
	void CameraRotationLeft(float axisValue);

	/**
	 * @brief Rotate right using the "E" key
	 * 
	 * @param axisValue 
	 */
	void CameraRotationRight(float axisValue);

	/**
	 * @brief Creates a Line Trace from screen to world
	 *	and returns a FHitResult containing
	 *	hit information for further use
	 * 
	 * @returns AActor
	 */
	FHitResult RayCast();


	void PlaceBuilding();

	UBuilding* SelectedBuilding(UBuilding* building, OptionSections mesh, AEconomyManager* ecoMan, AHexActor* hex, int engCost);
	
	/**
	* @brief Simple function to get the selected Actor from raycast hit
	*
	* @param h
	* @return AActor*
	*/
	AActor* SelectingActor(FHitResult h);
	
};
