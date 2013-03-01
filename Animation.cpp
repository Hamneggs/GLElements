#include "Animation.h"

Animation::Animation(void)
{
	x = 0;
	y = 0;
	z = 0;
	width = 0;
	height = 0;
	numFrames = 0;
	startTime = 0;
	curTime = 0;
	curFrame = 0;
	vertArray = 0;
	locationBO = 0;
	uvBO = 0;
	texture = NULL;
	shader = NULL;
	advanceMode = 0;
}

Animation::~Animation(void)
{
}

bool Animation::init(GLTexture * texture, float frameTime, int numFrames, ShaderProgram * shaderProgram)
{
	this->texture = texture;
	this->frameTime = frameTime;
	this->numFrames = numFrames;
	this->shader = shaderProgram;
	
	initVerts();
}

bool Animation::init(GLTexture * texture, float frameTime, int numFrames, float locX, float locY, float locZ, float width, float height, ShaderProgram shaderProgram
{
	this->texture = texture;
	this->frameTime = frameTime;
	this->numFrames = numFrames;
	this->shader = shaderProgram;
	this->x = locX;
	this->y = locY;
	this->z = locZ;
	this->width = width;
	this->height = height;
	
	initVerts();
}

void Animation::draw(void)
{
	texture->bindTexture();
	
	GLuint sampleLocation = 99999;
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "x");
	glUniform1f(sampleLocation, x);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "y");
	glUniform1f(sampleLocation, y);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "z");
	glUniform1f(sampleLocation, z);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "width");
	glUniform1f(sampleLocation, width);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "height");
	glUniform1f(sampleLocation, height);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "cur_frame");
	glUniform1i(sampleLocation, height);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "num_frames");
	glUniform1i(sampleLocation, height);
	
	shader->useProgram();
	
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glBindVertexArray(0);
	shader->useProgram();
}

void Animation::draw(float x, float y, float z)
{
	texture->bindTexture();
	
	GLuint sampleLocation = 99999;
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "x");
	glUniform1f(sampleLocation, x);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "y");
	glUniform1f(sampleLocation, y);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "z");
	glUniform1f(sampleLocation, z);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "width");
	glUniform1f(sampleLocation, width);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "height");
	glUniform1f(sampleLocation, height);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "cur_frame");
	glUniform1i(sampleLocation, height);
	sampleLocation = glGetUniformLocation(shader->getProgramID(), "num_frames");
	glUniform1i(sampleLocation, height);
	
	
	shader->useProgram();
	
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glBindVertexArray(0);
	shader->useProgram();
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
	return x;
}

float Animation::getY(void)
{
	return y;
}

float Animation::getZ(void)
{
	return z;
}

float Animation::getWidth(void)
{
	return width;
}

float Animation::getHeight(void)
{
	return height;
}

void Animation::forceSetFrame(int index)
{
	curFrame = index%numFrames;
}

void Animation::forceUpdateFrame(void)
{
	curFrame++;
	curFrame %= numFrames;
}

int Animation::getCurrentFrame(void)
{
	return curFrame;
}

void Animation::resetTimer(void)
{
	#ifdef _WIN32
	// Now this is nice and easy.
	DWORD currentTime = getTickCount();
	startTime = (unsigned int)currentTime;
	curTime = (unsigned int)currentTime;
	
	#else
	// This isn't really.
	timeval timeValue;
	gettimeofday(timeValue, NULL);
	startTime = (unsigned int)timeValue.Milliseconds;
	curTime = (unsigned int)timeValue.Milliseconds;
	
	#endif
	
}

void Animation::setFrameTime(float newFrameTime)
{
	frameTime = newFrameTime;
}

void Animation::changeFrameTime(float changeFrameTime)
{
	frameTime += changeFrameTime;
}

float Animation::getFrameTime(void)
{
	return frameTime;
}

void Animation::setNumFrames(int newNumFrames)
{
	numFrames = newNumFrames;
}

int Animation::getNumFrames(void)
{
	return numFrames;
}

void Animation::setTexture(GLTexture * newTexture)
{
	texture = newTexture;
}

GLTexture * Animation::getTexture(void)
{
	return texture;
}

void Animation::setShader(ShaderProgram * newProgram)
{
	shader = newProgram;
}

ShaderProgram * Animation::getShader(void)
{
	return shader;
}

ADVANCE_MODE Animation::getAdvanceMode(void)
{
	return advanceMode;
}

void Animation::setAdvanceMode(ADVANCE_MODE newMode)
{
	advanceMode = newMode;
}

void Animation::initVerts(void)
{
	
	// Create an array to store the vertices.
	float * verts = (float *) malloc(sizeof(float)*12);

	// Create all the vertex locations.
	verts[0]  = 0;
	verts[1]  = 1;
	verts[2]  = 0;

	verts[3]  = 0;
	verts[4]  = 0;
	verts[5]  = 0;

	verts[6]  = 1;
	verts[7]  = 1;
	verts[8]  = 0;

	verts[9]  = 1;
	verts[10] = 0;
	verts[11] = 0;

	// Create an array to store the vertex UV coordinates.
	float * uv = (float * ) malloc(sizeof(float)*8);

	// Create all the UV coordinates.
	uv[0] = 0.0f;
	uv[1] = 0.0f;

	uv[2] = 0.0f;
	uv[3] = 1.0f;

	uv[4] = 1.0f;
	uv[5] = 0.0f;

	uv[6] = 1.0f;
	uv[7] = 1.0f;
	
	glGenVertexArrays(1, &vertArray);
	glGenBuffers(1, &locationBO);
	glGenBuffers(1, &uvBO);

	glBindBuffer(GL_ARRAY_BUFFER, vboHandles[0]);
	
	glBufferData(GL_ARRAY_BUFFER, 12*sizeof(float), verts, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vboHandles[1]);
	glBufferData(GL_ARRAY_BUFFER, 8*sizeof(float), uv, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
	free(verts);
	free(uv);
}
