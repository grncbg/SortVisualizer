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
		x_default = (width - hight)/2;
        init_pair( COLOR_PAIRS - 1, COLOR_BLACK, COLOR_WHITE );
        init_pair( COLOR_PAIRS - 2, COLOR_BLACK, COLOR_BLUE );
        init_pair( COLOR_PAIRS - 3, COLOR_BLACK, COLOR_RED );
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
        int let = ::clear();
		move(0,x_default);
		return let;
    }

    int Ncurses::getMaxWidth ( void ) const noexcept {
        return width;
    }

    int Ncurses::getMaxHeight ( void ) const noexcept {
        return hight;
    }

    int Ncurses::hbar ( const unsigned int len, const int color ) const noexcept {
        attron(COLOR_PAIR(color));
        int ret = hline(' ', len);
        attron(COLOR_PAIR(0));
        return ret;
    }

    int Ncurses::move ( const int y, const int x ) const noexcept {
        return ::move( y, x );
    }

    int Ncurses::nextLine( void ) const noexcept {
        int y, x;
        getyx( window, y, x );
        return move( ++y, x_default );
    }

}
