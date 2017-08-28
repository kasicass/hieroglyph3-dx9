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

	return true;
}

void App::ShutdownEngineComponents()
{
}

void App::Initialize()
{
	Log::Get().Write(L"Initialize.");
}

void App::Update()
{
	m_pTimer->Update();
}

void App::Shutdown()
{
	Log::Get().Write(L"Shutdown");
}

std::wstring App::GetName()
{
	return L"BasicApplication";
}
