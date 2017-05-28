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
            変数
               milliseconds> なし
    */
    /*Repeatクラスに渡すための抽象クラス*/
    class Routine{
      public:
        virtual int run ( void ) = 0;
    };

    template < class T = std::milli >
    class Repeat{
      public:
        Repeat () = delete;
        Repeat ( Repeat& ) = default;
        Repeat ( Repeat&& ) = default;
        Repeat ( Routine *routine, std::chrono::duration< long long, T > &&interval ) : routine( routine ), interval( interval ){}

        virtual void start( void ) const;
      private:
        Routine *routine;
        std::chrono::duration< long long, T > interval;
    };

    template < class T >
    void Repeat<T>::start() const {
        std::chrono::steady_clock::time_point s,e;
        e = std::chrono::steady_clock::now();
        while(routine->run()){
            s = std::chrono::steady_clock::now();
            while( e - s < interval )
                e = std::chrono::steady_clock::now();
        }
    }

}

#endif
