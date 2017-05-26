#include "message.h"
#include "Forder.h"
#include <iostream>
void Message::save(Folder& f) {//����const��Ϊfolders��Folder* �ļ��ϣ�������const Folder*����f.addMsg�������޸�
	folders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Folder& f) {
	folders.erase(&f);
	f.remMsg(this);
}
void Message::add_to_Folders(const Message& msg) {//�ð���msg��Folder������this
	for (auto m : msg.folders) {
		m->addMsg(this);
	}
}
Message::Message(const Message& msg)
	:contents(msg.contents),folders(msg.folders) {
	add_to_Folders(msg);
}
Message::Message(Message&& m)
	: contents(std::move(m.contents)) {
	move_Folders(&m);
}
void Message::remove_from_Folder() {//�����а�����msg��folder��ɾ����msg
	for (auto m : folders) {
		m->remMsg(this);
	}
}
Message::~Message() {
	remove_from_Folder();
}
Message& Message::operator=(const Message& msg) {
	remove_from_Folder();
	contents = msg.contents;
	folders = msg.folders;
	add_to_Folders(msg);
	return *this;
}
Message& Message::operator=(Message&& m) {
	if (&m != this) {
		remove_from_Folder();
		contents = std::move(m.contents);
		move_Folders(&m);
	}
	return *this;
}
void swap(Message& m1, Message &m2) {
	using std::swap;
	m1.remove_from_Folder();
	m2.remove_from_Folder();
	swap(m1.contents, m2.contents);
	swap(m1.folders, m2.folders);
	m1.add_to_Folders(m1);
	m2.add_to_Folders(m2);
}
void Message::display_folders() {
	for (auto f : folders) {
		std::cout << f->getName() << std::endl;
	}
}
void Message::move_Folders(Message *m) {
	folders = std::move(m->folders);
	for (auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}