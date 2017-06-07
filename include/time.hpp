/*
    time.hpp
    Timeクラス

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#ifndef INCLUDED_TIMT_HPP
#define INCLUDED_TIMT_HPP

#include <chrono>

namespace kogcoder{

    class Time{
      public:
        Time() noexcept = default;
        virtual ~Time() noexcept = default;

        template <class T>
        void wait(const std::chrono::duration<long long, T> &) const;
        template < class T >
        void wait(const std::chrono::duration< long long, T > &&) const;
    };

    template < class T >
    void Time::wait(const std::chrono::duration< long long, T > &time) const {
        std::chrono::steady_clock::time_point s,e;
        s = std::chrono::steady_clock::now();
        e = std::chrono::steady_clock::now();
        while( e - s < time )
            e = std::chrono::steady_clock::now();
    }

    template < class T >
    void Time::wait(const std::chrono::duration< long long, T > &&time) const {
        wait(time);
    }

}

#endif
