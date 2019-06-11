#pragma once

#include "CoreMinimal.h"
#include "EconomyManager.h"
#include "GameFramework/Actor.h"
#include "GameTickManager.generated.h"

UCLASS()
/**
 * @brief Class that processes the game itself based on ingame hourly itteration
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
	 * @brief Processes GameTickHour()
	 * 
	 */
	void GameTickHour();

	/**
	 * @brief Ingame daily itteration
	 * 
	 */
	void GameTickDay();

	/**
	 * @brief Ingame monthly itteration
	 * 
	 */
	void GameTickMonth();

	/**
	 * @brief ingame yearly itteration
	 * 
	 */
	void GameTickYear();

	/**
	 * @brief Resets the hourly timer
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
