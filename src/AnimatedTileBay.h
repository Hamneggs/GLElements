#ifndef ANIMATED_TILE_BAY_GUARD
#define ANIMATED_TILE_BAY_GUARD

#include <vector>
#include "AnimatedTile.h"

/*
	This class is meant to be a collection of Animated Tiles.
	This allows for a sprite-table ideology, and for any Animated Tile
	in the bay to be drawn repeatedly rather than to exist repeatedly.
*/
class AnimatedTileBay{
	public:
		AnimatedTileBay(void);
		~AnimatedTileBay(void);
		
		/*
		Initializes the Animation Bay. This function is included for solidarity
		of form with other bays.
		*/
		bool init(void);
		
		/*
		Constructs and adds an animated tile to the bay.
		*/
		bool addTile(Animation * animation, float x=0, float y=0, float z=0, 
					float width=0, float height=0);
					
		/*
		Returns an AnimatedTile by searching for it in the arraylist.
		*/
		AnimatedTile * getTileByID(int id);
		
		/*
		Removes an AnimatedTile from the bay and returns it whole.
		*/
		AnimatedTile removeTileByID(int id);
		
		/*
		Deletes an AnimatedTile without returning it.
		*/
		bool deleteTileByID(int id);
		
		/*
		Returns the number of Animated Tiles in the bay.
		*/
		unsigned int getNumTiles(void);
		
		
	private:
	
		/*
		The vector that stores the Animated Tiles of this bay.
		*/
		std::vector<AnimatedTile> tiles;
		
		/*
		The current ID.
		*/
		unsigned int currentID;
		
};
#endif