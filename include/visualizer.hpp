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

#include <vector>
#include "ncurses.hpp"
#include "sort.hpp"

namespace kogcoder{

    class Visualizer{
      public:
        Visualizer () noexcept;
        virtual ~Visualizer () noexcept;
        virtual int run ();
      private:
        virtual int draw () = 0;
        virtual int setData() = 0;
      protected:
        Ncurses* ncurses;
        int height,width;
        std::vector<int> data;
    };

    class BubbleSortVisualizer : public Visualizer{
      public:
        BubbleSortVisualizer ( BubbleSort &bs ) noexcept : bs(bs) {}
        virtual int setData() noexcept override;
      private:
        BubbleSort &bs;
    };

}

#endif
