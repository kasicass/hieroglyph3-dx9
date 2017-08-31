#include "App.h"
#include "Log.h"

using namespace Glyph3;

App AppInstance;

App::App()
{
}

bool App::ConfigureEngineComponents()
{
	// The application currently supplies the 
	int width = 640;
	int height = 480;
	bool windowed = true;

	// Set the render window parameters and initialize the window
	m_pWindow = new Win32RenderWindow();
	m_pWindow->SetPosition( 25, 25 );
	m_pWindow->SetSize( width, height );
	m_pWindow->SetCaption( GetName() );
	m_pWindow->Initialize( this );

	m_pRenderer9 = new RendererDX9();
	if (!m_pRenderer9->Initialize(width, height, windowed, m_pWindow->GetHandle()))
	{
		ShowWindow( m_pWindow->GetHandle(), SW_HIDE );
		MessageBox( m_pWindow->GetHandle(), L"Could not create a hardware or software Direct3D 11 device - the program will now abort!", L"Hieroglyph 3 Rendering", MB_ICONEXCLAMATION | MB_SYSTEMMODAL );
		RequestTermination();			
		return false;
	}

	return true;
}

void App::ShutdownEngineComponents()
{
	if ( m_pRenderer9 )
	{
		m_pRenderer9->Shutdown();
		delete m_pRenderer9;
	}

	if ( m_pWindow )
	{
		m_pWindow->Shutdown();
		delete m_pWindow;
	}
}

void App::Initialize()
{
	Log::Get().Write(L"Initialize.");
}

void App::Update()
{
	m_pTimer->Update();

	m_pRenderer9->Clear();
	m_pRenderer9->Present();
}

void App::Shutdown()
{
	Log::Get().Write(L"Shutdown");
}

std::wstring App::GetName()
{
	return L"BasicApplication";
}
