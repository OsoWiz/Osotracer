#ifdef SHADER_SOURCE
std::string vertexShaderSource = R"(
#endif

#version 450

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

out vec3 fragNormal;
void main()
{
	gl_Position = vec4(position, 1.0);
}
#ifdef SHADER_SOURCE
)";
#endif