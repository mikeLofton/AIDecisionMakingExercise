#include "Agent1StateMachine.h"
#include "SeekMLComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "GameManager.h"
#include "Character.h"

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

		if (GameManager::getInstance()->getAgent2()->getHasBall() == true)
			setCurrentState(CHASEOPPONENT);
		else if (GameManager::getInstance()->getBall()->getActive() == false)
			setCurrentState(CHASEGOAL);

		break;

	case CHASEGOAL:
		m_seekComp->setSteeringForce(m_seekForce);

		m_seekComp->setTarget((Actor*)GameManager::getInstance()->getRightGoal());

		if (GameManager::getInstance()->getAgent2()->getHasBall() == true)
			setCurrentState(CHASEOPPONENT);
		else if (GameManager::getInstance()->getBall()->getActive() == true)
			setCurrentState(CHASEBALL);

		break;

	case CHASEOPPONENT:
		m_seekComp->setSteeringForce(m_seekForce + 20);

		m_seekComp->setTarget((Actor*)GameManager::getInstance()->getAgent2());

		if (GameManager::getInstance()->getAgent2()->getIsAlive() == false)
			setCurrentState(CHASEBALL);
	}
}
