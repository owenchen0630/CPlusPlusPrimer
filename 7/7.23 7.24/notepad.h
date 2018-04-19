#pragma once
#ifndef NOTEPAD_H
#define NOTEPAD_H
#include <string>
#include <vector>
class Screen
{
public:
	typedef std::string::size_type pos;
	//也可以使用类型别名等价地声明一个类型名字
	//using pos=std::string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht * wd, c) {}
	char get() const { return contents[cursor]; } //隐式内联
	char get(pos, pos) const;
	Screen& move(pos, pos);

private:
	pos cursor = 0;//光标位置
	pos height = 0, width = 0;//屏幕高宽
	std::string contents;
};

inline char Screen::get(pos r, pos c) const {
	pos row = r * width;
	return contents[row + c];
}

//返回值是*this 是对象（左值引用）故类型为Screen&
inline Screen& Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

class Window_mgr 
{
public:

private:
	//这个Window_mgr追踪的Screen
	//默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
};
#endif