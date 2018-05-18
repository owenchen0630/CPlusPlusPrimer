#include <string>
using std::string;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::allocator;
#include <new>
#include <mutex>
#include <thread>
#include <Windows.h>
#include <condition_variable>

std::mutex mt;
std::condition_variable cvar;
int cvnum = 0;
void Func1() {
	while (true) {
		std::unique_lock<std::mutex> ul(mt);
		cvar.wait(ul, []() {return cvnum == 0;});
		cvnum = 2;
		cvar.notify_all();
		ul.unlock();
		cout << 1;
		Sleep(1000);
	}
}
void Func2() {
	while (true) {
		std::unique_lock<std::mutex> ul(mt);
		cvar.wait(ul, []() {return cvnum == 2;});
		cvnum--;
		cvar.notify_all();
		ul.unlock();
		cout << 2;
		Sleep(1000);
	}
}
void Func3() {
	while (true) {
		std::unique_lock<std::mutex> ul(mt);
		cvar.wait(ul, []() {return cvnum == 1;});
		cvnum--;
		cvar.notify_all();
		ul.unlock();
		cout << 3;
		Sleep(1000);
	}
}
int main() {
	std::thread task1(Func1);
	std::thread task2(Func2);
	std::thread task3(Func3);
	task1.detach();
	task2.detach();
	task3.detach();
	system("pause");
	return 0;
}