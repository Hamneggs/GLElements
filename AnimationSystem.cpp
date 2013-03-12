#include "AnimationSystem.h"


AnimationSystem::AnimationSystem(void)
{
	x = 0;
	y = 0;
	z = 0;
	width = 0;
	height = 0;
}

AnimationSystem::~AnimationSystem(void)
{
	// Nothing to do here.
}

void AnimationSystem::init(float x, float y, float z, float width, float height, unsigned int id)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = width;
	this->height = height;
	this->id = id;
}

int AnimationSystem::addNewState(Animation * newAnimation)
{
	int maxID = 0;
	for(unsigned int i = 0; i < states.size(); i++)
	{
		if(states[i].stateID >= maxID)
		{
			maxID = states[i].stateID;
		}
	}
	
	ANIM_STATE newState;
	newState.stateID = ++maxID;
	newState.anim = newAnimation;
	states.push_back(newState);
	return newState.stateID;
}

bool AnimationSystem::addNewState(ANIM_STATE newState)
{
	unsigned int newID = newState.stateID;
	
	for(unsigned int i = 0; i < states.size(); i++)
	{
		if(states[i].stateID == newID)
		{
			return false;
		}
	}
	
	states.push_back(newState);
	return true;
	
}

bool AnimationSystem::addNewState(unsigned int newStateID, Animation * newAnimation)
{
	for(unsigned int i = 0; i < states.size(); i++)
	{
		if(states[i].stateID == newStateID)
		{
			return false;
		}
	}
	
	ANIM_STATE newState;
	newState.stateID = newStateID;
	newState.anim = newAnimation;
	states.push_back(newState);
	return true;
}

bool AnimationSystem::replaceState(unsigned int stateIDToReplace, Animation * replacementAnimation)
{
	for(unsigned int i = 0; i < states.size(); i++)
	{
		if(states[i].stateID == stateIDToReplace)
		{
			states[i].anim = replacementAnimation;
			return true;
		}
	}
	return false;
}

bool AnimationSystem::deleteState(unsigned int stateIDToDelete)
{
	unsigned int index = 0;
	bool found = false;
	for(unsigned int i = 0; i < states.size(); i++)
	{
		if(states[i].stateID == stateIDToReplace)
		{
			index = i;
			found = true;
		}
	}
	
	if(found)
	{
		states.erase(states.begin()+index);
	}
	return found;
}

ANIM_STATE * AnimationSystem::getState(unsigned int stateID)
{
	for(unsigned int i = 0; i < states.size(); i++)
	{
		if(states[i].stateID == stateID)
		{
			return &states[i];
		}
	}
	return NULL;
}

void AnimationSystem::setCurrentState(unsigned int stateID)
{
	for(unsigned int i = 0; i < states.size(); i++)
	{
		if(states[i].stateID == stateID)
		{
			currentState = states[i];
			return;
		}
	}
}

void AnimationSystem::setLocation(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

void AnimationSystem::changeLocation(float changeX, float changeY, float changeZ)
{
	x += changeX;
	y += changeY;
	z += changeZ;
}

void AnimationSystem::setSize(float newWidth, float newHeight)
{
	width = newWidth;
	height = newHeight;
}

void AnimationSystem::changeSize(float changeWidth, float changeHeight)
{
	width += changeWidth;
	height ++ changeHeight;
}

void AnimationSystem::drawSystem(void)
{
	currentState.anim->draw(x, y, z, width, height);
}

void AnimationSystem::drawSystem(float x, float y, float z)
{
	currentState.anim->draw(x, y, z, width, height);
}

void AnimationSystem::drawSystem(float x, float y, float z, float width, float height)
{
	currentState.anim->draw(x, y, z, width, height);
}

float AnimationSystem::getX(void)
{
	return x;
}

float AnimationSystem::getY(void)
{
	return y;
}

float AnimationSystem::getZ(void)
{
	return z;
}

float AnimationSystem::getWidth(void)
{	
	return width;
}

float AnimationSystem::getHeight(void)
{
	return height;
}

unsigned int AnimationSystem::getID(void)
{
	return id;
}





