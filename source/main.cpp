/*
    main.cpp

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#include <chrono>
#include <iostream>

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
int main(void){

    Ncurses ncurses;
    RandomArray gen;
    Time time;
    int height = ncurses.getMaxHeight();

    const int type = 2;

    int count = 0;

    while(true){
        //ランダムな配列を作成
        vector<int> vec = gen.make(height);

        switch(count){
          case 0:
            {
                BubbleSort bs(vec);
                BubbleSortVisualizer bsv(ncurses, bs, vec);
                Repeat<std::milli> r(&bsv, 10ms);
                r.start();
            }
            break;
          case 1:
            {
                ShakerSort ss(vec);
                ShakerSortVisualizer ssv(ncurses, ss, vec);
                Repeat<std::milli> r(&ssv, 10ms);
                r.start();
            }
            break;
        }

        //wait
        time.wait<std::milli>(1000ms);

        count = (count + 1) % type;

    }

    return 0;
}
