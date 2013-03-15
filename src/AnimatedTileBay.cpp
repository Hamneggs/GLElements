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

bool AnimatedTileBay::addTile(Animation * animation, float x, float y, float z, 
						float width, float height)
{
	unsigned int previousSize = tiles.size();

	AnimatedTile toAdd;
	bool shouldAdd = toAdd.init(animation, x, y, z, width, height, currentID);
	if(shouldAdd){tiles.push_back(toAdd);}
	
	unsigned int currentSize = tiles.size();
	return (currentSize == previousSize+1);
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
	return NULL;
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