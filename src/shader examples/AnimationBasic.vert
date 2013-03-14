/*
	This is a sample vertex shader for use with Animations.
	
	Here we see the uniform variables for the camera and position
	matrices, and how we must manipulate the incoming vertices
	with them for proper display.
	
	Texture manipulation for animation occurs in the fragment shader.
*/

// We use a lesser version of GLSL for compatiblility.
#version 300

// Declare entry data layout.
layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec2 inUV;

// Declare the uniform variables that we need for the 
// vertex shader.
uniform mat4 camera_matrix;
uniform mat4 location_matrix;

// Declare what we must send out to the fragment shader.
out vec2 texCoord;

// The main function of the vertex shader.
void main(void)
{
	// Perform matrix multiplication.
	vec4 translated_position = vec4(inPosition, 1);
	translated_position *= camera_matrix * location_matrix;
	gl_Position = translated_position;
	
	// Bind the incoming UV coordinates to our outgoing
	// variable being sent to the fragment shader.
	texCoord = inUV;
}


