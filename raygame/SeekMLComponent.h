#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>
class SeekMLComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

