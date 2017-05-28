/*
    main.cpp

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot
    E-mail : grncbg@gmail.com
*/

#include <iostream>
#include "ncurses.hpp"
#include <ncurses.h>
#include <chrono>
#include "repeat.hpp"

using namespace kogcoder;
using namespace std::chrono;
using namespace std::literals::chrono_literals;

class Test : public Routine{
  public:
    Test () {
        ncurses = new Ncurses;
        height = ncurses->getMaxHeight();
        curs_set(0);
        c = 0;
    }
    virtual ~Test(){
        delete ncurses;
    }
    virtual int run ( void ) override;
  private:
    int height;
    int c;
    Ncurses *ncurses;
};
int Test::run( void ) {
    ncurses->clear();
    ncurses->mvprintw( c, 0, "%d" , c );
    ncurses->refresh();
    return (c == height ? c = 0 : ++c);
}

// main関数
int main( void ){

    Test *t = new Test();
    Repeat<std::milli> a( t, 125ms );

    while(true){
        a.start();
    }

    delete t;

    return 0;
}
