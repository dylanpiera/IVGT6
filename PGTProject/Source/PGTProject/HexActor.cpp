// Fill out your copyright notice in the Description page of Project Settings.

#define _USE_MATH_DEFINES

#include "HexActor.h"
#include <cassert>
#include <vector>
#include <math.h>  // NOLINT(modernize-deprecated-headers)

// Sets default values
AHexActor::AHexActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

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
		/**
		 * \brief
		 * Hex coordinates as array 
		 */
		const Number v[3];

		struct {
			/**
			 * \brief Column
			 */
			const Number q;
			/**
			 * \brief Row
			 */
			const Number r;
			const Number s;
		};
	};

	_Hex(Number q, Number r) : v{ q, r, -q - r } {}
	_Hex(Number q, Number r, Number s) : v{ q, r, s } {}
};
/**
 * \brief 
 * A Hex with Grid Coordinates
 */
typedef _Hex<int, 1> Hex;
typedef _Hex<int, 0> HexDifference;
typedef _Hex<double, 1> FractionalHex;
typedef _Hex<double, 0> FractionalHexDifference;

// All mathematical overriders for the Hex Struct. 
#pragma region Operators

/**
 * \brief 
 * Checks if a hex is equal to another hex based on its coordinates on the hex grid.
 */
bool operator == (const Hex a, const Hex b) {
	return a.q == b.q && a.r == b.r && a.s == b.s;
}

/**
 * \brief
 * Checks if a hex is not equal to another hex based on its coordinates on the hex grid.
 */
bool operator != (const Hex a, const Hex b) {
	return !(a == b);
}

/**
 * \brief
 * Adds the coordinates of one hex with another hex.
 */
Hex operator + (const Hex a, const Hex b) {
	return { a.q + b.q, a.r + b.r, a.s + b.s };
}

/**
 * \brief
 * Removes the coordinates of one hex with another hex
 */
Hex operator - (const Hex a, const Hex b) {
	return { a.q - b.q, a.r - b.r, a.s - b.s };
}

/**
 * \brief
 * Multiplies the coordinates of a hex by a given value
 */
Hex operator * (const Hex a, const int k) {
	return { a.q * k, a.r * k, a.s * k };
}
#pragma endregion Operators

#pragma region Location Calculations

/**
 * \brief 
 * Returns the length of a hex based on its grid coordinates.
 * \param 
 * The hex object
 * \return 
 */
int hex_length(const Hex hex) {
	return int((abs(hex.q) + abs(hex.r) + abs(hex.s)) / 2);
}

/**
 * \brief 
 * Calculates the distance between two hexes in grid space.
 * \param a Hex 1
 * \param b Hex 2
 * \return 
 */
int hex_distance(const Hex a, const Hex b) {
	return hex_length(a - b);
}


/**
 * \brief 
 * The 6 cardinal directions of a Hex Grid
 */
const std::vector<Hex> kHexDirections = {
	Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
	Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
};

//TODO: Merge these two methods together
Hex hex_direction(const int direction /* 0 to 5 */) {
	assert(0 <= direction && direction < 6);
	return kHexDirections[direction];
}

Hex hex_neighbor(const Hex hex, const int direction) {
	return hex + hex_direction(direction);
}
#pragma endregion Location Calculations

#pragma region Drawing

FIntPoint hex_to_pixel(const LayoutHelper::Layout layout, const Hex h)
{
	const LayoutHelper::Orientation& m = layout._orientation;
	const double x = (m._f0 * h.q + m._f1 * h.r) * layout._size.X;
	const double y = (m._f2 * h.q + m._f3 * h.r) * layout._size.Y;
	return FIntPoint(x + layout._origin.X, y + layout._origin.Y);
}

FractionalHex pixel_to_hex(const LayoutHelper::Layout layout, const FIntPoint p)
{
	const LayoutHelper::Orientation& m = layout._orientation;
	const FIntPoint pt = FIntPoint((p.X - layout._origin.X) / layout._size.X,
		(p.Y - layout._origin.Y) / layout._size.Y);
	const double q = m._b0 * pt.X + m._b1 * pt.Y;
	const double r = m._b2 * pt.X + m._b3 * pt.Y;
	return { q, r, -q - r };
}

FIntPoint hex_corner_offset(const LayoutHelper::Layout layout, const int corner) {
	const FIntPoint size = layout._size;
	const double angle = 2.0 * M_PI *
		(layout._orientation._startAngle + corner) / 6;
	return FIntPoint(size.X * cos(angle), size.Y * sin(angle));
}

std::vector<FIntPoint> polygon_corners(const LayoutHelper::Layout layout, const Hex h) {
	std::vector<FIntPoint> corners = {};
	const FIntPoint center = hex_to_pixel(layout, h);
	for (int i = 0; i < 6; i++) {
		const FIntPoint offset = hex_corner_offset(layout, i);
		corners.emplace_back(center.X + offset.X,
			center.Y + offset.Y);
	}
	return corners;
}

#pragma endregion Drawing


// Called when the game starts or when spawned
void AHexActor::BeginPlay()
{
	Super::BeginPlay();

	auto hex = Hex(0, 0);
}

// Called every frame
void AHexActor::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}
