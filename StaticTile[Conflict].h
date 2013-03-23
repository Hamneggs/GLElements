#ifndef STATIC_TILE_GUARD
#define STATIC_TILE_GUARD

#include "ArtTile.h"
#include "Shaders.h"
#include "GLTexture.h"

class StaticTile : ArtTile
{
	public:
		StaticTile(void);
		~StaticTile(void);
		
		/*
		Initializes the StatiuTile. In this version we initialize all location 
		and size variables to 0.
		*/
		bool init(GLTexture * texture, GLCamera * camera, ShaderProgram * shader, unsigned int newID);
		
		/*
		Initializes the Static Tile.
		*/
		bool init(GLTexture * texture, GLCamera * camera, ShaderProgram * shaderProgram, float locX, float locY, float locZ, float width, float height, unsigned int newID);
		
		/*
		Renders the Static Tile.
		*/
		void draw(void);
		
		/*
		Renders the Static Tile at the given location.
		*/
		void draw(float x, float y, float z);
		
		/*
		Renders the Static Tile at the given location and size.
		*/
		void draw(float x, float y, float z, float width, float height);
		
};

#endif