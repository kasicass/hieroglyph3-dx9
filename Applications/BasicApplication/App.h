#pragma once

#include "Application.h"
#include "Win32RenderWindow.h"

using namespace Glyph3;

class App : public Application
{
public:
	App();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Shutdown() override;

	virtual bool ConfigureEngineComponents() override;
	virtual void ShutdownEngineComponents() override;

	virtual std::wstring GetName();

protected:
	Win32RenderWindow*    m_pWindow;
};

