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

	//OnClickRayCast();
	
}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//LeftCLick
	InputComponent->BindAction("LeftClick", IE_Pressed, this, &ACameraPawn::OnClickRayCast);

	//MouseWheel input
	InputComponent->BindAxis("MouseWheelAxis", this, &ACameraPawn::CameraZoom);
	
	//Rotation Input
	InputComponent->BindAxis("RotateRight", this, &ACameraPawn::CameraRotationRight);
	InputComponent->BindAxis("RotateLeft", this, &ACameraPawn::CameraRotationLeft);
}

void ACameraPawn::GetCameraPanDirection()
{
	margin = 5;
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

void ACameraPawn::OnClickRayCast() 
{	
	//Declared empty Vectors. These will be filled up with converted screenspace values
	FVector mousePos, mouseDir;

	//Converts the screenspace to world space as it was on the screen. 
	//Also gets direction.
	PC->DeprojectMousePositionToWorld(mousePos, mouseDir);

	//Define start and end(direction) location
	FVector startLocation = mousePos;
	FVector endLocation = startLocation + (mouseDir * 1000.f);

	//contains the actor that was hit
	FHitResult hit;

	//paramaters you can add to the specific trace you want to use
	FCollisionQueryParams CollParams;
	CollParams.AddIgnoredActor(this);

	//Throw out linetrace (second line is the debug line)
	GetWorld()->LineTraceSingleByChannel(hit, startLocation, endLocation, ECC_Visibility, CollParams);
	UKismetSystemLibrary::DrawDebugLine(GetWorld(), startLocation, endLocation, FColor::Red, 5.f, .3f);

	//Get's actor for selecting purposes
	SelectedActor = SelectingActor(hit);

	if(SelectedActor != NULL)
	{
		//TODO: Change destroy to something else. This was for testing purpose.
		SelectedActor->Destroy();
	}
}

AActor* ACameraPawn::SelectingActor(FHitResult h)
{
	AActor* Actor;

	if (h.Actor != NULL)
	{
		Actor = h.GetActor();
		return Actor;
	}
	else return NULL;
}





