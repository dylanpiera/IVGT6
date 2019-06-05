// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraPawn.h"
#include "BuildingGraphics.h"

// Sets default values
ACameraPawn::ACameraPawn()
{
	margin = 15;
	camSpeed = 15;
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

	SpringArm->TargetArmLength = CameraArmHeight;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArm);
	WRLD = GetWorld();
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

	GetCameraPanDirection();
	PC->GetViewportSize(screenSizeX, screenSizeY);
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
		CameraArmHeight -= 25;

	//ZoomOut
	if (axisValue < 0)
		CameraArmHeight += 25;

	SpringArm->TargetArmLength = CameraArmHeight;
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
	FVector endLocation = startLocation + (mouseDir * 15000.f);

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

	if(SelectedActor != NULL )
	{
		//TODO: Change destroy to something else. This was for testing purpose.
		//SelectedActor->Destroy();

		if (SelectedActor->IsA(AHexActor::StaticClass()))
		{
			//FVector hexPos = SelectedActor->GetActorLocation();
			AHexActor* hex = Cast<AHexActor>(SelectedActor);
			FVector vec = FVector(hex->hex->q, hex->hex->r, hex->hex->s);
			
			// BuildBuilding (activate or add something to the hex)

			
			FVector location = hex->GetActorLocation();
			FRotator rotation = hex->GetActorRotation();

			//TSubclassOf<ABuildingGraphics> Building;
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.Owner = hex;

			TArray<AActor*> FActors;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(),
			ADataHolder::StaticClass(),
			FActors);
			ADataHolder* holder = Cast<ADataHolder>(FActors[0]);
			OptionSections buildingMesh = holder->GetBuilding();

			//ABuildingGraphics* Building = GetWorld()->SpawnActor<ABuildingGraphics>(ABuildingGraphics::StaticClass(), location, rotation, SpawnInfo);
				
			// Create building
			UMineralBuilding* building = NewObject<UMineralBuilding>(UMineralBuilding::StaticClass());
			// Start building construction (its gonna spawn the mesh automatically)
			building->SetMesh(buildingMesh);
			building->BuildingConstruction(location, rotation, SpawnInfo);

			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("Position: "  + vec.ToString()));
		}
		else SelectedActor->Destroy();
	}
}

AActor* ACameraPawn::SelectingActor(FHitResult h)
{
	return h.Actor != NULL ? h.GetActor() : NULL;
}





