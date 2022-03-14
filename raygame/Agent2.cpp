#include "Agent2.h"
#include "SpriteComponent.h"
#include "GameManager.h"
#include "Goal.h"
#include "MoveComponent.h"
#include "SteeringComponent.h"
#include "SeekTTComponent.h"
#include "StateMachineTTComponent.h"

Agent2::Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/enemy.png"));
}

void Agent2::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent2::start()
{
	Character::start(); 
	//add steering behaviours here
	MoveComponent* moveComp = new MoveComponent();
	m_moveComponent = addComponent<MoveComponent>();
	m_moveComponent->setMaxSpeed(500);
	
	addComponent(moveComp);
	addComponent<SteeringComponent>();
	addComponent<StateMachineTTComponent>();
}

void Agent2::update(float deltaTime)
{
	Character::update(deltaTime);

	//GEt all force being applied from steering behaviours
	for (int i = 0; i < m_steeringComponents.getLength(); i++)
	{
		m_force = m_force + m_steeringComponents[i]->calculateForce();
	}

	//Clamp force if it exceeds the maximum scale
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}

	//Apply force to velocity
	getMoveComponent()->setVelocity(getMoveComponent()->getVelocity() + m_force * deltaTime);
}

void Agent2::onDeath()
{
	Character::onDeath();

}

void Agent2::onAddComponent(Component* component)
{
	SteeringComponent* steeringComponent = dynamic_cast<SteeringComponent*>(component);
	if (steeringComponent != nullptr)
		m_steeringComponents.addItem(steeringComponent);
}