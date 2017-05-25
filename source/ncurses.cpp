/*
	ncurses.cpp
	Ncursesクラスの実装

	Copyright (c) 2017 KogCoder

	This software is released under the MIT License.
	http://opensource.org/licenses/mit-license.php

	Auther : teapot
	E-mail : grncbg@gmail.com
*/

#include "ncurses.hpp"
#include <ncurses.h>

namespace kogcoder{

	Ncurses::Ncurses(){

		initscr();

	}

	Ncurses::~Ncurses(){

		endwin();

	}

}