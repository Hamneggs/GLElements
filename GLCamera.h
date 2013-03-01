#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#ifndef GLCAMERA_GUARD
#define GLCAMERA_GUARD
class GLCamera{
	public:
		GLCamera(void);
		~GLCamera(void);
		void lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float upX, float upY, float upZ);
		glm::mat4 getCameraMatrix(void);
	private:
		glm::mat4 cameraMatrix;
};
	