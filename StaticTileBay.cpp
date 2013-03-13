#include "StaticTileBay.h"

StaticTileBay::StaticTileBay(void)
{
	currentID = 0;
}

StaticTileBay::~StaticTileBay(void)
{
	// Blah
}

bool StaticTileBay::init(void)
{
	return true;
}

bool StaticTileBay::addTile(GLTexture * texture, GLCamera * camera, ShaderProgram * shaderProgram, float x=0, float y=0, float z=0, 
						float width=0, float height=0)
{
	unsigned int previousSize = tiles.size();
	tiles.push_back(StaticTile(animation, x, y, z, width, height, currentID);
	
	unsigned int currentSize = tiles.size();
	return (current == previousSize+1);
}

StaticTile * StaticTileBay::getTileByID(int id)
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

StaticTile StaticTileBay::removeTileByID(int id)
{
	StaticTile returnMe;
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

bool StaticTileBay::deleteTileByID(int id)
{
	StaticTile returnMe;
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

unsigned int StaticTileBay::getNumTiles(void)
{
	return tiles.size();
}