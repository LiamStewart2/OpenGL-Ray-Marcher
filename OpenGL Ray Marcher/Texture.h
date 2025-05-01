#pragma once

#include <iostream>

#include <glad/glad.h>
#include <glfw3.h>

class Texture
{
public:
	void loadTexture(const char* textureFilePath);
	void useTexture();
	unsigned int textureID = 0;
	int width = 0; int height = 0; int nrChannels = 0;
};