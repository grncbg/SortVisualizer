/*
    sort.hpp
    各種Sortクラス

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#ifndef INCLUDED_SORT_HPP
#define INCLUDED_SORT_HPP

#include <vector>

namespace kogcoder{
    /*
        class RandomArray
            概要
                ランダムな配列を作る
    */
    class RandomArray {
      public:
        RandomArray() noexcept = default;

        virtual std::vector<int> make(unsigned int) const;
    };

    //バブルソート
    class BubbleSort{
      public:
        BubbleSort ( std::vector<int> &vec ) : vec(vec), i(0), j(vec.size() - 1) {}
        int next( std::pair<unsigned int,unsigned int> & );
      private:
        std::vector<int>& vec;
        unsigned int i,j;
    };

}

#endif
