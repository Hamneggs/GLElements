#ifndef PARALLAX_LAYER_GUARD
#define PARALLAX_LAYER_GUARD

#include "ArtTile.h"
#include "GLCamera.h"

/*
	This class manipulates an ArtTile as a parallax layer.
	
	What this means is that the underlying ArtTile is moved
	along the same vector of the camera, with a different
	magnitude. This provides for the illusion of parallax 3D.
	
	A breakdown of how movementScale can affect the parallax illusion:
		1.0 = The ArtTile will be locked to the location of the
			camera, giving the impression of infinite distance.
		0.0 = The ArtTile will not be moved along with the
			camera at all, giving the impression of being at the
			same distance as the main plane.
		-1.0 = The ArtTile will be moved in the opposite direction
			as the camera, giving the impression that the Parallax
			layer is very, very near the camera.
	
	You can also choose whether the position of the underlying ArtTile is
	automatically updated with each call to draw, or is manually
	done with a call to updatePosition(void). This is done by setting
	the state of the boolean updateAtDraw.
*/
class ParallaxLayer{

	public:
	
		/*
		Constructs a new ParallaxLayer.
		*/
		ParallaxLayer(void);
	
		/*
		Destructs the Parallaxlayer.
		*/
		~ParallaxLayer(void);
	
		/*
		Initializes this ParallaxLayer.
		*/
		bool init(GLCamera * cameraToUse, ArtTile * tileToUse, float movementScale, bool updateAtDraw);
	
		/*
		Sets the GLCamera used by this ParallaxLayer.
		*/
		void setCamera(GLCamera * newCamera);
	
		/*
		Returns the GLCamera used by this Parallaxlayer.
		*/
		GLCamera * getCamera(void);
	
		/*
		Sets the ArtTile used by this ParallaxLayer.
		*/
		void setTile(ArtTile * newTile);
	
		/*
		Returns the ArtTile used by this ParallaxLayer.
		*/
		ArtTile * getTile(void);
	
		/*
		Sets the percentage of camera movement that this Parallax 
		Layer will move.
		*/
		void setMovementScale(float newMovementScale);
	
		/*
		Changes the current amount of camera movement that this
		ParallaxLayer will move by a set amount.
		*/
		void changeMovementScale(float changeMovementScale);
	
		/*
		Returns the percentage of Camera Movement that this
		ParallaxLayer will appear to move.
		*/
		float getMovementScale(void);
		
		/*
		Sets whether or not this Parallax Layer will be updated
		automatically with each call to draw().
		*/
		void setAutoUpdate(bool newState);
		
		/*
		Returns whether or not this Parallax Layer will be
		updated automatically with each call to draw().
		*/
		bool getAutoUpdateState(void);
		
		/*
		Draws the ParallaxLayer.
		*/
		void draw(void);
		
		/*
		The sort-of-pointless external manual position update function.
		*/
		void update(void);
		
	private:
	
		/*
		A pointer to the GLCamera instance that this Parallax
		Layer listens to.
		*/
		GLCamera * camera;
	
		/*
		A pointer to the underlying ArtTile instance.
		*/
		ArtTile * tile;
	
		/*
		The percentage of the camera movement that the ArtTile
		will be moved by.
		
		1.0 = The ArtTile will be locked to the location of the
			camera, giving the impression of infinite distance.
		0.0 = The ArtTile will not be moved along with the
			camera at all, giving the impression of being at the
			same distance as the main plane.
		-1.0 = The ArtTile will be moved in the opposite direction
			as the camera, giving the impression that the Parallax
			layer is very, very near the camera.
		*/
		float moveScale;
	
		/*
		Whether or not the position of the ArtTile is updated on
		each call to draw(void).
		*/
		bool updateAtDraw;
		
		/*
		The previous X position of the camera.
		*/
		float prevX;
		
		/*
		The current Y position of the camera.
		*/
		float prevY;
		
		/*
		The current Z position of the camera.
		*/
		float prevZ;
};
#endif