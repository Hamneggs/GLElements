#ifndef STATIC_TILE_BAY_GUARD
#define STATIC_TILE_BAY_GUARD

#include <vector>
#include "StaticTile.h"

/*
	This class is meant to be a collection of tiles Tiles.
	This allows for a sprite-table ideology, and for any tiles Tile
	in the bay to be drawn repeatedly rather than to exist repeatedly.
*/
class StaticTileBay{
	public:
		StaticTileBay(void);
		~StaticTileBay(void);
		
		/*
		Initializes the StaticTile Bay. This function is included for solidarity
		of form with other bays.
		*/
		bool init(void);
		
		/*
		Constructs and adds a StaticTile to the bay.
		*/
		bool addTile(GLTexture * texture, GLCamera * camera, ShaderProgram * shaderProgram, float x=0, float y=0, float z=0, 
					float width=0, float height=0);
					
		/*
		Returns an StaticTile by searching for it in the arraylist.
		*/
		StaticTile * getTileByID(int id);
		
		/*
		Removes an StaticTile from the bay and returns it whole.
		*/
		StaticTile removeTileByID(int id);
		
		/*
		Deletes an StaticTile without returning it.
		*/
		bool deleteTileByID(int id);
		
		/*
		Returns the number of StaticTiles in the bay.
		*/
		unsigned int getNumTiles(void);
		
		
	private:
	
		/*
		The vector that stores the tiles Tiles of this bay.
		*/
		std::vector<StaticTile> tiles;
		
		/*
		The current ID.
		*/
		unsigned int currentID;
		
};
#endif