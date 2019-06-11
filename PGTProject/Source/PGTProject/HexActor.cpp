#define _USE_MATH_DEFINES

#include "HexActor.h"
#include <cassert>
#include <vector>
#include <math.h>  // NOLINT(modernize-deprecated-headers)
#include "HexActorGraphics.h"

// Graphics controller
HexActorGraphics Graphic;

// Sets default values
AHexActor::AHexActor()
{
	hex = new Hex(1, 1);
	// Create hexagon tile graphics
	Graphic.CreateHexGraphics(this);

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

#pragma region Location Calculations

/**
 * \brief 
 * Returns the length of a hex based on its grid coordinates.
 * \param 
 * The hex object
 * \return 
 */
int AHexActor::hex_length(const Hex hex) const
{
	return int((abs(hex.q) + abs(hex.r) + abs(hex.s)) / 2);
}

/**
 * \brief 
 * Calculates the distance between two hexes in grid space.
 * \param a Hex 1
 * \param b Hex 2
 * \return 
 */
int AHexActor::hex_distance(const Hex a, const Hex b) const
{
	return hex_length(a - b);
}


/**
 * \brief 
 * The 6 cardinal directions of a Hex Grid
 */

//TODO: Merge these two methods together
AHexActor::Hex AHexActor::hex_direction(const int direction /* 0 to 5 */) const
{
	assert(0 <= direction && direction < 6);
	return kHexDirections[direction];
}

AHexActor::Hex AHexActor::hex_neighbor(const Hex hex, const int direction) const
{
	return hex + hex_direction(direction);
}
#pragma endregion Location Calculations

#pragma region Drawing

FIntPoint AHexActor::hex_to_pixel(const LayoutHelper::Layout layout, const Hex h)
{
	const LayoutHelper::Orientation& m = layout._orientation;
	const double x = (m._f0 * h.q + m._f1 * h.r) * layout._size.X;
	const double y = (m._f2 * h.q + m._f3 * h.r) * layout._size.Y;
	return FIntPoint(x + layout._origin.X, y + layout._origin.Y);
}

AHexActor::FractionalHex AHexActor::pixel_to_hex(const LayoutHelper::Layout layout, const FIntPoint p)
{
	const LayoutHelper::Orientation& m = layout._orientation;
	const FIntPoint pt = FIntPoint((p.X - layout._origin.X) / layout._size.X,
		(p.Y - layout._origin.Y) / layout._size.Y);
	const double q = m._b0 * pt.X + m._b1 * pt.Y;
	const double r = m._b2 * pt.X + m._b3 * pt.Y;
	return { q, r, -q - r };
}

FIntPoint AHexActor::hex_corner_offset(const LayoutHelper::Layout layout, const int corner) const {
	const FIntPoint size = layout._size;
	const double angle = 2.0 * M_PI *
		(layout._orientation._startAngle + corner) / 6;
	return FIntPoint(size.X * cos(angle), size.Y * sin(angle));
}

std::vector<FIntPoint> AHexActor::polygon_corners(const LayoutHelper::Layout layout, const Hex h) const
{
	std::vector<FIntPoint> corners = {};
	const FIntPoint center = hex_to_pixel(layout, h);
	for (int i = 0; i < 6; i++) {
		const FIntPoint offset = hex_corner_offset(layout, i);
		corners.emplace_back(center.X + offset.X,
			center.Y + offset.Y);
	}
	return corners;
}

FVector AHexActor::GetScreenSpaceLocation(Hex *hex)
{
	// Calculate space position for hex based on mesh size
	float k = (Graphic.MeshSize.X - Graphic.MeshSize.Y / FMath::Sqrt(12));

	// Gap between tiles for better visualization
	float gapX = hex->q * 3;
	float gapY = hex->r * 3;

	return FVector(
		hex->q * k + gapX,
		hex->r * Graphic.MeshSize.Y + hex->q * (Graphic.MeshSize.Y / 2.f) + gapY,
		0
	);
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
