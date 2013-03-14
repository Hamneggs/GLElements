/*
	This is a sample fragment shader for use with Animations.
	
	Here we see the technique usedfor texture coordinate 
	manipulation.
*/

#version 300

// We must declare an outgoing vec4 for OpenGL to dump into 
// the current framebuffer.
out vec4 finalColor;

// Now we declare the incoming texture coordinate so that we
// can actually recieve it.
in vec2 texCoord;

// Next we declare the uniform variables that are used to
// actually perform the animation.
uniform int cur_frame;
uniform int num_frames;
uniform sampler2D anim_sampler;

// The main (and sole) function of the fragment shader.
void main(void)
{
	// Translate and scale the incoming X coordinate to the 
	// location within the texture of the current frame.
	vec2 animationPosition = vec2( (texCoord.x / float(num_frames) )* float(cur_frame) , texCoord.y); 
	
	// Send out the interpolated texel of the animation texture.
	finalColor = texture(anim_sampler, animationPosition);
}