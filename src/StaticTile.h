#ifndef STATIC_TILE_GUARD
#define STATIC_TILE_GUARD

#include "ArtTile.h"
#include "Shaders.h"
#include "GLTexture.h"
#include "GLCamera.h"

/*
	The Static Tile is a non-animated art tile. It's like one of the dirt tiles in Sonic.
	This simply draws a texture to the screen onto a quad at the given location.
	
	SHADING
	======================================================================================
		Like the Animation, the Static Tile has requirements of shader code used to
	render it. Required uniforms are:
		
		camera_matrix   : The mat4 that stores the camera coordinates.
		location_matrix : The mat4 that stores the location of the object.
		tex_sampler     : The sampler that will store the texture of the 
		                  Static Tile.
						
		Vertex location data is required at layout position 0, and UV coordinate
	data is required at layout position 1. 
	
*/
class StaticTile : public ArtTile
{
	public:
	
		StaticTile(void);
		~StaticTile(void);
		
		/*
		Initializes the Static Tile. In this version we initialize all location 
		and size variables to 0.
		*/
		bool init(GLTexture * texture, GLCamera * camera, ShaderProgram * shader, unsigned int newID);
		
		/*
		Initializes the Static Tile.
		*/
		bool init(GLTexture * texture, GLCamera * camera, ShaderProgram * shaderProgram, 
					float locX, float locY, float locZ, float width, float height, 
					unsigned int newID);
		
		/*
		Renders the Art Tile.
		*/
		void draw(void);
		
		/*
		Renders the Art Tile at the given location.
		*/
		void draw(float x, float y, float z);
		
		/*
		Renders the Art Tile at the given location and size.
		*/
		void draw(float x, float y, float z, float width, float height);
		
		/*
		Sets the texture of this Animation to a different GLTexture.
		*/
		void setTexture(GLTexture * texture);
		
		/*
		Returns the GLTexture associated with this Animation.
		*/
		GLTexture * getTexture(void);
		
		/*
		Sets the ShaderProgram that the Animation uses.
		*/
		void setShader(ShaderProgram * newProgram);
		
		/*
		Returns a pointer to the shader that the Animation is using.
		*/
		ShaderProgram * getShader(void);
		
		/*
		Returns the GLCamera pointer that the Animation uses for perspective.
		*/
		GLCamera * getCamera(void);
		
		/*
		Changes the GLCamera pointer that the Animation uses for perspective.
		*/
		void setCamera(GLCamera * newCamera);
	
	private:
		
		/*
		Initializes the vertex data on the GPU.
		*/
		void initVerts(void);
		
		/*
		The ID given to the vertex array object of this Animation by OpenGL.
		*/
		unsigned int vertArray;
		
		/*
		The ID given to the VBO that stores the location data of the verts of
		the Animation's quad.
		*/
		unsigned int locationBO;
		
		/*
		The ID given to the VBO that stores the UV coordinate data of the
		verts of the Animation's quad.
		*/
		unsigned int uvBO;
		
		/*
		The camera object used for rendering of the tile.
		*/
		GLCamera * camera;
		
		/*
		The texture that is drawn to the tile.
		*/
		GLTexture * texture;
		
		/*
		The shader program that renders the tile.
		*/
		ShaderProgram * shader;
};

#endif