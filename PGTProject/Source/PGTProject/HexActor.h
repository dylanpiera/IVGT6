#pragma once

#include "LayoutHelper.h"
#include "IntPoint.h"
#include <vector>
#include "MineralBuilding.h"
#include "GameFramework/Actor.h"
#include "HexActor.generated.h"

UCLASS()
/**
 * @brief A Hex (tile) Actor
 * 
 * A single HexTile in actor format, contains a reference to its own managed logic from the HexGridManager.
 */
class PGTPROJECT_API AHexActor : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * @brief Construct a new AHexActor object, sets default values for this actor's properties
	 * 
	 */
	AHexActor();

protected:
	/**
	 * @brief Called when the game starts or when spawned
	 * 
	 */
	virtual void BeginPlay() override;

public:
	/**
	 * @brief Called every frame
	 * 
	 * @param deltaTime 
	 */
	virtual void Tick(float deltaTime) override;

	/**
	 * @brief The data structure for a given Hex represented in Hex Coordinates.
	 * 
	 * @tparam Number The type of data storage, either int or double
	 * @tparam W A seperation for whether the hex is a real Hex or just a hex used for calculations.
	 */
	template <typename Number, int W>
	struct _Hex {
		union {
			/**
			 * @brief The 3 coordinates in array format. 
			 * 
			 * Specifically useful for when looping through the code.
			 */
			const Number v[3];
			
			/**
			 * @brief The 3 coodinates in struct format.
			 * 
			 * QRS are the XYZ equivalent for our implementation of the Axial-Coordinate system.
			 * This specific struct makes it clearer what you're calling from code, when you don't necessarily
			 * need to loop through all numbers.
			 */
			struct { const Number q, r, s; };
		};
		/**
		 * @brief Construct a new hex object
		 * 
		 * @param q Column (x)
		 * @param r Row (y)
		 */
		_Hex(Number q, Number r) : v{ q, r, -q - r } {}
		/**
		 * @brief Construct a new hex object
		 * 
		 * @param q Column (x)
		 * @param r Row (y)
		 * @param s (z)
		 */
		_Hex(Number q, Number r, Number s) : v{ q, r, s } {}

	#pragma region Operators
		/**
		 * @brief Checks if a hex is equal to another hex based on its coordinates on the hex grid.
		 * 
		 * @param other 
		 * @return true 
		 * @return false 
		 */
		bool operator == (const _Hex<Number, W> other) const { return other.q == q && other.r == r && other.s == s; }

		/**
		 * @brief Checks if a hex is not equal to another hex based on its coordinates on the hex grid.
		 * 
		 * @param other 
		 * @return true 
		 * @return false 
		 */
		bool operator != (const _Hex<Number, W> other) const {
			return !(other == this);
		}

		/**
		 * @brief Adds the coordinates of one hex with another hex.
		 * 
		 * @param other 
		 * @return _Hex<Number, W> 
		 */
		_Hex<Number, W> operator + (const _Hex<Number, W> other) const {
			return { other.q + q, other.r + r, s + s };
		}

		/**
		 * @brief Removes the coordinates of one hex with another hex
		 * 
		 * @param other 
		 * @return _Hex<Number, W> 
		 */
		_Hex<Number, W> operator - (const _Hex<Number, W> other) const {
			return { other.q - q, other.r - r, other.s - s };
		}

		/**
		 * @brief Multiplies the coordinates of a hex by a given value
		 * 
		 * @param k 
		 * @return _Hex<Number, W> 
		 */
		_Hex<Number, W> operator * (const int k) const {
			return { q * k, r * k, s * k };
		}
#pragma endregion Operators
	};

	/**
	 * @brief A Hex with Grid Coordinates
	 * 
	 */
	typedef _Hex<int, 1> Hex;
	typedef _Hex<int, 0> HexDifference;
	typedef _Hex<double, 1> FractionalHex;
	typedef _Hex<double, 0> FractionalHexDifference;

	/**
	 * @brief Returns the length of a hex based on its grid coordinates.
	 * @param The hex object 
	 * @return int The length of the hex
	 */
	int hex_length(Hex hex) const;
	/**
	 * @brief Calculates the distance between two hexes in grid space.
	 * 
	 * @param a Hex 1
	 * @param b Hex 2
	 * @return int The distance between two hexes
	 */
	int hex_distance(Hex a, Hex b) const;

	/**
	 * @brief The 6 cardinal directions of a Hex Grid
	 */
	const std::vector<Hex> kHexDirections =
	{
		Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
		Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
	};
	/**
	 * @brief Gets a hex with kHexDirections based coordinates, to be used for calculations.
	 * 
	 * @param direction int 0-5, taking the correct direction from kHexDirections 
	 * @return Hex 
	 */
	Hex hex_direction(const int direction) const;
	/**
	 * @brief Tries to get an adjacent hex in a certain direction from the current hex.
	 * 
	 * @param hex Current Hex
	 * @param direction Direction to Look in
	 * @return Hex Found neighbor, if any.
	 */
	Hex hex_neighbor(const Hex hex, const int direction) const;

	/**
	 * @brief 
	 * 
	 * @param layout 
	 * @param h 
	 * @return FIntPoint 
	 */
	static FIntPoint hex_to_pixel(const LayoutHelper::Layout layout, const Hex h);
	/**
	 * @brief 
	 * 
	 * @param layout 
	 * @param p 
	 * @return FractionalHex 
	 */
	static FractionalHex pixel_to_hex(const LayoutHelper::Layout layout, const FIntPoint p);
	/**
	 * @brief 
	 * 
	 * @param layout 
	 * @param corner 
	 * @return FIntPoint 
	 */
	FIntPoint hex_corner_offset(const LayoutHelper::Layout layout, const int corner) const;
	/**
	 * @brief 
	 * 
	 * @param layout 
	 * @param h 
	 * @return std::vector<FIntPoint> 
	 */
	std::vector<FIntPoint> polygon_corners(const LayoutHelper::Layout layout, const Hex h) const;

	/**
	 * @brief Get the Screen Space Location object
	 * 
	 * @param hex 
	 * @return FVector 
	 */
	static FVector GetScreenSpaceLocation(Hex *hex);
	Hex* hex;

	UBuilding* Building;
	bool buildingBuilt = false;
};