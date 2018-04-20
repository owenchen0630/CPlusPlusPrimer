#pragma once
#ifndef NOTEPAD_H
#define NOTEPAD_H
#include <string>
#include <vector>
class Screen
{
	friend class Window_mgr;
public:
	typedef std::string::size_type pos;
	//也可以使用类型别名等价地声明一个类型名字
	//using pos=std::string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht * wd, c) {}
	pos size() const { return height * width; }
	char get() const { return contents[cursor]; } //隐式内联
	char get(pos, pos) const;
	Screen& move(pos, pos);
	Screen& set(char);
	Screen& set(pos, pos, char);
	Screen& display(std::ostream &os) { do_display(os);return *this; }
	const Screen& display(std::ostream &os) const { do_display(os);return *this; }
private:
	pos cursor = 0;//光标位置
	pos height = 0, width = 0;//屏幕高宽
	std::string contents;
	void do_display(std::ostream &os) const { os << contents; }
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

inline Screen& Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch) {
	contents[r*width + c] = ch;
	return *this;
}

class Window_mgr 
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	ScreenIndex addScreen(const Screen&);
	void clear(ScreenIndex);
private:
	//这个Window_mgr追踪的Screen
	//默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
};

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
	screens.push_back(s);
	return screens.size() - 1;
}

void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

#endif