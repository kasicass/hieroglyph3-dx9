#include "Application.h"

using namespace Glyph3;

Application* Application::ms_pApplication = NULL;

Application::Application()
{
	ms_pApplication = this;
}

Application::~Application()
{
}

Application* Application::GetApplication()
{
	return ms_pApplication;
}

void Application::MessageLoop()
{
	MSG msg;
	bool bLoop = true;

	while (bLoop)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message = WM_QUIT)
			{
				bLoop = false;
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// Call the overloaded application update function
		Update();
	}
}

LRESULT Application::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	return 0;
}
