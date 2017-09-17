#pragma once
#ifndef _GANDIVA_VERSION_1_APPLICATION_HPP_
#define _GANDIVA_VERSION_1_APPLICATION_HPP_

#ifdef GANDIVA_EXPORTS
#ifndef GANDIVA_DLL_API
#define GANDIVA_DLL_API  __declspec(dllexport)
#endif
#else
#ifndef GANDIVA_DLL_API
#define GANDIVA_DLL_API __declspec(dllimport)
#endif
#endif

#include <windows.h>
#include <string>
#include "..\Graphics\Renderer.hpp"

namespace Gandiva
{
	namespace Core
	{
		class GANDIVA_DLL_API Application
		{
		public:
			Application();
			virtual ~Application();

			int initialize(HINSTANCE hInstance, std::wstring title, int cmdShow);
			void cleanup();
			int run();

		protected:
			virtual void update(void) = 0;
			virtual void render(void) = 0;

			static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		private:
			HINSTANCE m_hInstance;
			HWND m_window;

			Graphics::Renderer* m_renderer;
		};
	}
}


#endif // _GANDIVA_VERSION_1_APPLICATION_HPP_