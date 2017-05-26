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
                なし
    */
    class Routine{
      public:
        virtual int run() = 0;
    };

}

#endif
