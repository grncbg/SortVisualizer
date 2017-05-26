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

    Ncurses::Ncurses(){
        initscr();
    }

    Ncurses::~Ncurses(){
        endwin();
    }

    int Ncurses::refresh(){
        return ::refresh();
    }

    int Ncurses::getch( void ){
        return ::getch();
    }

    int Ncurses::clear( void ){
        return ::clear();
    }

}
