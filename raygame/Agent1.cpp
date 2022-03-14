#include "Agent1.h"
#include "SpriteComponent.h"
#include "Goal.h"
#include "GameManager.h"
#include "SeekMLComponent.h"
#include "MoveComponent.h"
#include "SteeringComponent.h"

Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/player.png"));
}

void Agent1::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent1::start()
{
	Character::start();
	//add steering behaviours here
	m_moveComp = addComponent<MoveComponent>();
	SeekMLComponent* seekComp = new SeekMLComponent();
	seekComp->setSteeringForce(100);


	addComponent(seekComp);
}

void Agent1::update(float deltaTime)
{
	Character::update(deltaTime);

	for (int i = 0; i < m_steeringBehaviors.getLength(); i++)
		m_force = m_force + m_steeringBehaviors[i]->calculateForce();

	if (m_force.getMagnitude() > getMaxForce())
		m_force = m_force.getNormalized() * getMaxForce();

	getMoveComp()->setVelocity(getMoveComp()->getVelocity() + m_force * deltaTime);
}

void Agent1::onDeath()
{
	Character::onDeath();

}

void Agent1::onAddComponent(Component* comp)
{
	SteeringComponent* steeringComp = dynamic_cast<SteeringComponent*>(comp);

	if (steeringComp)
		m_steeringBehaviors.addItem(steeringComp);
}
