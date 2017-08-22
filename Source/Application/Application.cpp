#include "Application.h"
#include "Log.h"

using namespace Glyph3;

Application* Application::ms_pApplication = NULL;

Application::Application()
{
	ms_pApplication = this;

	Log::Get().Open();
}

Application::~Application()
{
	Log::Get().Close();
}

Application* Application::GetApplication()
{
	return ms_pApplication;
}

void Application::RequestTermination()
{
	PostQuitMessage(0);
}

void Application::MessageLoop()
{
	MSG msg;
	bool bLoop = true;

	while (bLoop)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
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
	switch( msg )
	{	
		case WM_CREATE: 
			{
				// Automatically return 0 to allow the window to proceed in the
				// creation process.

				return( 0 );
			} break;

		case WM_PAINT:
			{
				// This message is handled by the default handler to avoid a 
				// repeated sending of the message.  This results in the ability
				// to process all pending messages at once without getting stuck
				// in an eternal loop.
			} break;

		case WM_CLOSE:
			{
				// This message is sent when a window or an application should
				// terminate.
			} break;

		case WM_DESTROY: 
			{
				// This message is sent when a window has been destroyed.

				PostQuitMessage(0);
				return( 0 );
			} break;

		case WM_SIZE:
			{				
                //EvtWindowResize* pEvent = new EvtWindowResize( hwnd, wparam, lparam );
                //EventManager::Get()->ProcessEvent( pEvent );
			} break;


		case WM_LBUTTONUP:
			{				
                //EvtMouseLButtonUp* pEvent = new EvtMouseLButtonUp( hwnd, wparam, lparam );
                //EventManager::Get()->ProcessEvent( pEvent );
			} break;

		case WM_LBUTTONDOWN:
			{
                //EvtMouseLButtonDown* pEvent = new EvtMouseLButtonDown( hwnd, wparam, lparam );
                //EventManager::Get()->ProcessEvent( pEvent );
			} break;
			
		case WM_MBUTTONUP:
			{
                //EvtMouseMButtonUp* pEvent = new EvtMouseMButtonUp( hwnd, wparam, lparam );
                //EventManager::Get()->ProcessEvent( pEvent );
			} break;

		case WM_MBUTTONDOWN:
			{
                //EvtMouseMButtonDown* pEvent = new EvtMouseMButtonDown( hwnd, wparam, lparam );
                //EventManager::Get()->ProcessEvent( pEvent );
			} break;

		case WM_RBUTTONUP:
			{
                //EvtMouseRButtonUp* pEvent = new EvtMouseRButtonUp( hwnd, wparam, lparam );
                //EventManager::Get()->ProcessEvent( pEvent );
			} break;

		case WM_RBUTTONDOWN:
			{
                //EvtMouseRButtonDown* pEvent = new EvtMouseRButtonDown( hwnd, wparam, lparam );
                //EventManager::Get()->ProcessEvent( pEvent );
			} break;

		case WM_MOUSEMOVE:
			{
                //EvtMouseMove* pEvent = new EvtMouseMove( hwnd, wparam, lparam );
                //EventManager::Get()->ProcessEvent( pEvent );
			} break;

		case WM_MOUSEWHEEL:
			{
                //EvtMouseWheel* pEvent = new EvtMouseWheel( hwnd, wparam, lparam );
                //EventManager::Get()->ProcessEvent( pEvent );
			} break;

		case WM_CHAR:
			{
				//EvtChar* pEvent = new EvtChar( hwnd, wparam, lparam );
				//EventManager::Get()->ProcessEvent( pEvent );
				//return( 0 );
			} break;

		case WM_KEYDOWN:
			{
				//EvtKeyDown* pEvent = new EvtKeyDown( hwnd, wparam, lparam );
				//EventManager::Get()->ProcessEvent( pEvent );
				//return( 0 );
			} break;

		case WM_KEYUP:
			{
				//EvtKeyUp* pEvent = new EvtKeyUp( hwnd, wparam, lparam );
				//EventManager::Get()->ProcessEvent( pEvent );
				//return( 0 );
			} break;
    }
    return( DefWindowProc( hwnd, msg, wparam, lparam ) );
}
