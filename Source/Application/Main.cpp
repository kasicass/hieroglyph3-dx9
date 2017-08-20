//--------------------------------------------------------------------------------
// This file is a portion of the Hieroglyph 3 Rendering Engine.  It is distributed
// under the MIT License, available in the root of this distribution and 
// at the following URL:
//
// http://www.opensource.org/licenses/mit-license.php
//
// Copyright (c) 2003-2010 Jason Zink
//--------------------------------------------------------------------------------

#include "PCH.h"
#include "Application.h"
#include "Log.h"

using namespace Glyph3;

int WINAPI WinMain(	HINSTANCE h_Inst, HINSTANCE h_PrevInst,	LPSTR lpcmdline, int ncmdshow)
{
	Application* pApp = Application::GetApplication();
	if (!pApp)
	{
		Log::Get().Write( L"There was no instance of the application." );
		return -1;
	}

	// Call the application's ConfigureEngineComponent method.  This will load
	// and create each of the engine components that are needed by the application,
	// as well as the windows that are needed for interacting with the user.

	if ( !pApp->ConfigureEngineComponents() )
	{
		pApp->ShutdownEngineComponents();
		return -1;
	}

	// Call the application initialize function - this function
	// will be overloaded specifically for each of the applications.
	
	pApp->Initialize();

    
	// Call the application message loop function - this function
	// could be overloaded specifically for each the applications.

	pApp->MessageLoop();


	// Call the overloaded application shutdown method.

	pApp->Shutdown();
	pApp->ShutdownEngineComponents();

	return 0;
}