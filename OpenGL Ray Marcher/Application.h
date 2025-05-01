#pragma once

#include <windows.h>
#include <gl/gl.h>
#include <glfw3.h>

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