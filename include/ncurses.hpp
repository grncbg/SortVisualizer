/*
	ncurses.hpp
	Ncursesクラス

	Copyright (c) 2017 KogCoder

	This software is released under the MIT License.
	http://opensource.org/licenses/mit-license.php

	Auther : teapot <grncbg@gmail.com>
*/

#include <string>
#include <ncurses.h>
#include <type_traits>

#undef getch

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
			int refresh (void)
			int getch (void)
	*/
	class Ncurses{
	public:
		Ncurses ();
		Ncurses ( Ncurses& ) = delete;
		~Ncurses ();

		template < class ... Args >
		int printw ( const char*, Args const & ... );
		template < class ... Args >
		int printw ( const std::string &, Args const & ... );

		template < class T, class ... Args >
		int mvprintw ( const T, const T, const char*, Args const & ...);
		template < class T, class ... Args >
		int mvprintw ( const T, const T, const std::string, Args const & ...);

		int refresh( void );

		int getch( void );

		int clear( void );
	};

}

template <class ... Args>
int kogcoder::Ncurses::printw ( const char* format, Args const & ... args ){
	return ::printw( format, args ... );
};

template <class ... Args>
int kogcoder::Ncurses::printw ( const std::string & format, Args const & ... args ){
	return printw( format.c_str(), args ... );
};

#endif
