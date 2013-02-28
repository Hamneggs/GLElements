#include "freeimage.h"
#include "shaders.h"

class Animation{
	public:
		Animation(void);
		~Animation(void);
		bool initialize(char * imagePath, ShaderProgram shader); 
	private:
		float width;
		float height;
		float x;
		float y;
		float z; // For layer differentiation.
		float frametime;
		int curFrame;
		
		int vertArray;
		int locationBO;
		int uvBO;
};