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

LRESULT Application::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	return 0;
}
