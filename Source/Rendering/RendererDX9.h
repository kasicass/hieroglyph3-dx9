#pragma once

#include "PCH.h"

#include "IRenderer.h"

namespace Glyph3
{


	class RendererDX9 : public IRenderer
	{
	public:
		RendererDX9();
		virtual ~RendererDX9();

		virtual bool Initialize( int w, int h, bool windowed, HWND handle ) override;
		virtual void Shutdown() override;
		virtual void Present() override;

		void Clear();

	private:
		IDirect3D9* m_pD3D;
		D3DPRESENT_PARAMETERS m_d3dPP;
		IDirect3DDevice9 *m_pD3DDevice9;
	};

}