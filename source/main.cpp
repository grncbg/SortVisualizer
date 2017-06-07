/*
    main.cpp

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#include <chrono>
#include <iostream>

#include <ncurses.h>

#include "ncurses.hpp"
#include "repeat.hpp"
#include "sort.hpp"
#include "time.hpp"
#include "visualizer.hpp"

using namespace kogcoder;
using namespace std;
using namespace std::chrono;
using namespace std::literals::chrono_literals;

// main関数
int main( void ){
    //ncursesのラッパー
    Ncurses ncurses;

    //ランダムな配列のジェネレーター
    RandomArray gen;
    //時間処理のクラス(waitのみ)
    Time time;

    //端末の高さを取得
    int height = ncurses.getMaxHeight();

    while(true){
        //ランダムな配列を作成
        vector<int> vec = gen.make(height);
        //バブルソート
        BubbleSort bs(vec);
        //バブルソートのビジュアライザ
        BubbleSortVisualizer *bsv = new BubbleSortVisualizer(ncurses, bs, vec);
        //連続処理
        Repeat<std::milli> r(bsv, 25ms);

        //処理の開始
        r.start();

        delete bsv;

        //wait
        time.wait<std::milli>(1000ms);
    }

    return 0;
}
