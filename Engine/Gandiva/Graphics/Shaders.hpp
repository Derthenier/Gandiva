#pragma once

#ifndef _GANDIVA_VERSION_1_SHADER_HPP_
#define _GANDIVA_VERSION_1_SHADER_HPP_

#ifdef GANDIVA_EXPORTS
#ifndef GANDIVA_DLL_API
#define GANDIVA_DLL_API  __declspec(dllexport)
#endif
#else
#ifndef GANDIVA_DLL_API
#define GANDIVA_DLL_API __declspec(dllimport)
#endif
#endif

#include <wrl.h>
#include <d3d12.h>
#include <string>
using Microsoft::WRL::ComPtr;

namespace Gandiva
{
	namespace Graphics
	{
		enum GANDIVA_DLL_API ShaderType
		{
			VERTEX_SHADER,
			PIXEL_SHADER,

			NUM_SHADER_TYPES
		};

		class GANDIVA_DLL_API Shader
		{
		public:
			Shader(std::wstring shaderFile);
			virtual ~Shader();

			static const std::string VERTEX_SHADER_VERSION;
			static const std::string PIXEL_SHADER_VERSION;
			static const std::string VERTEX_SHADER_FUNCTION;
			static const std::string PIXEL_SHADER_FUNCTION;

			void load(ShaderType type);
		private:
			std::wstring m_shaderFilename;
			ComPtr<ID3DBlob> m_vertexShader;
			ComPtr<ID3DBlob> m_pixelShader;
		};
	}
}

#endif // _GANDIVA_VERSION_1_SHADER_HPP_
