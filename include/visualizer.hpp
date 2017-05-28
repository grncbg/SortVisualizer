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
#include "sort.hpp"

namespace kogcoder{

    class Visualizer{
      public:
        Visualizer () noexcept;
        virtual ~Visualizer () noexcept;
        virtual int draw () = 0;
        virtual int run ();
        virtual int setDate() = 0;
      private:
        Ncurses* ncurses;
        int height,width;
    };

    class BubbleSortVisualizer : public Visualizer{

    };

}

#endif
