/*
    sort.cpp
    各種Sortクラス

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#include <algorithm>
#include "sort.hpp"

namespace kogcoder{

    int BubbleSort::next(){
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
