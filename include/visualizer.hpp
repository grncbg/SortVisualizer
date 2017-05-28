/*
    visualizer.hpp
    ビジュアライザクラス

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#ifndef INCLUDED_VISUALIZER_HPP
#define INCLUDED_VISUALIZER_HPP

#include "ncurses.hpp"

namespace kogcoder{

    class Visualizer{
      public:
        Visualizer () noexcept;
        virtual ~Visualizer () noexcept;
        virtual int draw () = 0;
        virtual int run ();
      private:
        Ncurses* ncurses;
        int height,width;
    };

}

#endif
