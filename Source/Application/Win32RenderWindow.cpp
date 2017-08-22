//--------------------------------------------------------------------------------
// This file is a portion of the Hieroglyph 3 Rendering Engine.  It is distributed
// under the MIT License, available in the root of this distribution and 
// at the following URL:
//
// http://www.opensource.org/licenses/mit-license.php
//
// Copyright (c) 2003-2010 Jason Zink 
//--------------------------------------------------------------------------------
// 06.02.2012: Initialization of WNDCLASSEX structure to zero added by Francois
//             Piette.
//--------------------------------------------------------------------------------
#include "PCH.h"
#include "Win32RenderWindow.h"
//--------------------------------------------------------------------------------
using namespace Glyph3;
//--------------------------------------------------------------------------------
extern LRESULT CALLBACK WindowProc( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam );
//--------------------------------------------------------------------------------
Win32RenderWindow::Win32RenderWindow( )
{
	m_hWnd = 0;
}
//--------------------------------------------------------------------------------
Win32RenderWindow::~Win32RenderWindow()
{
	Shutdown();
}
//--------------------------------------------------------------------------------
// This free function is used as a hook into the window's messaging system.  When
// the window is initialized, the owner passes a pointer to a IWindowProc 
// implementation.  When Windows sends a message to this window, we call this 
// handler function - which will either call the default processor (when no valid
// pointer is there) or call the IWindowProc method (when a valid one is 
// available).
//--------------------------------------------------------------------------------
LRESULT CALLBACK InternalWindowProc( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam )
{
	LONG ObjPtr = GetWindowLongPtr(hwnd, 0);

	if (ObjPtr == 0) {
        return( DefWindowProc( hwnd, msg, wparam, lparam ) );
	} else {
	    return( ((IWindowProc*)ObjPtr)->WindowProc(hwnd, msg, wparam, lparam) );
	}
}
//--------------------------------------------------------------------------------
void Win32RenderWindow::Initialize(IWindowProc* WindowProcObj)
{
	WNDCLASSEX wc;
	
	// Setup the window class
	memset(&wc,0, sizeof(wc));
	wc.cbSize			= sizeof(WNDCLASSEX);
	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		= InternalWindowProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= sizeof(WindowProcObj);
	wc.hInstance		= 0;
	wc.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW); 
	wc.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= L"HieroglyphWin32";
	wc.hIconSm			= LoadIcon(NULL, IDI_APPLICATION);
	
	// Register the window class
	RegisterClassEx(&wc);

	// Specify the window style
	m_dStyle = (WS_OVERLAPPEDWINDOW | WS_VISIBLE);
	

	// Record the desired device size
	RECT rc;
	rc.top = rc.left = 0;
	rc.right = m_iWidth;
	rc.bottom = m_iHeight;
	
	// Adjust the window size for correct device size
	AdjustWindowRect(&rc, m_dStyle, FALSE);

	long lwidth = rc.right - rc.left;
	long lheight = rc.bottom - rc.top;

	long lleft = (long)m_iLeft;	
	long ltop = (long)m_iTop;


	// Create an instance of the window
	m_hWnd = CreateWindowEx(
		NULL,							// extended style
		wc.lpszClassName, 				// class name
		m_sCaption.c_str(),				// instance title
		m_dStyle,						// window style
		lleft, ltop,					// initial x, y
		lwidth,							// initial width
		lheight,						// initial height
		NULL,							// handle to parent 
		NULL,							// handle to menu
		NULL,							// instance of this application
		NULL );							// extra creation parms
	
	if (m_hWnd) {
		// Set in the "extra" bytes the pointer to the IWindowProc object
		// which handles messages for the window
        SetWindowLong(m_hWnd, 0, (LONG)WindowProcObj);
    	// Initially display the window
		ShowWindow( m_hWnd, SW_SHOWNORMAL );
		UpdateWindow( m_hWnd );
	}
}
//--------------------------------------------------------------------------------
void Win32RenderWindow::Shutdown()
{
	if ( m_hWnd )
		DestroyWindow( m_hWnd );

	m_hWnd = 0;
}
//--------------------------------------------------------------------------------
void Win32RenderWindow::Paint()
{
	
}
//--------------------------------------------------------------------------------