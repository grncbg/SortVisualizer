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
        //新しい状態の取得
        int ret = setData();
        //画面のクリア
        ncurses.clear();
        //描画
        draw();
        //画面の再描画
        ncurses.refresh();
        return ret;
    }

    int BubbleSortVisualizer::setData() noexcept {
        return bs.next( pickup );
    }

    int BubbleSortVisualizer::draw() const noexcept {
        for( unsigned int i = 0; i < data.size(); i++,ncurses.nextLine() ){
            //ソート済み
            if( i < pickup.first )
                ncurses.hbar( data[i], BLUE_LINE );
            //変更
            else if( i == pickup.second || i == pickup.second + 1 )
                ncurses.hbar( data[i], RED_LINE );
            //それ以外
            else
                ncurses.hbar( data[i] );
        }
        return true;
    }

}
