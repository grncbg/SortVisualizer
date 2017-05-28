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

    int Visualizer::run(){
        int ret = setData();
        ncurses.clear();
        draw();
        ncurses.refresh();
        return ret;
    }

    int BubbleSortVisualizer::setData() noexcept {
        return bs.next(pickup);
    }

    int BubbleSortVisualizer::draw() const noexcept {
        return true;
    }

}
