#include "Application.hpp"
using Gandiva::Core::Application;

LRESULT CALLBACK Application::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

Application::Application()
	: m_renderer(nullptr)
{
}


Application::~Application()
{
	if (m_renderer != nullptr)
	{
		m_renderer->cleanup();
		delete m_renderer;
		m_renderer = nullptr;
	}
}

int Application::initialize(HINSTANCE hInstance, std::wstring title, int cmdShow)
{

	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WindowProc;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = title.c_str();

	if (!RegisterClassEx(&wndClass))
	{
		return -1;
	}

	RECT rc = { 0, 0, 640, 480 };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	m_window = CreateWindow(title.c_str(),
		title.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		rc.right - rc.left,
		rc.bottom - rc.top,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!m_window)
	{
		return -1;
	}

	ShowWindow(m_window, cmdShow);

	RECT dimensions;
	GetClientRect(m_window, &dimensions);
	unsigned int width = dimensions.right - dimensions.left;
	unsigned int height = dimensions.bottom - dimensions.top;

	m_renderer = new Graphics::Renderer();
	m_renderer->initialize(m_window, width, height, false);

	return 0;
}

void Application::cleanup()
{
	if (m_renderer != nullptr)
	{
		m_renderer->cleanup();
	}
}

int Application::run()
{
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			update();
			render();
		}
	}

	cleanup();
	return static_cast<int>(msg.wParam);
}