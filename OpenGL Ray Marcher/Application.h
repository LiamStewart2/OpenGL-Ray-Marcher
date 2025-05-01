#pragma once

#include <glad/glad.h>
#include <glfw3.h>

#include <iostream>

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
};