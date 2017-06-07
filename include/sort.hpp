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
            コンストラクタ
                RandomArray() noexcept = default
            デストラクタ
                virtual ~RandomArray() noexcept = default
            関数
                virtual std::vector<int> make(unsigned int size) const
                    1<=n<=sizeの値が一つずつ入ったランダムな並び順のvectorを返す
                        引数
                            size
                                要素数
                        戻り値
                            1<=n<=sizeの値が一つずつ入ったランダムな並び順のvector
    */
    class RandomArray {
      public:
        RandomArray() noexcept = default;
        virtual ~RandomArray() noexcept = default;

        virtual std::vector<int> make(unsigned int) const;
    };

    class BubbleSort{
      public:
        BubbleSort ( std::vector<int> &vec ) : vec(vec), i(0), j(vec.size() - 1) {}
        virtual ~BubbleSort() noexcept = default;

        virtual int next( std::pair<unsigned int,unsigned int> & ) noexcept;
      private:
        std::vector<int>& vec;
        unsigned int i,j;
    };

}

#endif
