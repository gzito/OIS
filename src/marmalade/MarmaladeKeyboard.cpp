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
#include "Marmalade/MarmaladeKeyboard.h"
#include "Marmalade/MarmaladeInputManager.h"
#include "OISException.h"
#include "OISEvents.h"
//#include <sstream>

namespace OIS
{

//-------------------------------------------------------------------//
MarmaladeKeyboard::MarmaladeKeyboard( InputManager* creator, bool buffered )
	: Keyboard(creator->inputSystemName(), buffered, 0, creator)
{
	mType = OISKeyboard;
	setBuffered( buffered );
	MarmaladeInputManager *man = static_cast<MarmaladeInputManager*>(mCreator);
	man->_setKeyboardUsed(true);
}

//-------------------------------------------------------------------//
void MarmaladeKeyboard::_initialize()
{
	mModifiers = 0;
	createKeyMap() ;
	createInverseKeyMap() ;
}

void MarmaladeKeyboard::createKeyMap()
{
	mKeyMap.insert( KeyMap::value_type(s3eKeyEsc,KC_ESCAPE) );
	mKeyMap.insert( KeyMap::value_type(s3eKey1, KC_1) );
	mKeyMap.insert( KeyMap::value_type(s3eKey2, KC_2) );
	mKeyMap.insert( KeyMap::value_type(s3eKey3, KC_3) );
	mKeyMap.insert( KeyMap::value_type(s3eKey4, KC_4) );
	mKeyMap.insert( KeyMap::value_type(s3eKey5, KC_5) );
	mKeyMap.insert( KeyMap::value_type(s3eKey6, KC_6) );
	mKeyMap.insert( KeyMap::value_type(s3eKey7, KC_7) );
	mKeyMap.insert( KeyMap::value_type(s3eKey8, KC_8) );
	mKeyMap.insert( KeyMap::value_type(s3eKey9, KC_9) );
	mKeyMap.insert( KeyMap::value_type(s3eKey0, KC_0) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyMinus, KC_MINUS) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyEquals, KC_EQUALS) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyBackspace, KC_BACK) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyTab, KC_TAB) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyQ, KC_Q) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyW, KC_W) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyE, KC_E) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyR, KC_R) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyT, KC_T) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyY, KC_Y) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyU, KC_U) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyI, KC_I) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyO, KC_O) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyP, KC_P) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyEnter, KC_RETURN) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyLeftControl, KC_LCONTROL));
	mKeyMap.insert( KeyMap::value_type(s3eKeyA, KC_A) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyS, KC_S) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyD, KC_D) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF, KC_F) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyG, KC_G) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyH, KC_H) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyJ, KC_J) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyK, KC_K) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyL, KC_L) );
	mKeyMap.insert( KeyMap::value_type(s3eKeySemicolon, KC_SEMICOLON) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyC, KC_COLON) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyApostrophe, KC_APOSTROPHE) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyBacktick, KC_GRAVE)  );
	mKeyMap.insert( KeyMap::value_type(s3eKeyLeftShift, KC_LSHIFT) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyBackSlash, KC_BACKSLASH) );
	mKeyMap.insert( KeyMap::value_type(s3eKeySlash, KC_SLASH) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyZ, KC_Z) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyX, KC_X) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyC, KC_C) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyV, KC_V) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyB, KC_B) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyN, KC_N) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyM, KC_M) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyComma, KC_COMMA)  );
	mKeyMap.insert( KeyMap::value_type(s3eKeyPeriod, KC_PERIOD));
	mKeyMap.insert( KeyMap::value_type(s3eKeyRightShift, KC_RSHIFT));
	mKeyMap.insert( KeyMap::value_type(s3eKeyStar, KC_MULTIPLY) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyLeftAlt, KC_LMENU) );
	mKeyMap.insert( KeyMap::value_type(s3eKeySpace, KC_SPACE));
	mKeyMap.insert( KeyMap::value_type(s3eKeyCapsLock, KC_CAPITAL) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF1, KC_F1) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF2, KC_F2) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF3, KC_F3) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF4, KC_F4) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF5, KC_F5) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF6, KC_F6) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF7, KC_F7) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF8, KC_F8) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF9, KC_F9) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF10, KC_F10) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumLock, KC_NUMLOCK) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyScrollLock, KC_SCROLL));
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPad8, KC_NUMPAD8) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPad8, KC_NUMPAD9) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPadMinus, KC_SUBTRACT) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPad4, KC_NUMPAD4) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPad5, KC_NUMPAD5) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPad6, KC_NUMPAD6) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPadPlus, KC_ADD) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPad1, KC_NUMPAD1) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPad2, KC_NUMPAD2) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPad3, KC_NUMPAD3) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPad0, KC_NUMPAD0) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPadPeriod, KC_DECIMAL) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF11, KC_F11) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyF12, KC_F12) );
	// 	mKeyMap.insert( KeyMap::value_type(SDLK_F13, KC_F13) );
	// 	mKeyMap.insert( KeyMap::value_type(SDLK_F14, KC_F14) );
	// 	mKeyMap.insert( KeyMap::value_type(SDLK_F15, KC_F15) );
	//	mKeyMap.insert( KeyMap::value_type(SDLK_KP_EQUALS, KC_NUMPADEQUALS) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyNumPadSlash, KC_DIVIDE) );
	//	mKeyMap.insert( KeyMap::value_type(SDLK_SYSREQ, KC_SYSRQ) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyRightAlt, KC_RMENU) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyHome, KC_HOME) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyUp, KC_UP) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyPageUp, KC_PGUP) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyLeft, KC_LEFT) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyRight, KC_RIGHT) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyEnd, KC_END) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyDown, KC_DOWN) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyPageDown, KC_PGDOWN) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyInsert, KC_INSERT) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyDelete, KC_DELETE) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyLeftWindows, KC_LWIN) );
	mKeyMap.insert( KeyMap::value_type(s3eKeyRightWindows, KC_RWIN) );
}


void MarmaladeKeyboard::createInverseKeyMap()
{
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_ESCAPE, s3eKeyEsc) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_1, s3eKey1) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_2, s3eKey2) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_3, s3eKey3) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_4, s3eKey4) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_5, s3eKey5) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_6, s3eKey6) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_7, s3eKey7) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_8, s3eKey8) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_9, s3eKey9) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_0, s3eKey0) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_MINUS, s3eKeyMinus) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_EQUALS, s3eKeyEquals) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_BACK, s3eKeyBackspace) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_TAB, s3eKeyTab) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_Q, s3eKeyQ) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_W, s3eKeyW) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_E, s3eKeyE) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_R, s3eKeyR) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_T, s3eKeyT) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_Y, s3eKeyY) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_U, s3eKeyU) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_I, s3eKeyI) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_O, s3eKeyO) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_P, s3eKeyP) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_RETURN, s3eKeyEnter) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_LCONTROL, s3eKeyLeftControl) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_A, s3eKeyA) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_S, s3eKeyS) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_D, s3eKeyD) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F, s3eKeyF) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_G, s3eKeyG) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_H, s3eKeyH) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_J, s3eKeyJ) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_K, s3eKeyK) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_L, s3eKeyL) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_SEMICOLON, s3eKeySemicolon ) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_COLON, s3eKeyC) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_APOSTROPHE, s3eKeyApostrophe) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_GRAVE, s3eKeyBacktick)  );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_LSHIFT, s3eKeyLeftShift) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_BACKSLASH, s3eKeyBackSlash) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_SLASH, s3eKeySlash) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_Z, s3eKeyZ) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_X, s3eKeyX) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_C, s3eKeyC) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_V, s3eKeyV) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_B, s3eKeyB) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_N, s3eKeyN) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_M, s3eKeyM) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_COMMA, s3eKeyComma)  );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_PERIOD, s3eKeyPeriod));
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_RSHIFT, s3eKeyRightShift));
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_MULTIPLY, s3eKeyStar) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_LMENU, s3eKeyLeftAlt) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_SPACE, s3eKeySpace));
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_CAPITAL, s3eKeyCapsLock) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F1, s3eKeyF1) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F2, s3eKeyF2) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F3, s3eKeyF3) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F4, s3eKeyF4) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F5, s3eKeyF5) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F6, s3eKeyF6) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F7, s3eKeyF7) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F8, s3eKeyF8) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F9, s3eKeyF9) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F10, s3eKeyF10) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_NUMLOCK, s3eKeyNumLock) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_SCROLL, s3eKeyScrollLock));
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_NUMPAD8, s3eKeyNumPad8) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_NUMPAD9, s3eKeyNumPad9) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_SUBTRACT, s3eKeyNumPadMinus) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_NUMPAD4, s3eKeyNumPad4) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_NUMPAD5, s3eKeyNumPad5) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_NUMPAD6, s3eKeyNumPad6) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_ADD, s3eKeyNumPadPlus) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_NUMPAD1, s3eKeyNumPad1) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_NUMPAD2, s3eKeyNumPad2) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_NUMPAD3, s3eKeyNumPad3) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_NUMPAD0, s3eKeyNumPad0) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_DECIMAL, s3eKeyNumPadPeriod) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F11, s3eKeyF11) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F12, s3eKeyF12) );
	// 	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F13, SDLK_F13) );
	// 	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F14, SDLK_F14) );
	// 	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_F15, SDLK_F15) );
	//		mInverseKeyMap.insert( InverseKeyMap::value_type(KC_NUMPADEQUALS, SDLK_KP_EQUALS) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_DIVIDE, s3eKeyNumPadSlash) );
	//		mInverseKeyMap.insert( InverseKeyMap::value_type(KC_SYSRQ, SDLK_SYSREQ) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_RMENU, s3eKeyRightAlt) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_HOME, s3eKeyHome) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_UP, s3eKeyUp) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_PGUP, s3eKeyPageUp) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_LEFT, s3eKeyLeft) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_RIGHT, s3eKeyRight) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_END, s3eKeyEnd) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_DOWN, s3eKeyDown) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_PGDOWN, s3eKeyPageDown) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_INSERT, s3eKeyInsert) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_DELETE, s3eKeyDelete) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_LWIN, s3eKeyLeftWindows) );
	mInverseKeyMap.insert( InverseKeyMap::value_type(KC_RWIN, s3eKeyRightWindows) );
}

//-------------------------------------------------------------------//
MarmaladeKeyboard::~MarmaladeKeyboard()
{
	MarmaladeInputManager *man = static_cast<MarmaladeInputManager*>(mCreator);
	man->_setKeyboardUsed(false);
}

//-------------------------------------------------------------------//
void MarmaladeKeyboard::capture()
{
	bool ret = true ;

	s3eKeyboardUpdate() ;

	int32 keyLeftControlState = s3eKeyboardGetState(s3eKeyLeftControl) ;
	int32 keyRightControlState = s3eKeyboardGetState(s3eKeyRightControl) ;
	int32 keyLeftShiftState = s3eKeyboardGetState(s3eKeyLeftShift) ;
	int32 keyRightShiftState = s3eKeyboardGetState(s3eKeyRightShift) ;
	int32 keyLeftAltState = s3eKeyboardGetState(s3eKeyLeftAlt) ;
	int32 keyRightAltState = s3eKeyboardGetState(s3eKeyRightAlt) ;

	if( keyLeftControlState == S3E_KEY_STATE_DOWN || keyLeftControlState == S3E_KEY_STATE_PRESSED ||
		keyRightControlState == S3E_KEY_STATE_DOWN || keyRightControlState == S3E_KEY_STATE_PRESSED )
		mModifiers |= Ctrl ;

	if( keyLeftShiftState == S3E_KEY_STATE_DOWN || keyLeftShiftState == S3E_KEY_STATE_PRESSED ||
		keyRightShiftState == S3E_KEY_STATE_DOWN || keyRightShiftState == S3E_KEY_STATE_PRESSED )
		mModifiers |= Shift ;

	if( keyLeftAltState == S3E_KEY_STATE_DOWN || keyLeftAltState == S3E_KEY_STATE_PRESSED ||
		keyRightAltState == S3E_KEY_STATE_DOWN || keyRightAltState == S3E_KEY_STATE_PRESSED )
		mModifiers |= Alt ;

	if( keyLeftControlState == S3E_KEY_STATE_UP || keyLeftControlState == S3E_KEY_STATE_RELEASED ||
		keyRightControlState == S3E_KEY_STATE_UP || keyRightControlState == S3E_KEY_STATE_RELEASED )
		mModifiers &= ~Ctrl ;

	if( keyLeftShiftState == S3E_KEY_STATE_UP || keyLeftShiftState == S3E_KEY_STATE_RELEASED ||
		keyRightShiftState == S3E_KEY_STATE_UP || keyRightShiftState == S3E_KEY_STATE_RELEASED )
		mModifiers &= ~Shift ;

	if( keyLeftAltState == S3E_KEY_STATE_UP || keyLeftAltState == S3E_KEY_STATE_RELEASED ||
		keyRightAltState == S3E_KEY_STATE_UP || keyRightAltState == S3E_KEY_STATE_RELEASED )
		mModifiers &= ~Alt ;
}

//-------------------------------------------------------------------//
bool MarmaladeKeyboard::isKeyDown( KeyCode key ) const 
{
	InverseKeyMap::const_iterator it = mInverseKeyMap.find(key) ;
	if( it == mInverseKeyMap.end() ) {
		return false ;
	}
	int32 state = s3eKeyboardGetState( it->second ) ;
	return (state == S3E_KEY_STATE_DOWN) || (state == S3E_KEY_STATE_PRESSED) ;
}

//-------------------------------------------------------------------//
const std::string& MarmaladeKeyboard::getAsString( KeyCode kc )
{
	InverseKeyMap::const_iterator it = mInverseKeyMap.find(kc) ;
	if( it != mInverseKeyMap.end() )
	{
		mGetString = getKeyName(it->second) ;
	}
	else
	{
		switch(kc)
		{
			case KC_OEM_102: mGetString = "OEM_102"; break;
			case KC_KANA: mGetString = "Kana"; break;
			case KC_ABNT_C1: mGetString = "ABNT_C1"; break;
			case KC_CONVERT: mGetString = "CONVERT"; break;
			case KC_NOCONVERT: mGetString = "NOCONVERT"; break;
			case KC_YEN: mGetString = "YEN"; break;
			case KC_ABNT_C2: mGetString = "ABNT_C2"; break;
			case KC_PREVTRACK: mGetString = "KC_PREVTRACK"; break;
			case KC_AT: mGetString = "KC_AT"; break;
			case KC_UNDERLINE: mGetString = "KC_UNDERLINE"; break;
			case KC_KANJI: mGetString = "KC_KANJI"; break;
			case KC_STOP: mGetString = "KC_STOP"; break;
			case KC_AX: mGetString = "KC_AX"; break;
			case KC_UNLABELED: mGetString = "KC_UNLABELED"; break;
			case KC_NEXTTRACK: mGetString = "KC_NEXTTRACK"; break;
			case KC_NUMPADENTER: mGetString = "KC_NUMPADENTER"; break;
			case KC_RCONTROL: mGetString = "KC_RCONTROL"; break;
			case KC_MUTE: mGetString = "KC_MUTE"; break;
			case KC_CALCULATOR: mGetString = "KC_CALCULATOR"; break;
			case KC_PLAYPAUSE: mGetString = "KC_PLAYPAUSE"; break;
			case KC_MEDIASTOP: mGetString = "KC_MEDIASTOP"; break;
			case KC_VOLUMEDOWN: mGetString = "KC_VOLUMEDOWN"; break;
			case KC_VOLUMEUP: mGetString = "KC_VOLUMEUP"; break;
			case KC_WEBHOME: mGetString = "KC_WEBHOME"; break;
			case KC_NUMPADCOMMA: mGetString = "KC_NUMPADCOMMA"; break;
			case KC_RMENU: mGetString = getKeyName(s3eKeyRightAlt); break;
			case KC_PAUSE: mGetString = "Pause"; break;
			case KC_HOME: mGetString = getKeyName(s3eKeyHome); break;
			case KC_UP: mGetString = getKeyName(s3eKeyUp); break;
			case KC_PGUP: mGetString = getKeyName(s3eKeyPageUp); break;
			case KC_LEFT: mGetString = getKeyName(s3eKeyLeft); break;
			case KC_RIGHT: mGetString = getKeyName(s3eKeyRight); break;
			case KC_END:  mGetString = getKeyName(s3eKeyEnd); break;
			case KC_DOWN: mGetString = getKeyName(s3eKeyDown); break;
			case KC_PGDOWN: mGetString = getKeyName(s3eKeyPageDown); break;
			case KC_INSERT: mGetString = getKeyName(s3eKeyInsert); break;
			case KC_DELETE: mGetString = getKeyName(s3eKeyDelete); break;
			case KC_LWIN: mGetString = getKeyName(s3eKeyLeftWindows); break;
			case KC_RWIN: mGetString = getKeyName(s3eKeyRightWindows); break;
			case KC_APPS: mGetString = "KC_APPS"; break;
			case KC_POWER: mGetString = "KC_POWER"; break;
			case KC_SLEEP: mGetString = "KC_SLEEP"; break;
			case KC_WAKE: mGetString = "KC_WAKE"; break;
			case KC_WEBSEARCH: mGetString = "KC_WEBSEARCH"; break;
			case KC_WEBFAVORITES: mGetString = "KC_WEBFAVORITES"; break;
			case KC_WEBREFRESH: mGetString = "KC_WEBREFRESH"; break;
			case KC_WEBSTOP: mGetString = "KC_WEBSTOP"; break;
			case KC_WEBFORWARD: mGetString = "KC_WEBFORWARD"; break;
			case KC_WEBBACK: mGetString = "KC_WEBBACK"; break;
			case KC_MYCOMPUTER: mGetString = "KC_MYCOMPUTER"; break;
			case KC_MAIL: mGetString = "KC_MAIL"; break;
			case KC_MEDIASELECT: mGetString = "KC_MEDIASELECT"; break;
			default: mGetString = "Unknown"; break;
		}
	}

	return mGetString;
}


OIS::KeyCode MarmaladeKeyboard::getAsKeyCode( std::string str )
{
	/*TODO: Unimplemented */;
	return KC_UNASSIGNED ;
}

//-------------------------------------------------------------------//
void MarmaladeKeyboard::copyKeyStates( char keys[256] ) const 
{
	// empty method
}

// S3E_KEYBOARD_KEY_EVENT callback
int32 MarmaladeKeyboard::keyboardKeyEventHandler(void* sys, void* userData)
{
	s3eKeyboardEvent* kEvent = (s3eKeyboardEvent*)sys;
	MarmaladeKeyboard* keyboard = (MarmaladeKeyboard*)userData ;

	if( keyboard->mListener ) {
		KeyCode kc = keyboard->mKeyMap[kEvent->m_Key] ;

		bool ret ;

		// keycode to virtual code translation is not supported in Marmalade, so we'll always pass 0 as 'txt' in KeyEvent
		if( kEvent->m_Pressed ) {
			ret = keyboard->mListener->keyPressed( KeyEvent( keyboard, kc, 0 ) );
		}
		else {
			ret = keyboard->mListener->keyReleased( KeyEvent( keyboard, kc, 0) ) ;
		}
	}

	return 0 ;
}

//-------------------------------------------------------------------//
void MarmaladeKeyboard::setBuffered(bool buffered)
{
	mBuffered = buffered;
 	if( buffered ) {
 		s3eKeyboardRegister( S3E_KEYBOARD_KEY_EVENT, keyboardKeyEventHandler, this ) ;
 	}
 	else {
 		s3eKeyboardUnRegister( S3E_KEYBOARD_KEY_EVENT, keyboardKeyEventHandler ) ;
 	}
}

//-------------------------------------------------------------------//
void MarmaladeKeyboard::setTextTranslation( TextTranslationMode mode )
{
	mTextMode = mode;
	// Marmalade works always in Unicode (wchar)
}

std::string MarmaladeKeyboard::getKeyName( s3eKey key )
{
	static char nameBuf[S3E_KEYBOARD_DISP_LENGTH+1] ;
	if( s3eKeyboardGetDisplayName( nameBuf, key ) != S3E_RESULT_SUCCESS ) {
		strcpy(nameBuf, "Unknown") ;
	}
	return std::string(nameBuf) ;
}

}
