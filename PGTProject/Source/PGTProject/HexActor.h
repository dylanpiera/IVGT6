#pragma once

#include "LayoutHelper.h"
#include "IntPoint.h"
#include <vector>
#include "MineralBuilding.h"
#include "GameFramework/Actor.h"
#include "HexActor.generated.h"

UCLASS()
/**
 * @brief 
 * 
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
	 * @tparam Number 
	 * @tparam W 
	 */
	template <typename Number, int W>
	/**
	 * @brief ReSharper disable once CppInconsistentNaming
	 * 
	 */
	struct _Hex {
		union {
			const Number v[3];
			struct { const Number q, r, s; };
		};
		/**
		 * @brief Construct a new hex object
		 * 
		 * @param q 
		 * @param r 
		 */
		_Hex(Number q, Number r) : v{ q, r, -q - r } {}
		/**
		 * @brief Construct a new hex object
		 * 
		 * @param q 
		 * @param r 
		 * @param s 
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
	 * @brief 
	 * 
	 * @param hex 
	 * @return int 
	 */
	int hex_length(Hex hex) const;
	/**
	 * @brief 
	 * 
	 * @param a 
	 * @param b 
	 * @return int 
	 */
	int hex_distance(Hex a, Hex b) const;

	const std::vector<Hex> kHexDirections =
	{
		Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
		Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
	};
	/**
	 * @brief 
	 * 
	 * @param direction 
	 * @return Hex 
	 */
	Hex hex_direction(const int direction) const;
	/**
	 * @brief 
	 * 
	 * @param hex 
	 * @param direction 
	 * @return Hex 
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