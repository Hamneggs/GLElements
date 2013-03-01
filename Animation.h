#include "freeimage.h"
#include "Shaders.h"
#include "GLTexture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "GLCamera.h"

#ifndef _WIN32
#include <sys/time.h>
#else
#include <windows.h>

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
	
	The Z axis is used to differentiate between layers.
	
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
	
	Another necessary element are the inclusion and use of transformation matrices.
	They must be named "cameraMatrix" (this is used in conjunction with the bound
	GLCamera instance) and "modelMatrix". (This is used to pipe in location 
	and size data.)
	
	What you decide to do with those is up to you, but I would recommend following
	the example of the example shaders.
	
	Also, you can extend this class and override the necessary functions if
	you want to hack around these constraints. I'm not that much of an asshole.
	
*/

#ifndef GL_ANIMATION_GUARD
#define GL_ANIMATION_GUARD
class Animation{
	public:
	
		/*
		Constructs an Animation. This is left default for simplicity of use.
		*/
		Animation(void);
		
		/*
		Destructs the Animation. This is responsible for clearing up all GPU resources
		taken up by this Animation.
		*/
		~Animation(void);
		
		/*
		Initializes the Animation. In this version we initialize all location 
		and size variables to 0.
		*/
		bool init(GLTexture * texture, GLCamera * camera, ShaderProgram * shader, float frameTime, int numFrames);
		
		/*
		Initializes the Animation.
		*/
		bool init(GLTexture * texture, GLCamera * camera, ShaderProgram * shaderProgram, float frameTime, int numFrames, float locX, float locY, float locZ, float width, float height);
		
		
		/*
		Draws the Animation using the internal location variables. Use this version if you
		aren't updating the position every frame, or just like calling changeLocation() or
		setLocation().
		*/
		void draw(void);
		
		/*
		Draws the Animation at the specified location, ignoring the stored values
		for location.
		*/
		void draw(float x, float y, float z);
		
		/*
		Sets the location of the Animation.
		*/
		void setLocation(float newX, float newY, float newZ);
		
		/*
		Changes the location of the Animation.
		*/
		void changeLocation(float changeX, float changeY, float changeZ);
		
		/*
		Returns the X location of the Animation.
		*/
		float getX(void);
		
		/*
		Returns the Y location of the Animation.
		*/
		float getY(void);
		
		/*
		Returns the Z location of the Animation.
		*/
		float getZ(void);
		
		/*
		Sets the size of the Animation's quad.
		*/
		void setSize(float newWidth, float newHeight);
		
		/*
		Changes the size of the Animation's quad.
		*/
		void changeSize(float changeWidth, float changeHeight);
		
		/*
		Returns the width of the Animation's quad.
		*/
		float getWidth(void);
		
		/*
		Returns the height of the Animation's quad.
		*/
		float getHeight(void);
		
		/*
		Sets the current frame that the animation is to display
		to the one at the index specified.
		*/
		void forceSetFrame(int index);
		
		/*
		Increments the current frame to display by 1.
		*/
		void forceUpdateFrame(void);
		
		/*
		Returns the current frame to display.
		*/
		int getCurrentFrame(void);
		
		/*
		Resets the timer to be synchronized to the time the
		call to this function was made.
		*/
		void resetTimer(void);
		
		/*
		Sets how long each frame is to last.
		*/
		void setFrameTime(float newFrameTime);
		
		/*
		Changes the duration of each frame.
		*/
		void changeFrameTime(float changeFrameTime);
		
		/*
		Returns the frame duration.
		*/
		float getFrameTime(void);
		
		/*
		Sets the number of frames.
		*/
		void setNumFrames(int numFrames);
		
		/*
		Returns the total number of frames.
		*/
		int getNumFrames(void);
		
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
		Returns the ADVANCE_MODE of this Animation.
		*/
		ADVANCE_MODE getAdvanceMode(void);
		
		/*
		Sets the ADVANCE_MODE of this Animation.
		*/
		void setAdvanceMode(ADVANCE_MODE newMode);
		
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
		Stores the location and size of the Animation's quad GPU-side.
		*/
		void initVerts(void);
		
		/*
		Updates the frame counter based on the current time.
		*/
		void updateTimer(void);
		
		/*
		The width of this Animation's quad.
		*/
		float width;
		
		/*
		The height of this Animation's quad.
		*/
		float height;
		
		/*
		The X location of this Animation. This refers
		to the top left corner of the Animation's quad.
		*/
		float x;
		
		/*
		The Y location of this Animation. This refers
		to the top left corner of the Animation's quad.
		*/
		float y;
		
		/*
		The Z location of this Animation. This refers
		to the top left corner of the Animation's quad.
		*/
		float z; // For layer differentiation.
		
		/*
		The duration of each frame of animation.
		*/
		float frametime;
		
		/*
		The total number of frames.
		*/
		unsigned int numFrames;
		
		/*
		The start time of the Animation.
		*/
		unsigned int startTime;
		
		/*
		The current time of the Animation.
		*/
		unsigned int curTime;
		
		/*
		The current frame of the animation,
		stored locally for easy query.
		*/
		unsigned int curFrame;
		
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
		The texture that is used by the Animation.
		*/
		GLTexture * texture;
		
		/*
		The ADVANCE_MODE of this animation.
		*/
		ADVANCE_MODE advanceMode;
		
		/*
		The ShaderProgram that the Animation uses for drawing.
		*/
		ShaderProgram * shader;
		
		/*
		The GLCamera that the animation is viewed through.
		*/
		GLCamera * camera;
		
};

/*
Determines the frame advance mode of the Animation.
*/
enum ADVANCE_MODE{

	/*
	You must call one of the frame advance methods to change the current
	frame.
	*/
	ACTIVE_ADVANCE = 0,
	
	/*
	Frame advancing is handled internally and is determined by clock.
	This allows for proper operation despite framerate.
	*/
	PASSIVE_ADVANCE = 1
};

#endif