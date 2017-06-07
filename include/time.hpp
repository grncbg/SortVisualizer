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

    /*
        class Time
            概要
                指定時間待機する
            コンストラクタ
                Time() noexcept = default
            デストラクタ
                virtual ~Time() noexcept = default
            テンプレート
                class T
                    waitで指定する待ち時間の接頭辞
            関数
              public:
                template <class T>
                void wait(const std::chrono::duration<long long, T>  &time) const noexcept;
                void wait(const std::chrono::duration<long long, T> &&time) const noexcept;
                    指定時間待機する
                        引数
                            time
                                timeで指定した時間待機する
                        戻り値
                            なし
    */
    class Time{
      public:
        Time() noexcept = default;
        virtual ~Time() noexcept = default;

        template <class T>
        void wait(const std::chrono::duration<long long, T>  &) const noexcept;
        template <class T>
        void wait(const std::chrono::duration<long long, T> &&) const noexcept;
    };

    template < class T >
    void Time::wait(const std::chrono::duration< long long, T > &time) const noexcept {
        std::chrono::steady_clock::time_point s, e;
        s = std::chrono::steady_clock::now();
        e = std::chrono::steady_clock::now();
        while( e - s < time )
            e = std::chrono::steady_clock::now();
    }

    template <class T>
    void Time::wait(const std::chrono::duration<long long, T> &&time) const noexcept{
        wait(time);
    }

}

#endif
