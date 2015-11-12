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
#include "Marmalade/MarmaladeAccelerometer.h"
#include "Marmalade/MarmaladeInputManager.h"
#include "Marmalade/MarmaladePrereqs.h"

using namespace OIS;

MarmaladeAccelerometer::MarmaladeAccelerometer(InputManager* creator, bool buffered)
	: JoyStick(creator->inputSystemName(), buffered, 0, creator)
{
	MarmaladeInputManager* man = static_cast<MarmaladeInputManager*>(creator);
	man->_setAccelerometerUsed(true);
}

MarmaladeAccelerometer::~MarmaladeAccelerometer()
{
	// Stop accelerometer
	s3eAccelerometerStop();
	
	MarmaladeInputManager *man = static_cast<MarmaladeInputManager*>(mCreator);
	man->_setAccelerometerUsed(false);
}

void MarmaladeAccelerometer::_initialize()
{
	// Clear old joy state
	mState.mVectors.resize(1);
	mState.clear();
	//mTempState.clear();
	
	// Start accelerometer
	if( s3eAccelerometerStart() != S3E_RESULT_SUCCESS )
	{
	
	}
}

void MarmaladeAccelerometer::setBuffered(bool buffered)
{
	mBuffered = buffered;
}

void MarmaladeAccelerometer::capture()
{
	mState.clear();
	mState.mVectors[0].x = (float)s3eAccelerometerGetX();
	mState.mVectors[0].y = (float)s3eAccelerometerGetY();
	mState.mVectors[0].z = (float)s3eAccelerometerGetZ();
	
	if(mListener && mBuffered)
        mListener->vector3Moved(JoyStickEvent(this, mState), 0);
}

bool MarmaladeAccelerometer::_isSupported()
{
	return (s3eAccelerometerGetInt(S3E_ACCELEROMETER_AVAILABLE) != S3E_FALSE);
}