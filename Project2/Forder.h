#pragma once
#include<string>
#include<set>

class Message;
class Folder {
private:
	std::set<Message*> messages;
	std::string name;
	void add_to_Message(const Folder&);
	void remove_from_Message();
public:
	Folder(const std::string &str=""):name(str){}
	/*Folder(const Folder&);
	Folder& operator=(const Folder&);*/
	~Folder();
	void addMsg(Message*);
	void remMsg(Message*);
	void display_messages();
	std::string getName() {
		return name;
	}
	//void swap(Folder&, Folder&);
};