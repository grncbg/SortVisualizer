/*
	ncurses.hpp
	Ncursesクラス

	Copyright (c) 2017 KogCoder

	This software is released under the MIT License.
	http://opensource.org/licenses/mit-license.php

	Auther : teapot
	E-mail : grncbg@gmail.com
*/

#include <string>
#include <ncurses.h>

#ifndef INCLUDED_NCURSES_HPP
#define INCLUDED_NCURSES_HPP

namespace kogcoder{

	/*
		class Ncurses
			ncursesの薄いラッパー
		コンストラクタ
			Ncurses()
			Ncurses ( Ncurses& ) = delete
		デストラクタ
			~Ncurses()
		関数
			int printw ( const char*, Args const & ... )
			int printw ( const std::string, Args const & ... )
	*/
	class Ncurses{
	public:
		Ncurses ();
		Ncurses ( Ncurses& ) = delete;
		~Ncurses ();

		template <typename ... Args>
		int printw ( const char*, Args const & ... );
		template <typename ... Args>
		int printw ( const std::string &, Args const & ... );

		int refresh( void );
	};

}

template <typename ... Args>
int kogcoder::Ncurses::printw ( const char* format, Args const & ... args ){
	return ::printw( format, args ... );
};

template <typename ... Args>
int kogcoder::Ncurses::printw ( const std::string & format, Args const & ... args ){
	return ::printw( format, args ... );
};

#endif
