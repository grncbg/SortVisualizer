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

    Ncurses::Ncurses () noexcept {
        window = initscr();
		start_color();
        getmaxyx( window, hight, width );
    }

    Ncurses::~Ncurses () noexcept {
        endwin();
    }

    int Ncurses::refresh () const noexcept {
        return ::refresh();
    }

    int Ncurses::getch ( void ) const noexcept {
        return ::getch();
    }

    int Ncurses::clear ( void ) const noexcept {
        return ::clear();
    }

    int Ncurses::getMaxWidth ( void ) const noexcept {
        return width;
    }

    int Ncurses::getMaxHeight ( void ) const noexcept {
        return hight;
    }

    int Ncurses::hbar ( unsigned int len, int color ) const noexcept {
        init_pair( COLOR_PAIRS - 1, COLOR_BLACK, color );
        attron(COLOR_PAIR(COLOR_PAIRS - 1));
        int ret = hline(' ', len);
        attron(COLOR_PAIR(0));
        return ret;
    }

}
