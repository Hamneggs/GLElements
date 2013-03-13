#include "AnimatedTileBay.h"

AnimatedTileBay::AnimatedTileBay(void)
{
	currentID = 0;
}

AnimatedTileBay::~AnimatedTileBay(void)
{
	// Blah
}

bool AnimatedTileBay::init(void)
{
	return true;
}

bool AnimatedTileBay::addTile(Animation * animation, float x=0, float y=0, float z=0, 
						float width=0, float height=0)
{
	unsigned int previousSize = tiles.size();
	tiles.push_back(AnimatedTile(animation, x, y, z, width, height, currentID);
	
	unsigned int currentSize = tiles.size();
	return (current == previousSize+1);
}

AnimatedTile * AnimatedTileBay::getTileByID(int id)
{
	for(unsigned int i = id; i >= 0; i--)
	{
		if(i >= tiles.size())
		{
			continue;
		}
		else if(tiles[i].id == id)
		{
			return &tiles[i];
		}
	}
}

AnimatedTile AnimatedTileBay::removeTileByID(int id)
{
	AnimatedTile returnMe;
	unsigned int indexOf = 99999999;
	for(unsigned int i = id; i >= 0; i--)
	{
		if(i >= tiles.size())
		{
			continue;
		}
		else if(tiles[i].id == id)
		{
			returnMe = tiles[i];
			indexOf = i;
			break;
		}
	}
	tiles.erase(tiles.begin()+indexOf);
	return returnMe;
}

bool AnimatedTileBay::deleteTileByID(int id)
{
	AnimatedTile returnMe;
	unsigned int indexOf = 99999999;
	bool found = false;
	for(unsigned int i = id; i >= 0; i--)
	{
		if(i >= tiles.size())
		{
			continue;
		}
		else if(tiles[i].id == id)
		{
			returnMe = tiles[i];
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
		tiles.erase(tiles.begin()+indexOf);
		return true;
	}
}

unsigned int AnimatedTileBay::getNumTiles(void)
{
	return tiles.size();
}