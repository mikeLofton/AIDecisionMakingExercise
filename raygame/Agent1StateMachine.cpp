#include "Agent1StateMachine.h"
#include "SeekMLComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "GameManager.h"

void Agent1StateMachine::start()
{
	Component::start();

	m_seekComp = getOwner()->getComponent<SeekMLComponent>();
	m_seekForce = m_seekComp->getSteeringForce();

	m_currentState = IDLE;
}

void Agent1StateMachine::update(float deltaTime)
{
	switch (m_currentState)
	{
	case IDLE:
		m_seekComp->setSteeringForce(0);

		if (GameManager::getInstance()->getBall()->getActive() == true)
			setCurrentState(CHASEBALL);

		break;

	case CHASEBALL:
		m_seekComp->setSteeringForce(m_seekForce);

		m_seekComp->setTarget(GameManager::getInstance()->getBall());

		if (GameManager::getInstance()->getBall()->getActive() == false)
			setCurrentState(CHASEGOAL);

		break;

	case CHASEGOAL:
		m_seekComp->setSteeringForce(m_seekForce);

		m_seekComp->setTarget((Actor*)GameManager::getInstance()->getRightGoal());

		if (GameManager::getInstance()->getBall()->getActive() == true)
			setCurrentState(CHASEBALL);

		break;
	}
}
