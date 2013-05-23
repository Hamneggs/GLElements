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

// The texture of the Static Tile, stored in a sampler object.
uniform sampler2D tex_sampler;

// The main (and sole) function of the fragment shader.
void main(void)
{	
	// Send out the interpolated texel of the StaticTile's texture.
	finalColor = texture(texCoord, texCoord);
}