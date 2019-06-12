#include "CameraPawn.h"
#include "Constants.h"
#include "building.h"
#include "EconomyManager.h"
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
	InputComponent->BindAction("LeftClick", IE_Pressed, this, &ACameraPawn::PlaceBuilding);

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
		AddActorWorldOffset(RootScene->GetRightVector() * camSpeed * -1);
	}

	// Pan up
	if (mousePosY <= margin)
	{
		AddActorWorldOffset(RootScene->GetForwardVector() * camSpeed);
	}

	// Pan right
	if (mousePosX >= screenSizeX - margin)
	{
		AddActorWorldOffset(RootScene->GetRightVector() * camSpeed);
	}

	// Pan down
	if (mousePosY >= screenSizeY - margin)
	{
		AddActorWorldOffset(RootScene->GetForwardVector() * camSpeed * -1);
	}
}

void ACameraPawn::CameraZoom(float axisValue)
{
	//ZoomIn
	if (axisValue > 0)
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

//BADSMELL: The function OnClickRayCast is far too big.
//			The function starts at line 137 and ends at 299
FHitResult ACameraPawn::RayCast()
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
	//UKismetSystemLibrary::DrawDebugLine(GetWorld(), startLocation, endLocation, FColor::Red, 5.f, .3f);

	return hit;
}

AActor* ACameraPawn::SelectingActor(FHitResult h)
{
	return h.Actor != NULL ? h.GetActor() : NULL;
}

void ACameraPawn::PlaceBuilding()
{
	FHitResult h = RayCast();
	//Get's actor for selecting purposes
	SelectedActor = SelectingActor(h);

	if (SelectedActor != NULL)
	{

		//BADSMELL: The Get all actor's function is used several times.
		//		    Might want to make this a singleton that is globaly
		//			accessable.
		//Ecoman
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(),
			AEconomyManager::StaticClass(),
			FoundActors);
		AEconomyManager* EconomyManager = Cast<AEconomyManager>(FoundActors[0]);


		if (SelectedActor->IsA(AHexActor::StaticClass()))
		{

			// Cast selected vector to HexActor
			AHexActor* hex = Cast<AHexActor>(SelectedActor);

			if (!hex->buildingBuilt) // checks if already building build.
			{
				FVector vec = FVector(hex->hex->q, hex->hex->r, hex->hex->s);

				FVector location = hex->GetActorLocation();
				FRotator rotation = hex->GetActorRotation();

				

				// Find DataHolder
				TArray<AActor*> FActors;
				UGameplayStatics::GetAllActorsOfClass(GetWorld(),
					ADataHolder::StaticClass(),
					FActors);
				ADataHolder* holder = Cast<ADataHolder>(FActors[0]);
				OptionSections buildingMesh = holder->GetBuilding();


				UBuilding* building;
				// Create building
				switch (buildingMesh)
				{
					case MineralsBuilding:
					{
						building = NewObject<UMineralBuilding>(UMineralBuilding::StaticClass());
						building = SelectedBuilding(building, buildingMesh, EconomyManager, hex, -20);
						building->totalOfBuildingType = &EconomyManager->MineralBuildings; // specific
						break;
					}
				case EnergyBuilding:
				{
					building = NewObject<UEnergyBuilding>(UEnergyBuilding::StaticClass());
					building = SelectedBuilding(building, buildingMesh, EconomyManager, hex, 50);
					building->totalOfBuildingType /*what is this!?*/ = &EconomyManager->EnergyBuildings; // specific
					break;
				}
				case MoneyBuilding:
				{
					building = NewObject<UHouseBuilding>(UHouseBuilding::StaticClass());
					building = SelectedBuilding(building, buildingMesh, EconomyManager, hex, 50);
					building->totalOfBuildingType = &EconomyManager->Houses;
					break;
				}
				}
			}
		}
		else
		{
			//Finds Dataholder.
			TArray<AActor*> FActors;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(),
				ADataHolder::StaticClass(),
				FActors);
			ADataHolder* holder = Cast<ADataHolder>(FActors[0]);
			OptionSections buildingMesh = holder->GetBuilding();

			if (buildingMesh == DestroyTool) {
				auto parent = SelectedActor->GetOwner();
				if (parent->IsA(AHexActor::StaticClass()))
				{
					//FVector hexPos = SelectedActor->GetActorLocation();
					AHexActor* hex = Cast<AHexActor>(parent);
					*hex->Building->x -= 1;
					hex->buildingBuilt = false;
					EconomyManager->ActiveBuildings.Remove(hex->Building);

					SelectedActor->Destroy();
				}
				else
				{
					GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("No hex found."));
				}
			}
		}
	}

	

}

UBuilding* ACameraPawn::SelectedBuilding(UBuilding* building, OptionSections mesh, AEconomyManager* ecoMan, AHexActor* hex, int engCost)
{
	building->SetBuildingCost();
	if (building->GetCost() > ecoMan->resources._minerals) {
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("You lack the required resource to build this building."));
	}
	else {
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.Owner = hex;

		ecoMan->resources._minerals -= building->GetCost();
		hex->Building = building;
		building->SetMesh(mesh);
		building->BuildingConstruction(hex->GetActorLocation(), hex->GetActorRotation(), SpawnInfo);
		ecoMan->ActiveBuildings.Add(building);
		hex->buildingBuilt = true;
		ecoMan->resources._energy += engCost;
	}
	return building;
}








