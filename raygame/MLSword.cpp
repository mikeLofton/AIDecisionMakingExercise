#include "MLSword.h"
#include "SpriteComponent.h"
#include "AABBCollider.h"
#include "Transform2D.h"

MLSword::MLSword(Actor* owner, float x, float y, const char* name) : Actor::Actor(x, y, name)
{
	m_owner = owner;

	addComponent(new SpriteComponent("Images/sword.png"));
}

void MLSword::start()
{
	Actor::start();

	getTransform()->setScale({ 50, 50 });
	AABBCollider* swordCollider = new AABBCollider(3, 10, this);
	setCollider(swordCollider);
}
