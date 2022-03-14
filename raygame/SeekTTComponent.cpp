#include "SeekTTComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "Agent2.h"

MathLibrary::Vector2 SeekTTComponent::calculateForce()
{
	if (!getTarget())
	{
		return { 0,0 };
	}

	setSteeringForce(500);

	MathLibrary::Vector2 directionToTarget = getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition();

	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return seekForce;
}

MathLibrary::Vector2 SeekTTComponent::calculateForce()
{
	return MathLibrary::Vector2();
}
