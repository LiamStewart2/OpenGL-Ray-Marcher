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
	if (!glfwInit())
		return;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(640, 480, "Window", NULL, NULL);

	if (!window)
	{
		std::cerr << "[INIT] window init failed" << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "[INIT] GLAD init failed" << std::endl;
		return;
	}

	Mainloop();
}

void Application::Mainloop()
{
	while (!glfwWindowShouldClose(window))
	{
		HandleEvents();
		Update();
		Render();

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
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window);
}

void Application::Kill()
{
	glfwTerminate();
	return;
}
