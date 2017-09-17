#include <d3dcompiler.h>
#include "Shaders.hpp"
#include "Utility.hpp"
using Gandiva::Graphics::Shader;
using Gandiva::Graphics::ShaderType;

const std::string Shader::VERTEX_SHADER_VERSION = "vs_5_0";
const std::string Shader::PIXEL_SHADER_VERSION = "ps_5_0";
const std::string Shader::VERTEX_SHADER_FUNCTION = "VSMain";
const std::string Shader::PIXEL_SHADER_FUNCTION = "PSMain";

Shader::Shader(std::wstring shaderFile)
	: m_shaderFilename(shaderFile)
	, m_vertexShader(nullptr)
	, m_pixelShader(nullptr)
{

}

Shader::~Shader()
{

}

void Shader::load(ShaderType type)
{
#ifdef _DEBUG
	// Enable better shader debugging with the graphics debugging tools.
	UINT compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#else
	UINT compileFlags = 0;
#endif

	if (type == VERTEX_SHADER)
	{
		ThrowIfFailed(D3DCompileFromFile(m_shaderFilename.c_str(), nullptr, nullptr, VERTEX_SHADER_FUNCTION.c_str(), VERTEX_SHADER_VERSION.c_str(), compileFlags, 0, &m_vertexShader, nullptr));
	}
	else if (type == PIXEL_SHADER)
	{
		ThrowIfFailed(D3DCompileFromFile(m_shaderFilename.c_str(), nullptr, nullptr, PIXEL_SHADER_FUNCTION.c_str(), PIXEL_SHADER_VERSION.c_str(), compileFlags, 0, &m_pixelShader, nullptr));
	}
}