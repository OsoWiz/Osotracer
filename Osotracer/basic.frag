#ifdef SHADER_SOURCE
std::string fragmentShaderSource = R"(
#endif

layout(location = 0) in vec3 fragNormal;

layout(location=0) out vec4 outColor;

void main()
{
	outColor = vec4(0.0, 1.0, 0.0, 1.0);
}

#ifdef SHADER_SOURCE
)";
#endif