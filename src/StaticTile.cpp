#include "StaticTile.h"

StaticTile::StaticTile(void)
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
}

StaticTile::~StaticTile(void)
{
	glDeleteBuffers(1, &locationBO);
	glDeleteBuffers(1, &uvBO);
	glDeleteArrays(1, &vertArray);
}

bool StaticTile::init(GLTexture * texture, GLCamera * camera, ShaderProgram * shaderProgram, 
				unsigned int newID)
{
	this->texture = texture;
	this->frameTime = frameTime;
	this->numFrames = numFrames;
	this->shader = shaderProgram;
	this->id = newID;
	
	initVerts();
	return (vertArray != 999999) && (locationBO != 999999) && (uvBO != 999999);
}

bool StaticTile::init(GLTexture * texture, GLCamera * camera, ShaderProgram * shaderProgram, 
					float locX, float locY, float locZ, float width, float height, 
					unsigned int newID)
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

void StaticTile::draw(void)
{
	texture->bindTexture();
	
	GLuint uniformLocation = 99999;
	
	glm::mat4 modelScale = glm::scale(glm::mat4(1.0f), glm::vec3(width, height, 1.0f));
	glm::mat4 modelTranslation = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
	glm::mat4 modelScaleAndTranslation = modelScale * modelTranslation;
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "model_matrix");
	glUniformMat4fv(uniformLocation, modelScaleAndTranslation);
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "camera_matrix");
	glUniformMat4fv(uniformLocation, camera->getCameraMatrix());	
	
	shader->useProgram();
	
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glBindVertexArray(0);
	shader->useProgram();
}

void StaticTile::draw(float x, float y, float z)
{
	texture->bindTexture();
	
	GLuint uniformLocation = 99999;
	
	glm::mat4 modelScale = glm::scale(glm::mat4(1.0f), glm::vec3(width, height, 1.0f));
	glm::mat4 modelTranslation = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
	glm::mat4 modelScaleAndTranslation = modelScale * modelTranslation;
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "model_matrix");
	glUniformMat4fv(uniformLocation, modelScaleAndTranslation);
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "camera_matrix");
	glUniformMat4fv(uniformLocation, camera->getCameraMatrix());	
	
	shader->useProgram();
	
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glBindVertexArray(0);
	shader->useProgram();
}

void StaticTile::void draw(float x, float y, float z, float width, float height)
{
	texture->bindTexture();
	
	GLuint uniformLocation = 99999;
	
	glm::mat4 modelScale = glm::scale(glm::mat4(1.0f), glm::vec3(width, height, 1.0f));
	glm::mat4 modelTranslation = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
	glm::mat4 modelScaleAndTranslation = modelScale * modelTranslation;
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "model_matrix");
	glUniformMat4fv(uniformLocation, modelScaleAndTranslation);
	
	uniformLocation = glGetUniformLocation(shader->getProgramID(), "camera_matrix");
	glUniformMat4fv(uniformLocation, camera->getCameraMatrix());	
	
	shader->useProgram();
	
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glBindVertexArray(0);
	shader->useProgram();
}

void StaticTile::setTexture(GLTexture * newTexture)
{
	texture = newTexture;
}

GLTexture * StaticTile::getTexture(void)
{
	return texture;
}

void StaticTile::setShader(ShaderProgram * newProgram)
{
	shader = newProgram;
}

ShaderProgram * StaticTile::getShader(void)
{
	return shader;
}

GLCamera * StaticTile::getCamera(void)
{
	return camera;
}

void StaticTile::setCamera(GLCamera * newCamera)
{
	camera = newCamera;
}

void StaticTile::initVerts(void)
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