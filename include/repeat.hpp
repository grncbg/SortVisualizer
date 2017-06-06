/*
    repeat.hpp
    Repeatクラス

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#ifndef INCLUDED_REPEAT_HPP
#define INCLUDED_REPEAT_HPP

#include <chrono>

#include "time.hpp"

namespace kogcoder{

    /*
        class Routine
            概要
                Repeatクラスに渡すための抽象クラス
            コンストラクタ
                なし
            デストラクタ
                なし
            関数
              public:
                virtual int run() = 0
                    ルーチンを実行する
                        引数
                            なし
                        戻り値
                            int : すべて終了したときfalseを返す
                                  それ以外の場合任意のtrueに相当する値を返して良い
    */
    class Routine{
      public:
        virtual int run ( void ) = 0;
    };

    /*
        class Repeat
            概要
                指定時間ごとにRoutineを繰り返し実行する
            コンストラクタ
                Repeat () = delete;
                Repeat ( Repeat& ) = default;
                Repeat ( Repeat&& ) = default;
                Repeat ( Routine *routine, std::chrono::duration< long long, T > &interval )
                Repeat ( Routine *routine, std::chrono::duration< long long, T > &&interval )
                    引数
                        routine
                            繰り返し実行するRoutineのポインタ
                        interval
                            繰り返す間隔
    */
    template < class T >
    class Repeat{
      public:
        Repeat() noexcept = delete;
        Repeat(Repeat &) noexcept = default;
        Repeat(Repeat &&) noexcept = default;
        Repeat(Routine *routine, std::chrono::duration<long long, T> &interval) noexcept : routine(routine), interval(interval) {}
        Repeat(Routine *routine, std::chrono::duration<long long, T> &&interval) noexcept : routine(routine), interval(interval) {}

        virtual ~Repeat() noexcept = default;

        virtual void start( void ) const;
      private:
        Routine *routine;
        Time time;
        std::chrono::duration< long long, T > interval;
    };

    template < class T >
    void Repeat< T >::start() const {
        while( routine->run() )
            time.wait< T >( interval );
    }

}

#endif
