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