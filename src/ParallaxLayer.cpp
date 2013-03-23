ParallaxLayer::ParallaxLayer
{
	camera = NULL;
	tile = NULL;
	moveScale = 0.0;
	updateAtDraw = true;
	prevX = 0.0;
	prevY = 0.0;
	prevZ = 0.0;
}

ParallaxLayer::~ParallaxLayer
{
	// Don't really need to do anything here.
}

bool ParallaxLayer::init(GLCamera * cameraToUse, ArtTile * tileToUse, float movementScale, bool updateAtDraw)
{
	camera = cameraTouse;
	tile = tileToUse;
	moveScale = movementScale;
	this->updateAtDraw = updateAtDraw;
	prevX = camera->getX();
	prevY = camera->getY();
	prevZ = camera->getZ(); 
	return (camera != NULL) && (tile != NULL);
}

void ParallaxLayer::setCamera(GLCamera * newCamera)
{
	camera = newCamera;
}

GLCamera * ParallaxLayer::getCamera(void)
{
	return camera;
}

void ParallaxLayer::setTile(ArtTile * newTile)
{
	tile = newTile;
}

ArtTile * ParallaxLayer::getTile(void)
{
	return tile;
}

void ParallaxLayer::setMovementScale(float newMovementScale)
{
	moveScale = newMovementScale;
}

void ParallaxLayer::changeMovementScale(float changeMovementScale)
{
	moveScale += changeMovementScale;
}

float ParallaxLayer::getMovementScale(void)
{
	return moveScale;
}

void ParallaxLayer::setAutoUpdate(bool newState)
{
	updateAtDraw = newState;
}

bool ParallaxLayer::getAutoUpdateState(void)
{	
	return updateAtDraw;
}

void ParallaxLayer::draw(void)
{
	if(updateAtDraw)
	{
		tile->changeLocation(camera->getX()-prevX, camera->getY()-prevY, camera->getZ()-prevZ);
		prevX = camera->getX();
		prevY = camera->getY();
		prevZ = camera->getZ();
	}
	tile->draw();
}

void ParallaxLayer::update(void)
{
	if(!updateAtDraw)
	{
		tile->changeLocation(camera->getX()-prevX, camera->getY()-prevY, camera->getZ()-prevZ);
		prevX = camera->getX();
		prevY = camera->getY();
		prevZ = camera->getZ();
	}
}

