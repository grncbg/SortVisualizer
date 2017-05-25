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

#ifndef INCLUDED_NCURSES_HPP
#define INCLUDED_NCURSES_HPP
namespace kogcoder{

	/*
		class Ncurses
			ncursesの薄いラッパー
		コンストラクタ
			Ncurses()
			Ncurses ( Ncurses& ) = delete;
		デストラクタ
			~Ncurses()
	*/
	class Ncurses{
	public:
		Ncurses ();
		Ncurses ( Ncurses& ) = delete;
		~Ncurses ();

		template <typename ... Args>
		int printw ( const char*, Args const & ... );
		template <typename ... Args>
		int printw ( const std::string, Args const & ... );
	};

}

#endif
