#include "App.h"
#include "Log.h"

using namespace Glyph3;

App AppInstance;

App::App()
{
}

bool App::ConfigureEngineComponents()
{
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
}

void App::Shutdown()
{
	Log::Get().Write(L"Shutdown");
}

std::wstring App::GetName()
{
	return L"BasicApplication";
}
