#include "AnimationBay.h"

AnimationBay::AnimationBay(void)
{
	// Nothing needs to be done in the constructor.
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
								float x=0, float y=0, float z=0, float width=0, float height=0)
{
	unsigned int previousSize = animations.size();
	animations.push_back(Animation(texture, camera, program, frameTime, numFrames, x, y, z, 
									width, height, (unsigned int)animations.size()));
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

Animation AnimationBay::removeAnimationByID(int id)
{
	Animation returnMe;
	unsigned int indexOf = 99999999;
	for(unsigned int i = id; i >= 0; i--)
	{
		if(i >= animations.size())
		{
			continue;
		}
		else if(animations[i].id == id)
		{
			returnMe = animations[i];
			indexOf = i;
			break;
		}
	}
	animations.erase(animations.begin()+indexOf);
	return returnMe;
}

bool AnimationBay::deleteAnimationByID(int id)
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
		else if(animations[i].id == id)
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