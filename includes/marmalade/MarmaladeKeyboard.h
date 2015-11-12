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
#ifndef _OIS_MarmaladeKeyboard_H
#define _OIS_MarmaladeKeyboard_H

#include "OISKeyboard.h"
#include "Marmalade/MarmaladePrereqs.h"

namespace OIS
{
	class MarmaladeKeyboard : public Keyboard
	{
	public:
		/**
		@remarks
			Constructor
		@param buffered
			True for buffered input mode
		*/
		MarmaladeKeyboard( InputManager* creator, bool buffered );
		virtual ~MarmaladeKeyboard();

		/** @copydoc Keyboard::isKeyDown */
		virtual bool isKeyDown( KeyCode key ) const ;

		/** @copydoc Keyboard::getAsString */
		virtual const std::string& getAsString( KeyCode kc );

		/** @copydoc Keyboard::getAsKeyCode */
		virtual OIS::KeyCode getAsKeyCode(std::string str) ;

		/** @copydoc Keyboard::copyKeyStates */
		virtual void copyKeyStates( char keys[256] ) const ;

		/** @copydoc Object::setBuffered */
		virtual void setBuffered(bool buffered);

		/** @copydoc Object::capture */
		virtual void capture();

		/** @copydoc Object::queryInterface */
		virtual Interface* queryInterface(Interface::IType type) {return 0;}

		/** @copydoc Object::_initialize */
		virtual void _initialize();

		/** @copydoc Object::setTextTranslation */
		virtual void setTextTranslation( TextTranslationMode mode );

	private:
		std::string getKeyName( s3eKey key ) ;
		void createKeyMap();
		void createInverseKeyMap() ;
		
		static int32 keyboardKeyEventHandler(void* sys, void*);

		typedef std::map<s3eKey, KeyCode> KeyMap;
		typedef std::map<KeyCode, s3eKey> InverseKeyMap ;

		KeyMap mKeyMap;
		InverseKeyMap mInverseKeyMap ;

		std::string mGetString;
	};
}
#endif
