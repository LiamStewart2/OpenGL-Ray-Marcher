#include "Application.h"

Application::Application()
{
	Init();
}

Application::~Application()
{
}

void Application::Init()
{
	if(!glfwInit())
		return;

	window = glfwCreateWindow(640, 480, "Window", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	Mainloop();
}

void Application::Mainloop()
{
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	Kill();
}

void Application::HandleEvents()
{
}

void Application::Update()
{
}

void Application::Render()
{
}

void Application::Kill()
{
	glfwTerminate();
	return;
}
