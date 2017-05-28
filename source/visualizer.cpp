/*
    visualizer.cpp
    ビジュアライザクラス

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#include "visualizer.hpp"

namespace kogcoder{

    Visualizer::Visualizer( ) noexcept{
        ncurses = new Ncurses;
        height = ncurses->getMaxHeight();
        width  = ncurses->getMaxWidth();
        curs_set(0);
    }

    Visualizer::~Visualizer () noexcept{
        delete ncurses;
    }

    Visualizer::run(){
        ncurses->clear();
        draw();
        ncurses->refresh();
    }

}
