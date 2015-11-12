/*
The zlib/libpng License

Copyright (c) 2005-2007 Phillip Castaneda (pjcast -- www.wreckedgames.com)
Copyright (c) 2015		Giovanni Zito

This software is provided 'as-is', without any express or implied warranty. In no event will
the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial
applications, and to alter it and redistribute it freely, subject to the following
restrictions:

    1. The origin of this software must not be misrepresented; you must not claim that
		you wrote the original software. If you use this software in a product,
		an acknowledgment in the product documentation would be appreciated but is
		not required.

    2. Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.

    3. This notice may not be removed or altered from any source distribution.
*/
#include "marmalade/MarmaladeMouse.h"
#include "marmalade/MarmaladeInputManager.h"
#include "OISException.h"
#include "OISEvents.h"

using namespace OIS;

//--------------------------------------------------------------------------------------------------//
MarmaladeMouse::MarmaladeMouse( InputManager* creator, bool buffered )
	: Mouse(creator->inputSystemName(), buffered, 0, creator)
{
	static_cast<MarmaladeInputManager*>(mCreator)->_setMouseUsed(true);
}

//--------------------------------------------------------------------------------------------------//
void MarmaladeMouse::_initialize()
{
	s3ePointerRegister(S3E_POINTER_BUTTON_EVENT, (s3eCallback)&MarmaladeInputManager::_pointerButtonCallback, this);
	s3ePointerRegister(S3E_POINTER_MOTION_EVENT, (s3eCallback)&MarmaladeInputManager::_pointerMotionCallback, this);
}

//--------------------------------------------------------------------------------------------------//
MarmaladeMouse::~MarmaladeMouse()
{
	s3ePointerUnRegister(S3E_POINTER_BUTTON_EVENT, (s3eCallback)&MarmaladeInputManager::_pointerButtonCallback);
	s3ePointerUnRegister(S3E_POINTER_MOTION_EVENT, (s3eCallback)&MarmaladeInputManager::_pointerMotionCallback);

	MarmaladeInputManager *man = static_cast<MarmaladeInputManager*>(mCreator);
	man->_setMouseUsed(false);
}

//--------------------------------------------------------------------------------------------------//
void MarmaladeMouse::capture()
{
}

//--------------------------------------------------------------------------------------------------//
void MarmaladeMouse::setBuffered(bool buffered)
{
	mBuffered = buffered;
}

void MarmaladeMouse::_mousePressed(s3ePointerEvent *touch)
{
	// Record touch (for touchMoved event)
	mPosHistory = LastPos(touch->m_x, touch->m_y);

	MouseState newState;
	newState.X.abs = touch->m_x;
	newState.Y.abs = touch->m_y;
	newState.buttons |= 1 << touch->m_Button;

	if( mListener && mBuffered )
	{
		mListener->mousePressed(MouseEvent(this, newState),(MouseButtonID)touch->m_Button);
	}
	else
	{
		mState = newState;
	}
}

void MarmaladeMouse::_mouseReleased(s3ePointerEvent *touch)
{
	MouseState newState;
	newState.X.abs = touch->m_x;
	newState.Y.abs = touch->m_y;
	newState.buttons &= ~(1 << touch->m_Button);

	if( mListener && mBuffered )
	{
		mListener->mouseReleased(MouseEvent(this, newState),(MouseButtonID)touch->m_Button);
	}
	else
	{
		mState = newState;
	}
}

void MarmaladeMouse::_mouseMoved(s3ePointerMotionEvent *touch)
{
	LastPos previousLocation = mPosHistory;

	MouseState newState;
	newState.X.rel = (touch->m_x - previousLocation.x);
	newState.Y.rel = (touch->m_y - previousLocation.y);
	newState.X.abs = touch->m_x;
	newState.Y.abs = touch->m_y;

	if( mListener && mBuffered )
	{
		mListener->mouseMoved(MouseEvent(this, newState));
	}
	else
	{
		mState = newState;
	}
}

