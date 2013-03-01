#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

/*
	GLCamera is just what it sounds like. This class encapsulates
	a single 4x4 matrix that serves as the camera position.
	
	USAGE:
	===================================================================
	Just think of it like a camera. You move the camera around to
	see different stuff.
*/

#ifndef GLCAMERA_GUARD
#define GLCAMERA_GUARD
class GLCamera{
	public:
		GLCamera(void);
		~GLCamera(void);
		void lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
		glm::mat4 getCameraMatrix(void);
	private:
		glm::mat4 cameraMatrix;
};
	