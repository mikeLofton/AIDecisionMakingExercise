#pragma once
#include "SteeringComponent.h"

class SeekTTComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};


