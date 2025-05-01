#pragma once

#include <string>

#include <glad/glad.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtc/matrix_transform.hpp>

class Shader
{
public:
	Shader() { shaderID = 0; }
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader() {}

	unsigned int shaderID;
	void useShader();

	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMat4(const std::string& name, glm::mat4 value) const;

	void deleteShader();
private:
	void checkCompileErrors(unsigned int shader, std::string type);
};