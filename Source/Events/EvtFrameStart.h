//--------------------------------------------------------------------------------
// This file is a portion of the Hieroglyph 3 Rendering Engine.  It is distributed
// under the MIT License, available in the root of this distribution and 
// at the following URL:
//
// http://www.opensource.org/licenses/mit-license.php
//
// Copyright (c) 2003-2010 Jason Zink 
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// EvtFrameStart
//
//--------------------------------------------------------------------------------
#ifndef EvtFrameStart_h
#define EvtFrameStart_h
//--------------------------------------------------------------------------------
#include "IEvent.h"
//--------------------------------------------------------------------------------
namespace Glyph3
{
	class EvtFrameStart : public IEvent
	{
	public:
		EvtFrameStart( float dt );
		virtual ~EvtFrameStart( );

		virtual std::wstring GetEventName( );
		virtual eEVENT GetEventType( );

		float GetElapsed();

	protected:
		float m_fDelta;
	};

};
//--------------------------------------------------------------------------------
#endif // EvtFrameStart_h
