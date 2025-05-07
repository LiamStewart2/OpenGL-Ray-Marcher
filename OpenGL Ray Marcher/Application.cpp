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

	window = glfwCreateWindow(1080, 720, "Window", NULL, NULL);

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

	testShader = Shader("Resources/Shaders/TestShader/testShader.vs", "Resources/Shaders/TestShader/testShader.fs");

	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);

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

	testShader.useShader();

	testShader.setFloat("timePassed", glfwGetTime());

	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(window);
}

void Application::Kill()
{
	glfwTerminate();
	return;
}
