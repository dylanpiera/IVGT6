// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC_Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "OutputDeviceNull.h"

// Sets default values
ANPC_Character::ANPC_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LoadMesh();

	//this->SpawnDefaultController();
}

// Called when the game starts or when spawned
void ANPC_Character::BeginPlay()
{
	Super::BeginPlay();
	//FOutputDeviceNull ar;
	//this->CallFunctionByNameWithArguments(TEXT("Move"), ar, NULL, true);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MOVE BABY!"));

	TEST();
	FVector tile = FVector(4000, 4000, 0);
	MoveToLocation(tile);
}

void ANPC_Character::TEST_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Default..."));
    // Logic needed when blueprints don't implement the event. Can be empty.
}

// Called every frame
void ANPC_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ANPC_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANPC_Character::LoadMesh()
{
	// Find and load skeletal mesh
	MeshContainer = LoadObject<USkeletalMesh>(nullptr, TEXT("SkeletalMesh'/Game/Assets/NPC/Cyborg.Cyborg'"));
	// If mesh was found apply it to this character
	if (MeshContainer) {
		CharacterMesh = GetMesh();
		CharacterMesh->AddRelativeLocation(FVector(0, 2, -60));
		CharacterMesh->SetSkeletalMesh(MeshContainer);
		FVector MeshScale = FVector(10, 10, 10);
		CharacterMesh->SetWorldScale3D(MeshScale);

		CharacterCapsule = GetCapsuleComponent();
		CharacterCapsule->SetCapsuleHalfHeight(60.0f, false);
		CharacterCapsule->SetCapsuleRadius(22.0f, false);
	}
}

void ANPC_Character::MoveTo(FVector place)
{
	
	//this->CallFunctionByNameWithArguments(TEXT("Move"), ar, NULL, true);
	//ACharacterController* moveController = Cast<ACharacterController>(this->GetController());
}