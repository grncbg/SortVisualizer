/*
	ncurses.hpp
	Ncursesクラス

	Copyright (c) 2017 KogCoder

	This software is released under the MIT License.
	http://opensource.org/licenses/mit-license.php

	Auther : teapot
	E-mail : grncbg@gmail.com
*/

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
	};

}

#endif
