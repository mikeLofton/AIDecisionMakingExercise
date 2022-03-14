#pragma once
#include "Actor.h"
class SpriteComponent;

class MLSword :
	public Actor
{
public:
	MLSword(Actor* owner, float x, float y, const char* name);

	void start() override;
private:
	Actor* m_owner;
};

