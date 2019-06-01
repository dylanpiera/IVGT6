// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterController.h"
#include "NavigationSystem.h"

ACharacterController::ACharacterController()
{
	
}

void ACharacterController::SetNewMoveDestination(const FVector DestLocation)
{
	//APawn* const Pawn = GetPawn();
	//if (Pawn)
	//{
	//	UNavigationSystem* const NavSys = Cast<UNavigationSystem>(GetWorld()->GetNavigationSystem());
	//	float const Distance = FVector::Dist(DestLocation, Pawn->GetActorLocation());

	//	// We need to issue move command only if far enough in order for walk animation to play correctly
	//	if (NavSys && (Distance > 120.0f))
	//	{
	//		NavSys->SimpleMoveToLocation(this, DestLocation);
	//	}
	//}
}
