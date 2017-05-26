/*
    ncurses.hpp
    Ncursesクラス

    Copyright (c) 2017 KogCoder

    This software is released under the MIT License.
    http://opensource.org/licenses/mit-license.php

    Auther : teapot <grncbg@gmail.com>
*/

#include <string>
#include <ncurses.h>

#undef getch

#ifndef INCLUDED_NCURSES_HPP
#define INCLUDED_NCURSES_HPP

namespace kogcoder{

    /*
        class Ncurses
            ncursesの薄いラッパー
        コンストラクタ
            Ncurses()
            Ncurses ( Ncurses& ) = delete
        デストラクタ
            ~Ncurses()
        関数
          public:
            virtual int printw ( const char*, Args const & ... ) const
            virtual int printw ( const std::string, Args const & ... ) const
            virtual int mvprintw ( const int, const int, const char*, Args const & ... ) const
            virtual int mvprintw ( const int, const int, const std::string, Args const & ... ) const
            virtual int refresh ( void ) const
            virtual int getch ( void ) const
            virtual int clear ( void ) const
            virtual int getWindowX ( void ) const
            virtual int getWindowY ( void ) const
        変数
          private:
            WINDOW window
                作ったwindowを持つ
            int y
                windowの高さを持つ
            int x
                windowの横幅を持つ
    */
    class Ncurses{
      public:
        Ncurses ();
        Ncurses ( Ncurses& ) = delete;
        ~Ncurses ();

        template < class ... Args >
        int printw ( const char*, Args const & ... ) const;
        template < class ... Args >
        int printw ( const std::string &, Args const & ... ) const;

        template < class ... Args >
        int mvprintw ( const int, const int, const char*, Args const & ...) const;
        template < class ... Args >
        int mvprintw ( const int, const int, const std::string, Args const & ...) const;

        virtual int refresh ( void ) const;

        virtual int getch ( void ) const;

        virtual int clear ( void ) const;

        virtual int getWindowX ( void ) const;
        virtual int getWindowY ( void ) const;

      private:
        WINDOW *window;
        int y, x;
    };

}

template < class ... Args >
int kogcoder::Ncurses::printw ( const char* format, Args const & ... args ) const {
    return ::printw( format, args ... );
};

template < class ... Args >
int kogcoder::Ncurses::printw ( const std::string & format, Args const & ... args ) const {
    return printw( format.c_str(), args ... );
};

template < class ... Args >
int kogcoder::Ncurses::mvprintw ( const int y, const int x, const char* format, Args const & ... args ) const {
    return ::mvprintw( y, x, format, args ... );
}
template < class ... Args >
int kogcoder::Ncurses::mvprintw ( const int y, const int x, const std::string format, Args const & ... args ) const {
    return mvprintw( y, x, format.c_str(), args ... );
}

#endif
