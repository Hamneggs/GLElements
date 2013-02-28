#include "freeimage.h"
#include "Shaders.h"
#include "GLTexture.h"
#include <ctime>

/*
	This class represents a single animation that can be drawn to the screen.
	Normally this would be drawn as part of something else, be it an Animation
	System or an AnimatedTile, but it can be used alone as well.
	
	This works on the premise that the animation textur is actually a 
	long strip of several frames, and every time we want to change frames,
	we just change the current UV coordinates.
	
	In essence, this is just a texture drawn on a quad. Use accordingly.
	
	Enjoy some explanatory ASCII art:
	----------------------------------------------------------------------------
	|              |              |              |              |              |
	|              |              |              |              |              |
	| Frame 0      | Frame 1      | Frame 2      | Frame 3      | Frame 4      |
	|              |              |              |              |              |
	|              |              |              |              |              |
	----------------------------------------------------------------------------
	^                                                                          ^
	UV X coordinate = 0	                                     UV X coordinate = 1
	
	FRAME ADVANCING MODES:
	===============================================================================
	The animation has two modes: PASSIVE_ADVANCE, where the frame count is 
	updated automatically based on the current system time of each draw call, 
	and ACTIVE_ADVANCE, where the frame count is not updated automatically,
	and you must call forceSetFrame() or forceUpdateFrame() to advance the
	Animation.
	
	DRAWING:
	===============================================================================
	There are also two ways to draw an Animation. Either you can pass draw()
	the X, Y, and Z coordiates of where you want to draw the Animation, or
	you can use the stored values and call draw() with no arguments, using
	changeLocation() and setLocation() to update the position of the quad.
	
	Since size is something that will be changed less often, changeSize() 
	and setSize() must be used to manipulate the size of the Animation's
	quad.
	
	TIMING:
	===============================================================================
	When using PASSIVE_ADVANCE, the timer's start time is by default the time
	the animation is initialized, meaning that the animation will be synchronized
	to the most recent call to init(). However, this can be updated by
	calling resetTimer(), which will synchronize the Animation to the time
	the call to resetTimer() was performed.
	
	Timing is meant to appear as a float, since it is much easer to set the
	frame time as 1/60.0 seconds rather than 16 milliseconds. However 
	underneath it all we still use ctime's millisecond tick. Accuracy will
	reflect this.
	
	SHADING:
	================================================================================
	The Animations require a very specific ShaderProgram. It must accept location
	data in layout position 0, and UV data in layout position 1. Also it
	must have passed in the X, Y, and Z coordinates as uniforms "x", "y", 
	and "z". The same goes for width and height, where the uniforms must be named
	"width", and "height". Other uniforms needed are current frame "cur_frame"
	and total number of frames "num_frames." 
	
	What you decide to do with those is up to you, but I would recommend following
	the example of the example shaders.
	
	Also, you can extend this class and override the necessary functions if
	you want to hack around these constraints. I'm not that much of an asshole.
	
*/
class Animation{
	public:
		Animation(void);
		~Animation(void);
		
		bool init(char * imagePath, float frameTime, int numFrames, ShaderProgram shader);
		bool init(char * imagePath, float frameTime, int numFrames, float locX, float locY, float locZ, ShaderProgram shader);
		
		void draw(void);
		void draw(float x, float y, float z);
		
		void setLocation(float newX, float newY, float newZ);
		void changeLocation(float changeX, float changeY, float changeZ);
		
		float getX(void);
		float getY(void);
		float getZ(void);
		
		void setSize(float newWidth, float newHeight);
		void changeSize(float changeWidth, float changeHeight);
		
		float getWidth(void);
		float getHeight(void);
		
		void forceSetFrame(int frame);
		void forceUpdateFrame(void);
		int getCurrentFrame(void);
		void resetTimer(void);
		
		void setFrameTime(float newFrameTime);
		void changeFrameTime(float changeFrameTime);
		float getFrameTime(void);
		int getNumFrames(void);
		void changeNumFrames(void);
		
		void setTexture(GLTexture * texture);
		GLTexture * getTexture(void);
		
		
		
	private:
		float width;
		float height;
		
		float x;
		float y;
		float z; // For layer differentiation.
		
		float frametime;
		int numFrames;
		int startTime;
		int curTime;
		
		int curFrame;
		
		int vertArray;
		int locationBO;
		int uvBO;
		
		GLTexture texture;
		
		
};

enum ADVANCE_MODE{
	ACTIVE_ADVANCE = 0,
	PASSIVE_ADVANCE = 1
};