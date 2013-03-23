#include "GLCamera.h"

GLCamera::GLCamera(void)
{
	// We don't really need to do anything.
}

GLCamera::~GLCamera(void)
{
	// We also don't have to do anything here.
}

void GLCamera::lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ)
{
	cameraMatrix = glm::lookAt(glm::vec3(eyeX, eyeY, eyeZ), glm::vec3(centerX, centerY, centerZ), glm::vec3(upX, upY, upZ));
}

glm::mat4 * GLCamera::getCameraMatrix(void)
{
	return &cameraMatrix;
}

float GLCamera::getX(void)
{
	return glm::value_ptr(cameraMatrix)[0];
}

float GLCamera::getY(void)
{
	return glm::value_ptr(cameraMatrix)[1];
}

float GLCamera::getZ(void)
{
	return glm::value_ptr(cameraMatrix)[2];
}

