/*
	THIS CLASS IS ABSTRACT.
	
	This class defines an abstract art asset tile.
*/
#ifndef ART_TILE_GUARD
#define ART_TILE_GUARD

class ArtTile
{
	public:
	
		/*
		Renders the Art Tile.
		*/
		virtual void draw(void) = 0;
		
		/*
		Renders the Art Tile at the given location.
		*/
		virtual void draw(float x, float y, float z) = 0;
		
		/*
		Renders the Art Tile at the given location and size.
		*/
		virtual void draw(float x, float y, float z, float width, float height) = 0;
		
		/*
		Sets the location of the Art Tile.
		*/
		void setLocation(float newX, float newY, float newZ);
			
		/*
		Changes the location of the Art Tile.
		*/
		void changeLocation(float changeX, float changeY, float changeZ);
			
		/*
		Sets the size of the Art Tile.
		*/
		void setSize(float newWidth, float newHeight);
			
		/*
		Changes the size of the Art Tile.
		*/
		void changeSize(float changeWidth, float changeHeight);
		
		/*
		Returns the X location of this Animation.
		*/
		float getX(void);
		
		/*
		Returns the Y location of this Art Tile.
		*/
		float getY(void);
		
		/*
		Returns the Z location of this Art Tile.
		*/
		float getZ(void);
		
		/*
		Returns the width of this Art Tile.
		*/
		float getWidth(void);
		
		/*
		Returns the height of this Art Tile.
		*/
		float getHeight(void);
		
		/*
		Returns the ID of this Art Tile.
		*/
		unsigned getID(void);
	
		/*
		The ID of this Art Tile.
		*/
		unsigned int id;
		
		/*
		The X location of this Art Tile.
		*/
		float x;
		/*
		The Y location of this Art Tile.
		*/
		float y;
		
		/*
		The Z location of this Art Tile.
		*/
		float z;
		
		/*
		The width of this Art Tile.
		*/
		float width;
		
		/*
		The height of this Art Tile.
		*/
		float height;
};

#endif