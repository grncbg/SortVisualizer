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

    int Visualizer::run() {
        int ret = setData();
        ncurses.clear();
        draw();
        ncurses.refresh();
        return ret;
    }

    int BubbleSortVisualizer::setData() noexcept {
        return bs.next( pickup );
    }

    int BubbleSortVisualizer::draw() const noexcept {
        for( unsigned int i = 0; i < data.size(); i++,ncurses.nextLine() ){
            if( i < pickup.first )
                ncurses.hbar( data[i], BLUE_LINE );
            else if( i == pickup.second || i == pickup.second + 1 )
                ncurses.hbar( data[i], RED_LINE );
            else
                ncurses.hbar( data[i] );
        }
        return true;
    }

}
