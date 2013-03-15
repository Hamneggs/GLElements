#include "AnimationBay.h"

AnimationBay::AnimationBay(void)
{
	currentID = 0;
}

AnimationBay::~AnimationBay(void)
{
	// All objects are deleted automatically.
}

bool AnimationBay::init(GLCamera * camera)
{
	this->camera = camera;
	return (this->camera != NULL);
}

bool AnimationBay::addAnimation(GLTexture * texture, ShaderProgram * program, float frameTime, int numFrames,
								float x, float y, float z, float width, float height)
{
	unsigned int previousSize = animations.size();
	Animation toAdd;
	bool shouldAdd = toAdd.init(texture, camera, program, frameTime, numFrames, x, y, z, 
									width, height, currentID);
	if(shouldAdd){animations.push_back(toAdd);}
	currentID ++;
	
	unsigned int currentSize = animations.size();
	return (currentSize == previousSize+1);
}

Animation * AnimationBay::getAnimationByID(unsigned int id)
{
	for(unsigned int i = id; i >= 0; i--)
	{
		if(i >= animations.size())
		{
			continue;
		}
		else if(animations[i].id == id)
		{
			return &animations[i];
		}
	}
}

Animation AnimationBay::removeAnimationByID(unsigned int id)
{
	Animation returnMe;
	unsigned int indexOf = 99999999;
	for(unsigned int i = id; i >= 0; i--)
	{
		if(i >= animations.size())
		{
			continue;
		}
		else if(animations[i].getID() == id)
		{
			returnMe = animations[i];
			indexOf = i;
			break;
		}
	}
	animations.erase(animations.begin()+indexOf);
	return returnMe;
}

bool AnimationBay::deleteAnimationByID(unsigned int id)
{
	Animation returnMe;
	unsigned int indexOf = 99999999;
	bool found = false;
	for(unsigned int i = id; i >= 0; i--)
	{
		if(i >= animations.size())
		{
			continue;
		}
		else if(animations[i].getID() == id)
		{
			returnMe = animations[i];
			indexOf = i;
			found = true;
			break;
		}
	}
	if(!found)
	{
		return false;
	}
	else
	{
		animations.erase(animations.begin()+indexOf);
		return true;
	}
}

void AnimationBay::setCamera(GLCamera * camera)
{
	this->camera = camera;
	for(unsigned int i = 0; i < animations.size(); i++)
	{
		animations[i].setCamera(this->camera);
	}
}

GLCamera * AnimationBay::getCamera(void)
{
	return camera;
}

unsigned int AnimationBay::getNumAnimations(void)
{
	return animations.size();
}