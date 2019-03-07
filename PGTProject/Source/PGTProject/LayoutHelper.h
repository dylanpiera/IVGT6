// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IntPoint.h"

/**
 *
 */
class PGTPROJECT_API LayoutHelper
{
public:

#pragma region Orientation Const
	struct Orientation
	{
		Orientation(const double f0, const double f1, const double f2, const double f3, const double b0, const double b1, const double b2, const double b3,
			const double startAngle)
			: _f0(f0),
			_f1(f1),
			_f2(f2),
			_f3(f3),
			_b0(b0),
			_b1(b1),
			_b2(b2),
			_b3(b3),
			_startAngle(startAngle) {}

		const double _f0, _f1, _f2, _f3;
		const double _b0, _b1, _b2, _b3;
		const double _startAngle; // in multiples of 60°
	};

	const Orientation _layoutPointy = Orientation(sqrt(3.0), sqrt(3.0) / 2.0, 0.0, 3.0 / 2.0,
		sqrt(3.0) / 3.0, -1.0 / 3.0, 0.0, 2.0 / 3.0,
		0.5);

	const Orientation _layoutflat = Orientation(3.0 / 2.0, 0.0, sqrt(3.0) / 2.0, sqrt(3.0),
		2.0 / 3.0, 0.0, -1.0 / 3.0, sqrt(3.0) / 3.0,
		0.0);
#pragma endregion Orientation Const 

#pragma region Layout
	struct Layout {
		const Orientation _orientation;
		const FIntPoint _size;
		const FIntPoint _origin;

		Layout(const Orientation& orientation, const FIntPoint& size, const FIntPoint& origin)
			: _orientation(orientation),
			  _size(size),
			  _origin(origin) {}
	};


#pragma endregion Layout
};