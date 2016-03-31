#pragma once

#include <glbinding/Binding.h>
#include <glbinding/gl/gl.h>
using namespace gl;

#include <glm/glm.hpp>

enum class ShaderType
{
	VERTEX   = static_cast<GLuint>(GL_VERTEX_SHADER),
	TESSCRTL = static_cast<GLuint>(GL_TESS_CONTROL_SHADER),
	TESSEVAL = static_cast<GLuint>(GL_TESS_EVALUATION_SHADER),
	GEOMETRY = static_cast<GLuint>(GL_GEOMETRY_SHADER),
	FRAGMENT = static_cast<GLuint>(GL_FRAGMENT_SHADER),
};

class Shader
{
public:
	Shader(ShaderType type, const std::string& sourceFile);

    GLuint shaderID();

private:
	bool _compileShader();

	ShaderType m_ShaderType;
	std::string m_ShaderSourceFile;
	std::string m_ShaderSource;
	GLuint m_ShaderID;
};

class Program
{
public:
    Program();

    void attach(Shader* shader);
    void link();
    
    void setUniform(const std::string& name, const glm::mat4& matrix);
    void setUniform(const std::string& name, const glm::vec3& vector);
    void setUniform(const std::string& name, float value);

    void bind();
    void unbind();

public:
	GLuint m_ProgramID;
};