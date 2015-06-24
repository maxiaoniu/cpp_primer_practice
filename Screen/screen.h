#ifndef SCREEN_H
#define SCREEN_H

#include <string>
class Screen
{
public:
    //Users of Screen class should not know that Screen uses a string to hold its data
    //hide detail
    //
    typedef std::string::size_type pos;
    Screen()=default;
    Screen(pos ht, pos wd):height(ht),width(wd),contents(ht*wd,' ') {}
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht *wd, c) {}
    // Function that be defined in the class is automatically inline, so this is impilicitly inline
    char get() const {return contents[cursor];}
    inline char get(pos r, pos c) const;
    Screen &move(pos r, pos c);
private:
    pos cursor=0;
    pos height = 0, width = 0;
    std::string contents;


};
//inline function should be defined in the header file
inline
Screen &Screen::move(pos r, pos c)
{
    pos row = r*width;
    cursor = row + c;
    return *this;
}
char
Screen::get(pos r, pos c) const
{
    pos row = r*width;
    return contents[row+c];
}
#endif // SCREEN_H
