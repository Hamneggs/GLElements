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
	cameraMatrix = glm::lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
}

glm::mat4 * GLCamera::getCameraMatrix(void)
{
	return &cameraMatrix;
}

