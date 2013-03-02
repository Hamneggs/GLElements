#include <vector>
#include "Animation.h"

/*
	This class represents a collection of Animations. This allows a sprite-table ideology
	that allows Animations to be drawn repeatedly.
*/
class AnimationBay{
	public:
	
		/*
		Constructs the AnimationBay.
		*/
		AnimationBay(void);
	
		/*
		Destructs the AnimationBay.
		*/
		~AnimationBay(void);
	
		/*
		Initializes the AnimationBay.
		*/
		bool init(GLCamera * camera);
		
	
		/*
		Adds a new Animation to the bay. This actually constructs an animation and places it in the
		underlying vector.
		*/
		bool addAnimation(GLTexture * texture, ShaderProgram * program, float frameTime, int numFrames, 
							float x=0, float y=0, float z=0, float width=0, float height=0);
		
		/*
		Returns an Animation by searching for it in the arraylist.
		*/
		Animation * getAnimationByID(int id);
		
		/*
		Removes an Animation from the bay and returns it whole.
		*/
		Animation removeAnimationByID(int id);
		
		/*
		Deletes an Animation without returning it.
		*/
		bool deleteAnimationByID(int id);
		
		/*
		Sets the camera that is supplied to all of the Animations in the bay.
		*/
		void setCamera(GLCamera * camera);
		
		/*
		Returns the camera that is supplied to all of the Animations in the bay.
		*/
		GLCamera * getCamera(void);
		
		/*
		Returns the number of tiles in the bay.
		*/
		unsigned int numberOfTiles(void);
	
	private:
	
		/*
		The camera that is common to all of the Animations in the bay.
		*/
		GLCamera * camera;
		
		/*
		The vector that stores the Animations of this bay.
		*/
		std::vector<Animation> animations;
		
		
};