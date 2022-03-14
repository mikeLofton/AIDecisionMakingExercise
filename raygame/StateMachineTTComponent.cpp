#include "StateMachineTTComponent.h"
#include "Actor.h"
#include "SeekTTComponent.h"
#include "Transform2D.h"
#include "GameManager.h"

void StateMachineTTComponent::start()
{
	Component::start();

	m_seekComponent = getOwner()->getComponent<SeekTTComponent>();
	m_seekForce = m_seekComponent->getSteeringForce();

	m_currentState = SEEK;
}

void StateMachineTTComponent::update(float deltaTime)
{

	switch (m_currentState)
	{
	case SEEK:
		m_seekComponent->setSteeringForce(m_seekForce);
		m_seekComponent->setTarget(GameManager::getInstance()->getBall());

		break;
	}
}

