/*
    sort.cpp
    各種Sortクラス

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#include <algorithm>
#include <random>
#include "sort.hpp"

namespace kogcoder{

    std::vector<int>&& RandomArray::make( unsigned int size ) const {
        std::vector<long long> v( size );
        //vectorに連続な値を設定
        iota( v.rbegin(), v.rend(), 1 );

        std::random_device rnd;

        //ランダムに並び替え
        shuffle( v.begin(), v.end(), std::mt19937( rnd() ) );

        return std::move( v );
    }

    int BubbleSort::next() {
		if (i == vec.size() - 1)
			return 0;
		//右が小さかったら入れ替え
		if(vec[j] < vec[j-1])
			std::swap(vec[j], vec[j - 1]);

		j--;
		if(i == j){
			i++;
			j = vec.size() - 1;
		}
		return 1;
    }

}
