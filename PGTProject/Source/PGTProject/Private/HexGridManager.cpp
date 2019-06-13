// Fill out your copyright notice in the Description page of Project Settings.

#include "HexGridManager.h"
#include "HexActor.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include <Runtime/Json/Public/Json.h>


// Sets default values
AHexGridManager::AHexGridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHexGridManager::BeginPlay()
{
	Super::BeginPlay();

	//Testing
	GenerateGrid();
	LogGrid();


	GenerateWithLudo();
	FString data = ReadFile("out.txt");

    std::vector<std::string> result;

	std::stringstream ss(std::string(TCHAR_TO_UTF8(*data)));

    while(ss.good())
    {
        std::string substr;
        std::getline( ss, substr, ',' );
        result.push_back( substr );
    }

	for(std::string o : result) {
		FString temp(o.c_str());
		UE_LOG(LogTemp, Warning, TEXT("Loaded from Ludo: %s"), *temp);
	}
}

// Called every frame
void AHexGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHexGridManager::GenerateGrid()
{
	for (int column = 0; column < mapsize; column++)
	{
		for(int row = 0; row < mapsize; row++)
		{
			auto* hex = new AHexActor::Hex(column, row);
			hexes[column][row] = hex;
			
			FRotator Rotation(0.0f, 0.0f, 0.0f);
			FActorSpawnParameters SpawnInfo;
			AHexActor* a = GetWorld()->SpawnActor<AHexActor>(AHexActor::GetScreenSpaceLocation(hex), Rotation, SpawnInfo);
			a->hex = hex; // this is for getting grid position
		}
	}
}

void AHexGridManager::GenerateWithLudo()
{
    FString tool = FPaths::Combine(FPaths::ProjectDir(), "Ludo\\LudoTool.exe");
    FPlatformProcess::CreateProc(*tool, nullptr, true, false, false, nullptr, 0, nullptr, nullptr);
}


FString AHexGridManager::ReadFile(FString filename)
{
    //Read file ini [project]/Content/Data/
    //you can change with other location
    FString directory = FPaths::Combine(FPaths::ProjectContentDir(), "Data");
    FString result;
    IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();
    if (file.CreateDirectory(*directory)) {
        FString myFile = directory + "/" + filename;
        FFileHelper::LoadFileToString(result, *myFile);
    }
    return result;
}

void AHexGridManager::LogGrid() const
{
	for (int column = 0; column < mapsize; column++)
	{
		for (int row = 0; row < mapsize; row++)
		{
			UE_LOG(LogTemp, Warning, TEXT("q: %d - r: %d - s: %d"), hexes[column][row]->q, hexes[column][row]->r, hexes[column][row]->s);
		}
	}
}