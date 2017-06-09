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

    std::vector< int > RandomArray::make( unsigned int size ) const {
        std::vector< int > v( size );
        //vectorに連続な値を設定
        iota( v.begin(), v.end(), 1 );

        std::random_device rnd;

        //ランダムに並び替え
        shuffle( v.begin(), v.end(), std::mt19937( rnd() ) );

        return v;
    }

    int BubbleSort::next( std::pair<unsigned int,unsigned int> &pickup ) noexcept {
        pickup.first  = i;
        pickup.second = j - 1;

        //終了したら0を返す
		if (i == vec.size() - 1){
            pickup.first = vec.size();
			return 0;
        }

		//右が小さかったら入れ替え
		if(vec[j] < vec[j-1])
			std::swap( vec[j], vec[j - 1] );

		j--;
		if(i == j){
			i++;
			j = vec.size() - 1;
		}
		return 1;
    }


    int ShakerSort::next( std::pair<std::pair<unsigned int, unsigned int>, unsigned int> &pickup ) noexcept {
        pickup.first.first  = top;
        pickup.first.second = bot;
        pickup.second = j - 1;

        //終了したら0を返す
		if (top == bot){
            pickup.first.first = vec.size();
            pickup.first.second = vec.size();
            return 0;
        }

        if(flag){

            //右が小さかったら入れ替え
            if(vec[j] < vec[j-1]){
                std::swap( vec[j], vec[j - 1] );
                last_swap_index = j;
            }

            j--;

            if(top == j){
                top = last_swap_index;
                j = top;
                flag = false;
            }
        }else{

            //右が小さかったら入れ替え
            if(vec[j] > vec[j+1]){
                std::swap(vec[j], vec[j + 1]);
                last_swap_index = j;
            }

            j++;

            if(bot == j){
                bot = last_swap_index;
                j = bot;
                flag = true;
            }
        }
		return 1;
    }

}
