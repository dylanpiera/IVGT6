// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraPawn.h"

// Sets default values
ACameraPawn::ACameraPawn()
{
	margin = 15;
	camSpeed = 3;
	rotation = 0;

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Sets camera controls ro player0 otherwise it crashes the editor
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootScene);
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetRelativeRotation(FRotator(-50, 0, 0));

	SpringArm->TargetArmLength = 200;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();

	PC = Cast<APlayerController>(GetController());
	PC->GetViewportSize(screenSizeX, screenSizeY);
	
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//AddActorWorldOffset(GetCameraPanDirection() * camSpeed);
	GetCameraPanDirection();
	
}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//MouseWheel input
	InputComponent->BindAxis("MouseWheelAxis", this, &ACameraPawn::CameraZoom);
	
	//Rotation Input
	InputComponent->BindAxis("RotateRight", this, &ACameraPawn::CameraRotationRight);
	InputComponent->BindAxis("RotateLeft", this, &ACameraPawn::CameraRotationLeft);
}

void ACameraPawn::GetCameraPanDirection()
{
	margin = 15;
	float mousePosX;
	float mousePosY;

	PC->GetMousePosition(mousePosX, mousePosY);

	// Pan left
	if (mousePosX <= margin)
	{
		//camDirectionY = -1;
		AddActorWorldOffset(RootScene->GetRightVector() * camSpeed * -1);
	}

	// Pan up
	if (mousePosY <= margin)
	{
		//camDirectionX = 1;
		AddActorWorldOffset(RootScene->GetForwardVector() * camSpeed);
	}

	// Pan right
	if (mousePosX >= screenSizeX - margin)
	{
		//camDirectionY = 1;
		AddActorWorldOffset(RootScene->GetRightVector() * camSpeed);
	}

	// Pan down
	if (mousePosY >= screenSizeY - margin)
	{
		//camDirectionX = -1;
		AddActorWorldOffset(RootScene->GetForwardVector() * camSpeed * -1);

	}
}

void ACameraPawn::CameraZoom(float axisValue)
{
	UE_LOG(LogTemp, Warning, TEXT("%f"), axisValue);

	//ZoomIn
	if(axisValue > 0)
		SpringArm->TargetArmLength -= 25;

	//ZoomOut
	if (axisValue < 0)
		SpringArm->TargetArmLength += 25;
}

void ACameraPawn::CameraRotationLeft(float axisValue)
{
	if (axisValue > 0)
	{
		float rotateValue = 2;
		FRotator newRotation = FRotator(0, rotation += rotateValue, 0);
		RootScene->SetRelativeRotation(newRotation);
	}
}

void ACameraPawn::CameraRotationRight(float axisValue)
{
	if (axisValue > 0)
	{
		float rotateValue = 2;
		FRotator newRotation = FRotator(0, rotation -= rotateValue, 0);
		RootScene->SetRelativeRotation(newRotation);
	}
}



