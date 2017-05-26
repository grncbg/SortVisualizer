/*
    ncurses.cpp
    Ncursesクラスの実装

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#include "ncurses.hpp"

namespace kogcoder{

    Ncurses::Ncurses () {
        window = initscr();
		start_color();
        getmaxyx( window, y, x );
    }

    Ncurses::~Ncurses () {
        endwin();
    }

    int Ncurses::refresh () const {
        return ::refresh();
    }

    int Ncurses::getch ( void ) const {
        return ::getch();
    }

    int Ncurses::clear ( void ) const {
        return ::clear();
    }

    int Ncurses::getWindowX ( void ) const {
        return x;
    }

    int Ncurses::getWindowY ( void ) const {
        return y;
    }

}
