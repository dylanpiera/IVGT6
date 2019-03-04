// Fill out your copyright notice in the Description page of Project Settings.

#include "HexActor.h"
#include <cassert>
#include <vector>

// Sets default values
AHexActor::AHexActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

template <typename Number>
struct _Hex {
	union {
		const Number v[3];
		struct { const Number q, r, s; };
	};

	_Hex(Number q, Number r) : v{ q, r, -q - r } {}
	_Hex(Number q, Number r, Number s) : v{ q, r, s } {}
};
typedef _Hex<int> Hex;

#pragma region Operators
bool operator == (const Hex a, const Hex b) {
	return a.q == b.q && a.r == b.r && a.s == b.s;
}

bool operator != (const Hex a, const Hex b) {
	return !(a == b);
}

Hex operator + (const Hex a, const Hex b) {
	return {a.q + b.q, a.r + b.r, a.s + b.s};
}

Hex operator - (const Hex a, const Hex b) {
	return {a.q - b.q, a.r - b.r, a.s - b.s};
}

Hex operator * (const Hex a, const int k) {
	return {a.q * k, a.r * k, a.s * k};
}
#pragma endregion Operators
#pragma region Location Calculations
int hex_length(const Hex hex) {
	return int((abs(hex.q) + abs(hex.r) + abs(hex.s)) / 2);
}

int hex_distance(const Hex a, const Hex b) {
	return hex_length(a-b);
}

const std::vector<Hex> hex_directions = {
	Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
	Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
};

Hex hex_direction(int direction /* 0 to 5 */) {
	assert(0 <= direction && direction < 6);
	return hex_directions[direction];
}

Hex hex_neighbor(Hex hex, int direction) {
	return hex + hex_direction(direction);
}
#pragma endregion Location Calculations


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
