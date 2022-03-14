#pragma once
#include "SteeringComponent.h"
class FleeTTComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

