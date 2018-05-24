#include <string>
using std::string;
#include <vector>
using std::vector;
#include <set>
using std::set;
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
#include <algorithm>

class Folder;

class Message {
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	explicit Message(const string &str = "") :contents(str) {}
	Message(const Message&);
	Message(Message&&);
	Message& operator=(const Message&);
	Message& operator=(Message &&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	void addFolder(Folder*f) { folders.insert(f); }
	void remFolder(Folder*f) { folders.erase(f); }
private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_Folders(Message *m);
};

Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders) {
	add_to_Folders(m);
}

Message::Message(Message &&m) :
	contents(std::move(m.contents)) {
	move_Folders(&m);
}

Message & Message::operator=(const Message &rhs) {
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message& Message::operator=(Message &&rhs) {
	if (this != &rhs) {
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

Message::~Message() {
	remove_from_Folders();
}

class Folder {
public:
	explicit Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder() { remove_from_Messages(); }
	void addMsg(Message*);
	void remMsg(Message*);
private:
	set<Message*> messages;
	void add_to_Messages(const Folder&);
	void remove_from_Messages();
};

Folder::Folder(const Folder &f) :
	messages(f.messages) {
	add_to_Messages(f);
}

Folder& Folder::operator=(const Folder &rhs) {
	remove_from_Messages();
	messages = rhs.messages;
	add_to_Messages(rhs);
	return *this;
}

void Folder::add_to_Messages(const Folder &f) {
	for (auto m : f.messages) {
		m->folders.insert(this);
	}
}

void Folder::remove_from_Messages() {
	for (auto m : messages) {
		m->folders.erase(this);
	}
}

void Folder::addMsg(Message *m) {
	messages.insert(m);
}

void Folder::remMsg(Message *m) {
	messages.erase(m);
}

void Message::save(Folder &f) {
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f) {
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders() {
	for (auto f : folders)
		f->remMsg(this);
}

void Message::move_Folders(Message *m) {
	folders = std::move(m->folders);
	for (auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

void swap(Message &lhs, Message &rhs) {
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

int main() {

	system("pause");
	return 0;
}
