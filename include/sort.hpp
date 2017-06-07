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

    /*
        class BubbleSort
            概要
                バブルソートをする
            コンストラクタ
                BubbleSort ( std::vector<int> &vec )
                    引数
                        vec
                            ソートをするvector
            デストラクタ
                virtual ~BubbleSort() noexcept = default
            関数
              private:
                virtual int next( std::pair<unsigned int,unsigned int> &pickup) noexcept
                    ソートを1段階すすめる
                        引数
                            pickup
                                値を返すための引数
                                firstに既にソートされた部分の最後の要素の添字を
                                secondに入れ替えを行った要素の添字を入れる
                        戻り値
                            ソートが終了したら0を、それ以外のとき1を返す
            変数
              private:
                std::vector<int>& vec
                    現在状態の配列を保持する
                unsigned int i
                    ソートが終了済みの領域の最後の要素の添字
                unsigned int j
                    現在比較している要素の添字
    */
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
