#include "Agent1StateMachine.h"
#include "SeekMLComponent.h"
#include "Actor.h"
#include "Transform2D.h"

void Agent1StateMachine::start()
{
	Component::start();

	m_seekComp = getOwner()->getComponent<SeekMLComponent>();
	m_seekForce = m_seekComp->getSteeringForce();

	m_currentState = IDLE;
}

void Agent1StateMachine::update(float deltaTime)
{
	MathLibrary::Vector2 targetPos = m_seekComp->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();

	switch (m_currentState)
	{
	case IDLE:

	}
}
