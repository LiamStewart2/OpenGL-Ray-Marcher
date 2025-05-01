#pragma once

#include <glad/glad.h>
#include <glfw3.h>

#include <iostream>

#include "Shader.h"

class Application
{
public:
	Application();
	~Application();

private:
	void Init();

	void Mainloop();

	void HandleEvents();
	void Update();
	void Render();

	void Kill();

	GLFWwindow* window = nullptr;

	Shader testShader;

	float vertices[12] = {
	 0.5f,  0.5f, 0.0f,			// top right
	 0.5f, -0.5f, 0.0f,			// bottom right
	-0.5f, -0.5f, 0.0f,			// bottom left
	-0.5f,  0.5f, 0.0f			// top left 
	};
	unsigned int indices[6] = { 
		0, 1, 3,				// first triangle
		1, 2, 3					// second triangle
	};

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
};