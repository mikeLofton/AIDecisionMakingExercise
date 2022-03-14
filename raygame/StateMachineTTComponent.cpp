#include "StateMachineTTComponent.h"
#include "Actor.h"
#include "SeekTTComponent.h"
#include "Transform2D.h"

void StateMachineTTComponent::start()
{
	Component::start();

	m_seekComponent = getOwner()->getComponent<SeekTTComponent>();
	m_seekForce = m_seekComponent->getSteeringForce();

	m_currentState = SEEK;
}

void StateMachineTTComponent::update(float deltaTime)
{
	MathLibrary::Vector2 targetPos = m_seekComponent->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();//Gets the distance from the target 

	bool targetInRange = distanceFromTarget <= m_seekRange;//Gets a bull by doing operation on same line

	switch (m_currentState)
	{
	case SEEK:
		m_seekComponent->setSteeringForce(m_seekForce);

		if (!targetInRange)
			setCurrentState(SEEK);

		break;
	}
}

