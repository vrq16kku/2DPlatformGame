#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include "OBB.h"
#include <vector>
#include <Windows.h>
#include "Image_Loading/nvImage.h"
#include <gl\GL.h>
#include <gl\GLu.h>
#include <iostream>
#include <cstring>


using namespace std;

class GameCharacter
{
public:
	Point points[NUMVERTS];

	double XPla = 0.0;
	double Xspeed = 0.0;
	double XspeedInc = 1.5f;
	double oldXspeed = 0.0f;

	//for recording everything to do with textures
	GLuint textureID = 0;
	bool textureDirection = true;
	int numFrames = 0;
	int textureNumber = 0;

	double YPla = 0;
	double Yspeed = 0.0f;
	double YspeedInc = 7.5f;
	double oldYspeed = 0.0f;

	bool flash = false;
	bool collidingSpaceship = false;

	//variable for recording whether the character has collided with a platform or not
	bool areCollidingPlatform = true;
	OBB boundingBox;

	//variable for recording what type of collision the character is making with a platform
	std::vector<std::string> collisionStatuses = {};

	GameCharacter();
	void loadTexture(string texturePath);
	GLuint loadPNG(char* name);
	//First 8 coordinates are for the polygon
	void addPointsandDraw(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float p4x, float p4y);
	virtual void updatePlayerMovement(double dt) = 0;
	virtual void resetCharacter() = 0;
	void createOBB(float matrix[16]);
	void drawOBB(void);
	~GameCharacter();
	
};
#endif
