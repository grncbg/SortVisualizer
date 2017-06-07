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
#include "repeat.hpp"
#include "sort.hpp"

namespace kogcoder{
    /*
        class Visualizer : public Routine
            概要
                ビジュライザの基底クラス
            コンストラクタ
                Visualizer ( Ncurses &ncurses ) noexcept
                    引数
                        Ncursesのインスタンス
            デストラクタ
                virtual ~Visualizer() noexcept = default
    */
    class Visualizer : public Routine{
      public:
        Visualizer ( Ncurses &ncurses ) noexcept : ncurses(ncurses){
            height = ncurses.getMaxHeight();
            width  = ncurses.getMaxWidth();
            curs_set(0);
        }
        virtual ~Visualizer() noexcept = default;

        virtual int run();

      private:
        virtual int draw() const = 0;
        virtual int setData() = 0;

      protected:
        Ncurses& ncurses;
        int height,width;
    };

    class BubbleSortVisualizer : public Visualizer{
      public:
        BubbleSortVisualizer(Ncurses &ncurses, BubbleSort &bs, std::vector<int> &v) noexcept : Visualizer(ncurses), bs(bs), data(v){}
        virtual int setData() noexcept override;
        virtual int draw() const noexcept override;

      private:
        BubbleSort &bs;
        std::vector< int > &data;
        std::pair<unsigned int, unsigned int> pickup;
    };
}

#endif
