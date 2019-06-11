#pragma once

#include "CoreMinimal.h"
#include "EconomyManager.h"
#include "GameFramework/Actor.h"
#include "GameTickManager.generated.h"

UCLASS()
/**
 * @brief 
 * 
 */
class PGTPROJECT_API AGameTickManager : public AActor
{
	GENERATED_BODY()
	
public:	
	/**
	 * @brief Construct a new AGameTickManager object
	 * 
	 */
	AGameTickManager();

protected:
	/**
	 * @brief 
	 * 
	 */
	virtual void BeginPlay() override;

public:	
	/**
	 * @brief 
	 * 
	 * @param DeltaTime 
	 */
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	bool Debug = false;

	UPROPERTY()
	UINT32 currentHour;
	UINT32 currentDay;
	UINT32 dayOfWeek;
	UINT32 currentMonth;
	UINT32 currentYear;
	UINT32 currentYearFirst;
	UINT32 currentYearSecond;

	UINT32 timeMultiplier;
	float timer;

	TArray<FString> days;
	TArray<FString> months;
	FString dayName;
	FString monthName;

	FTimerHandle GameTickTimerHandle;
	bool bCanTick;

	AEconomyManager* EconomyManager;

	UFUNCTION()
	/**
	 * @brief 
	 * 
	 */
	void GameTick();

	/**
	 * @brief 
	 * 
	 */
	void GameTickHour();

	/**
	 * @brief 
	 * 
	 */
	void GameTickDay();

	/**
	 * @brief 
	 * 
	 */
	void GameTickMonth();

	/**
	 * @brief 
	 * 
	 */
	void GameTickYear();

	/**
	 * @brief 
	 * 
	 */
	void ResetTimer();

	/**
	 * @brief Set the Speed Time One object
	 * 
	 */
	void SetSpeedTimeOne();

	/**
	 * @brief Set the Speed Time Two object
	 * 
	 */
	void SetSpeedTimeTwo();

	/**
	 * @brief Set the Speed Time Four object
	 * 
	 */
	void SetSpeedTimeFour();
};
