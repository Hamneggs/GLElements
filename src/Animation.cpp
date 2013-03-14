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
	vertArray = 999999;
	locationBO = 999999;
	uvBO = 999999;
	texture = NULL;
	shader = NULL;
	advanceMode = 0;
}

Animation::~Animation(void)
{
	glDeleteBuffers(1, &locationBO);
	glDeleteBuffers(1, &uvBO);
	glDeleteArrays(1, &vertArray);
}

bool Animation::init(GLTexture * texture, GLCamera * camera, ShaderProgram * shaderProgram, 
						float frameTime, int numFrames, unsigned int newID)
{
	this->texture = texture;
	this->frameTime = frameTime;
	this->numFrames = numFrames;
	this->shader = shaderProgram;
	this->id = newID;
	
	initVerts();
	return (vertArray != 999999) && (locationBO != 999999) && (uvBO != 999999);
}

bool Animation::init(GLTexture * texture, GLCamera * camera, ShaderProgram * shaderProgram, 
					float frameTime, int numFrames, float locX, float locY, float locZ, 
					float width, float height, unsigned int newID)
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
	this->id = newID;
	
	initVerts();
	return (vertArray != 999999) && (locationBO != 999999) && (uvBO != 999999);
}

void Animation::draw(void)
{

	if(advanceMode == PASSIVE_ADVANCE)
	{
		updateTimer();
	}	
	
	texture->bindTexture();
	
	GLuint uniformLocation = 99999;
	
	glm::mat4 modelScale = glm::scale(glm::mat4(1.0f), glm::vec3(width, height, 1.0f));
	glm::mat4 modelTranslation = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
	glm::mat4 modelScaleAndTranslation = modelScale * modelTranslation;
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "model_matrix");
	glUniformMat4fv(uniformLocation, modelScaleAndTranslation);
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "camera_matrix");
	glUniformMat4fv(uniformLocation, camera->getCameraMatrix());
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "cur_frame");
	glUniform1i(uniformLocation, curFrame);
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "num_frames");
	glUniform1i(uniformLocation, numFrames);
	
	
	
	shader->useProgram();
	
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glBindVertexArray(0);
	shader->useProgram();
}

void Animation::draw(float x, float y, float z)
{
	if(advanceMode == PASSIVE_ADVANCE)
	{
		updateTimer();
	}		
		
	texture->bindTexture();
	
	GLuint uniformLocation = 99999;
	
	glm::mat4 modelScale = glm::scale(glm::mat4(1.0f), glm::vec3(width, height, 1.0f));
	glm::mat4 modelTranslation = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
	glm::mat4 modelScaleAndTranslation = modelScale * modelTranslation;
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "model_matrix");
	glUniformMat4fv(uniformLocation, modelScaleAndTranslation);
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "camera_matrix");
	glUniformMat4fv(uniformLocation, camera->getCameraMatrix());
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "cur_frame");
	glUniform1i(uniformLocation, curFrame);
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "num_frames");
	glUniform1i(uniformLocation, numFrames);
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "anim_sampler");
	
	
	
	shader->useProgram();
	
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glBindVertexArray(0);
	shader->useProgram();
}

void Animation::void draw(float x, float y, float z, float width, float height)
{
	if(advanceMode == PASSIVE_ADVANCE)
	{
		updateTimer();
	}		
		
	texture->bindTexture();
	
	GLuint uniformLocation = 99999;
	
	glm::mat4 modelScale = glm::scale(glm::mat4(1.0f), glm::vec3(width, height, 1.0f));
	glm::mat4 modelTranslation = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
	glm::mat4 modelScaleAndTranslation = modelScale * modelTranslation;
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "model_matrix");
	glUniformMat4fv(uniformLocation, modelScaleAndTranslation);
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "camera_matrix");
	glUniformMat4fv(uniformLocation, camera->getCameraMatrix());
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "cur_frame");
	glUniform1i(uniformLocation, curFrame);
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "num_frames");
	glUniform1i(uniformLocation, numFrames);
	
	uniformLocation = glGetuniformLocation(shader->getProgramID(), "anim_sampler");
	glUniform1i(uniformLocation, texture->getSamplerID());
	
	
	shader->useProgram();
	
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glBindVertexArray(0);
	shader->useProgram();
}

void Animation::setLocation(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

void Animation::changeLocation(float changeX, float changeY, float changeZ)
{
	x += changeX;
	y += changeY;
	z += changeZ;
}

void Animation::setSize(float newWidth, float newHeight)
{
	width = newWidth;
	height = newHeight;
}

void Animation::changeSize(float changeWidth, float changeHeight)
{
	width += changeWidth;
	height += changeHeight;
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

unsigned int Animation::getID(void)
{
	return id;
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

GLCamera * Animation::getCamera(void)
{
	return camera;
}

void Animation::setCamera(GLCamera * newCamera)
{
	camera = newCamera;
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

	glBindVertexArray(vertArray);
	
	glBindBuffer(GL_ARRAY_BUFFER, &locationBO);
	
	glBufferData(GL_ARRAY_BUFFER, 12*sizeof(float), verts, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, &uvBO);
	glBufferData(GL_ARRAY_BUFFER, 8*sizeof(float), uv, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindVertexArray(0);
	
	free(verts);
	free(uv);
}

void Animation::updateTimer(void)
{
	#ifdef _WIN32
	// Now this is nice and easy.
	DWORD currentTime = getTickCount();
	curTime = (unsigned int)currentTime;
	
	#else
	// This isn't really.
	timeval timeValue;
	gettimeofday(timeValue, NULL);
	curTime = (unsigned int)timeValue.Milliseconds;
	
	#endif
	
	curFrame = (curTime-startTime)%( (unsigned int)(frameTime * 1000) );
	curFrame %= numFrames;
}
