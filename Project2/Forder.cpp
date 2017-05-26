#include "Forder.h"
#include"message.h"
#include<iostream>
void Folder::addMsg(Message *m) {
	messages.insert(m);
	m->folders.insert(this);
}
void Folder::remMsg(Message *m) {
	messages.erase(m);
	m->folders.erase(this);
}
void Folder::display_messages() {
	for (auto m : messages)
		std::cout<<m->contents<<std::endl;
}
void Folder::remove_from_Message() {
	for (auto m : messages)
		m->folders.erase(this);
}
Folder::~Folder() {
	remove_from_Message();
}
void Folder::add_to_Message(const Folder& f) {
	for (auto m : f.messages) {
		m->save(*this);
	}
}