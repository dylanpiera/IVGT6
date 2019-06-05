// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LayoutHelper.h"
#include "IntPoint.h"
#include <vector>
#include "MineralBuilding.h"
#include "GameFramework/Actor.h"
#include "HexActor.generated.h"

UCLASS()
class PGTPROJECT_API AHexActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHexActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float deltaTime) override;

	/**
	 * \brief
	 * The data structure for a given Hex represented in Hex Coordinates.
	 * \tparam Number
	 * Data storage type
	 */
	template <typename Number, int W>
	// ReSharper disable once CppInconsistentNaming
	struct _Hex {
		union {
			const Number v[3];
			struct { const Number q, r, s; };
		};

		_Hex(Number q, Number r) : v{ q, r, -q - r } {}
		_Hex(Number q, Number r, Number s) : v{ q, r, s } {}

	#pragma region Operators
		/**
		 * \brief
		 * Checks if a hex is equal to another hex based on its coordinates on the hex grid.
		 */
		bool operator == (const _Hex<Number, W> other) const { return other.q == q && other.r == r && other.s == s; }

		/**
		 * \brief
		 * Checks if a hex is not equal to another hex based on its coordinates on the hex grid.
		 */
		bool operator != (const _Hex<Number, W> other) const {
			return !(other == this);
		}

		/**
		 * \brief
		 * Adds the coordinates of one hex with another hex.
		 */
		_Hex<Number, W> operator + (const _Hex<Number, W> other) const {
			return { other.q + q, other.r + r, s + s };
		}

		/**
		 * \brief
		 * Removes the coordinates of one hex with another hex
		 */
		_Hex<Number, W> operator - (const _Hex<Number, W> other) const {
			return { other.q - q, other.r - r, other.s - s };
		}

		/**
		 * \brief
		 * Multiplies the coordinates of a hex by a given value
		 */
		_Hex<Number, W> operator * (const int k) const {
			return { q * k, r * k, s * k };
		}
#pragma endregion Operators
	};

	/**
	 * \brief
	 * A Hex with Grid Coordinates
	 */
	typedef _Hex<int, 1> Hex;
	typedef _Hex<int, 0> HexDifference;
	typedef _Hex<double, 1> FractionalHex;
	typedef _Hex<double, 0> FractionalHexDifference;

	int hex_length(Hex hex) const;
	int hex_distance(Hex a, Hex b) const;

	const std::vector<Hex> kHexDirections =
	{
		Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
		Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
	};
	Hex hex_direction(const int direction) const;
	Hex hex_neighbor(const Hex hex, const int direction) const;

	static FIntPoint hex_to_pixel(const LayoutHelper::Layout layout, const Hex h);
	static FractionalHex pixel_to_hex(const LayoutHelper::Layout layout, const FIntPoint p);
	FIntPoint hex_corner_offset(const LayoutHelper::Layout layout, const int corner) const;
	std::vector<FIntPoint> polygon_corners(const LayoutHelper::Layout layout, const Hex h) const;

	static FVector GetScreenSpaceLocation(Hex *hex);
	Hex* hex;

	UMineralBuilding* Building;
	bool buildingBuilt = false;
};