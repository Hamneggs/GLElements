#ifndef ANIMATED_TILE_GUARD
#define ANIMATED_TILE_GUARD

#include "ArtTile.h"
#include "Animation.h"

class AnimatedTile : public ArtTile
{
	public:
	
		AnimatedTile(void);
		~AnimatedTile(void);
		
		/*
		Initializes the Animated Tile. In this version we initialize all location 
		and size variables to 0.
		*/
		bool init(Animation * animation, unsigned int newID);
		
		/*
		Initializes the Animated Tile.
		*/
		bool init(Animation * animation, float locX, float locY, float locZ, 
				float width, float height, unsigned int newID);
		
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
		Returns the Animation assigned to this Animated tile.
		*/
		Animation * getAnimation(void);
		
		/*
		Assigns an animation to this Animated tile.
		*/
		void setAnimation(Animation * animation);
		
	private:
		
		/*
		The underlying animation of this Animated Tile.
		*/
		Animation * animation;
};
#endif