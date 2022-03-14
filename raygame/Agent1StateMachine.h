#pragma once
#include "Component.h"

enum State
{
	IDLE,
	ChaseBall,
	ChaseGoal
};

class SeekMLComponent;

class Agent1StateMachine :
	public Component
{
public:

	void start() override;

	State getCurrentState() { return m_currentState; }
	void setCurrentState(State state) { m_currentState = state; }
	void update(float deltaTime) override;

private:
	State m_currentState;
	SeekMLComponent* m_seekComp;
	float m_seekForce;
};
