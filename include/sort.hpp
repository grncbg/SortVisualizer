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

    class BubbleSort{
      public:
        BubbleSort ( std::vector<int> &vec ) : vec(vec) {}
      private:
        std::vector<int>& vec;
    };

}

#endif
