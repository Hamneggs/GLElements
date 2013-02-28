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
}

float Animation::getY(void)
{
}

float Animation::getZ(void)
{
}

float Animation::getWidth(void)
{
}

float Animation::getHeight(void)
{
}

void Animation::forceSetFrame(int index)
{
}

void Animation::forceUpdateFrame(void)
{
}

int Animation::getCurrentFrame(void)
{
}

void Animation::resetTimer(void)
{
}

void Animation::setFrameTime(float newFrameTime)
{
}

void Animation::changeFrameTime(float changeFrameTime)
{
}

float Animation::getFrameTime(void)
{
}

void Animation::setNumFrames(int newNumFrames)
{
}

int Animation::getNumFrames(void)
{
}

void Animation::setTexture(GLTexture * texture)
{
}

GLTexture * Animation::getTexture(void)
{
}

void Animation::setShader(ShaderProgram * newProgram)
{
}

ShaderProgram * Animation::getShader(void)
{
}

ADVANCE_MODE Animation::getAdvanceMode(void)
{
}

void Animation::setAdvanceMode(ADVANCE_MODE newMode)
{
}
