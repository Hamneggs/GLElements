#ifndef GLCAMERA_GUARD
#define GLCAMERA_GUARD

#include "dependencies/glm/glm.hpp"
#include "dependencies/glm/gtc/matrix_transform.hpp"
#include "dependencies/glm/gtc/type_ptr.hpp"

/*
	GLCamera is just what it sounds like. This class encapsulates
	a single 4x4 matrix that serves as the camera position.
	
	USAGE:
	===================================================================
	Just think of it like a camera. You move the camera around to
	see different stuff.
*/


class GLCamera{
	public:
	
		/*
		Constructs the GLCamera.
		*/
		GLCamera(void);
		
		/*
		Destructs the GLCamera.
		*/
		~GLCamera(void);
		
		/*
		Calls GLM's lookAt() on the underlying matrix.
		*/
		void lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
		
		/*
		Returns a pointer to the underlying matrix.
		*/
		glm::mat4 * getCameraMatrix(void);

		/*
		Returns the X location stored in the camera matrix.
		*/
		float getX(void);

		/*
		Returns the Y location stored in the camera matrix.
		*/
		float getY(void);

		/*
		Returns the Z location stored in the camera matrix.
		*/
		float getZ(void);

	private:
	
		/*
		The underlying matrix that the camera exists in.
		*/
		glm::mat4 cameraMatrix;
};

#endif
	