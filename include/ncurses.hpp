/*
    ncurses.hpp
    Ncursesクラス

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#ifndef INCLUDED_NCURSES_HPP
#define INCLUDED_NCURSES_HPP

#include <string>
#include <ncurses.h>

#undef getch

#define WHITE_LINE COLOR_PAIRS - 1
#define BLUE_LINE  COLOR_PAIRS - 2
#define RED_LINE   COLOR_PAIRS - 3

namespace kogcoder{

    /*
        class Ncurses
            概要
                ncursesの薄いラッパー
            コンストラクタ
                Ncurses()
                Ncurses ( Ncurses& ) = delete
                Ncurses ( Ncurses&& ) noexcept = default
            デストラクタ
                ~Ncurses()
            関数
            public:
                virtual int printw ( const char* format, Args const & ... args ) const noexcept
                virtual int printw ( const std::string format, Args const & ... args ) const noexcept
                    printf形式で表示する
                        引数
                            format : 出力するフォーマット(printfと同様)
                            args   : 出力内容の引数(printfと同様)
                        戻り値
                            TODO : ncursesのprintf関数の戻り値を調べる

                virtual int mvprintw ( const int y, const int x, const char* format, Args const & ... args ) const noexcept
                virtual int mvprintw ( const int y, const int x, const std::string format, Args const & ... args ) const noexcept
                    移動したあとprintf形式で表示する
                        引数
                            y : 移動先のy座標
                            x : 移動先のx座標
                            format : 出力するフォーマット(printfと同様)
                            args   : 出力内容の引数(printfと同様)
                        戻り値
                            TODO : ncursesのmvprintf関数の戻り値を調べる

                virtual int refresh ( void ) const noexcept
                    端末を再描画する
                        引数
                            なし
                        戻り値
                            TODO : ncursesのrefresh関数の戻り値を調べる

                virtual int getch ( void ) const noexcept
                    1文字入力する
                        引数
                            なし
                        戻り値
                            int : keypadがtrueに設定されているとき，キーコードを返す

                virtual int clear ( void ) const noexcept
                    windowをクリアする
                        引数
                            なし
                        戻り値
                            なし

                virtual int getMaxWidth ( void ) const noexcept
                    windowの横幅を返す
                        引数
                            なし
                        戻り値
                            int : windowの横幅を返す

                virtual int getMaxHeight ( void ) const noexcept
                    windowの高さを返す
                        引数
                            なし
                        戻り値
                            int : windowの高さを返す


            変数
            private:
                WINDOW window
                    作ったwindowを持つ

                int hight
                    windowの高さを持つ

                int width
                    windowの横幅を持つ
    */
    class Ncurses{
      public:
        Ncurses () noexcept;
        Ncurses ( Ncurses& ) = delete;
        Ncurses ( Ncurses&& ) noexcept = default;
        virtual ~Ncurses () noexcept;

        template < class ... Args >
        int printw ( const char*, Args const & ... ) const noexcept;
        template < class ... Args >
        int printw ( const std::string &, Args const & ... ) const noexcept;

        template < class ... Args >
        int mvprintw ( const int, const int, const char*, Args const & ...) const noexcept;
        template < class ... Args >
        int mvprintw ( const int, const int, const std::string, Args const & ...) const noexcept;

        virtual int refresh ( void ) const noexcept;

        virtual int getch ( void ) const noexcept;

        virtual int clear ( void ) const noexcept;

        virtual int getMaxWidth ( void ) const noexcept;
        virtual int getMaxHeight ( void ) const noexcept;

        virtual int hbar ( const unsigned int, const int = WHITE_LINE ) const noexcept;

        virtual int move ( const int, const int ) const noexcept;

        virtual int nextLine( void ) const noexcept;

      private:
        WINDOW *window;
        int hight, width;
    };

}

template < class ... Args >
int kogcoder::Ncurses::printw ( const char* format, Args const & ... args ) const noexcept {
    return ::printw( format, args ... );
};

template < class ... Args >
int kogcoder::Ncurses::printw ( const std::string & format, Args const & ... args ) const noexcept {
    return printw( format.c_str(), args ... );
};

template < class ... Args >
int kogcoder::Ncurses::mvprintw ( const int y, const int x, const char* format, Args const & ... args ) const noexcept {
    return ::mvprintw( y, x, format, args ... );
}
template < class ... Args >
int kogcoder::Ncurses::mvprintw ( const int y, const int x, const std::string format, Args const & ... args ) const noexcept {
    return mvprintw( y, x, format.c_str(), args ... );
}

#endif
