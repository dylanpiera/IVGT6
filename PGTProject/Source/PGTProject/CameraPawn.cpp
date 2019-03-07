// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraPawn.h"

// Sets default values
ACameraPawn::ACameraPawn()
{
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
	AddActorWorldOffset(GetCameraPanDirection() * camSpeed);
}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//MouseWheel input
	InputComponent->BindAxis("MouseWheelAxis", this, &ACameraPawn::CameraZoom);
}

FVector ACameraPawn::GetCameraPanDirection()
{
	float mousePosX;
	float mousePosY;
	float camDirectionX = 0;
	float camDirectionY = 0;

	PC->GetMousePosition(mousePosX, mousePosY);

	// Pan left
	if (mousePosX <= margin)
	{
		camDirectionY = -1;
	}

	// Pan up
	if (mousePosY <= margin)
	{
		camDirectionX = 1;
	}

	// Pan right
	if (mousePosX >= screenSizeX - margin)
	{
		camDirectionY = 1;
	}

	// Pan down
	if (mousePosY >= screenSizeY - margin)
	{
		camDirectionX = -1;
	}

	return FVector(camDirectionX, camDirectionY, 0);
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


