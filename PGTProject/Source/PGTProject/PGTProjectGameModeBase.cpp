// Fill out your copyright notice in the Description page of Project Settings.

#include "PGTProjectGameModeBase.h"

#include  "GameHUD.h"

APGTProjectGameModeBase::APGTProjectGameModeBase() : Super()
{
	HUDClass = AGameHUD::StaticClass();
}
