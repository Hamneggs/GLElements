#include "Animation.h"

Animation::Animation(void)
{
}

Animation::~Animation(void)
{
}

bool Animation::init(char * imagePath, float frameTime, int numFrames, ShaderProgram shaderProgram)
{
	
}

bool Animation::init(char*imagePath, float frameTime, int numFrames, float locX, float locY, float locZ, float width, float height, ShaderProgram shaderProgram
{
}

void Animation::draw(void)
{
}

void Animation::draw(float x, float y, float z)
{
}

void Animation::setLocation(float newX, float newY, float newZ)
{
}

void Animation::changeLocation(float changeX, float changeY, float changeZ)
{
}

void Animation::setSize(float newWidth, float newHeight)
{
}

void Animation::changeSize(float changeWidth, float changeHeight)
{
}

float Animation::getX(void)
{
	return x;
}

float Animation::getY(void)
{
	return y;
}

float Animation::getZ(void)
{
	return z;
}

float Animation::getWidth(void)
{
	return width;
}

float Animation::getHeight(void)
{
	return height;
}

void Animation::forceSetFrame(int index)
{
	curFrame = index%numFrames;
}

void Animation::forceUpdateFrame(void)
{
	curFrame++;
	curFrame %= numFrames;
}

int Animation::getCurrentFrame(void)
{
	return curFrame;
}

void Animation::resetTimer(void)
{
	#ifdef _WIN32
	// Now this is nice and easy.
	DWORD currentTime = getTickCount();
	startTime = (unsigned int)currentTime;
	curTime = (unsigned int)currentTime;
	
	#else
	// This isn't really.
	timeval timeValue;
	gettimeofday(timeValue, NULL);
	startTime = (unsigned int)timeValue.Milliseconds;
	curTime = (unsigned int)timeValue.Milliseconds;
	
	#endif
	
}

void Animation::setFrameTime(float newFrameTime)
{
	frameTime = newFrameTime;
}

void Animation::changeFrameTime(float changeFrameTime)
{
	frameTime += changeFrameTime;
}

float Animation::getFrameTime(void)
{
	return frameTime;
}

void Animation::setNumFrames(int newNumFrames)
{
	numFrames = newNumFrames;
}

int Animation::getNumFrames(void)
{
	return numFrames;
}

void Animation::setTexture(GLTexture * newTexture)
{
	texture = newTexture;
}

GLTexture * Animation::getTexture(void)
{
	return texture;
}

void Animation::setShader(ShaderProgram * newProgram)
{
	shader = newProgram;
}

ShaderProgram * Animation::getShader(void)
{
	return shader;
}

ADVANCE_MODE Animation::getAdvanceMode(void)
{
	return advanceMode;
}

void Animation::setAdvanceMode(ADVANCE_MODE newMode)
{
	advanceMode = newMode;
}
