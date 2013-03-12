#include "AnimatedTile.h"

AnimatedTile::AnimatedTile(void)
{
	x = 0;
	y = 0;
	z = 0;
	width = 0;
	height = 0;
	animation = NULL;
}

AnimatedTile::~AnimatedTile(void)
{
}

bool AnimatedTile::init(Animation * animation, unsigned int newID)
{
	this->animation = animation;
	this->id 		= newID;
	return true;
}

bool AnimatedTile::init(Animation * animation, float locX, float locY, float locZ, 
						float width, float height, unsigned int newID)
{
	this->x 		= locX;
	this->y 		= locY;
	this->z 		= locZ;
	this->width 	= width;
	this->height 	= height;
	this->animation = animation;
	this->id		= newID;
	return true;
}

void AnimatedTile::draw(void)
{
	animation->draw(x, y, z, width, height);
}

void AnimatedTile::draw(float x, float y, float z)
{
	animation->draw(x, y, z, width, height);
}

void AnimatedTile::draw(float x, float y, float z, float width, float height)
{
	animation->draw(x, y, z, width, height);
}

Animation * AnimatedTile::getAnimation(void)
{
	return animation;
}

void AnimatedTile::setAnimation(Animation * animation)
{
	this->animation = animation;
}