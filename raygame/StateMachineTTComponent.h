#pragma once
#include "Component.h"

enum State
{
	SEEK,
	FLEE,
};

class SeekTTComponent;
class FleeTTComponent;

class StateMachineTTComponent :
	public Component
{
public:
	void start() override;

	State getCurrentState() { return m_currentState; }
	void setCurrentState(State state) { m_currentState = state; }

	void update(float deltaTime) override;

private:
	State m_currentState;
	SeekTTComponent* m_seekComponent;
	FleeTTComponent* m_fleeComponent;
	float m_seekForce;
	float m_fleeForce;
	float m_seekRange = 150;

};

