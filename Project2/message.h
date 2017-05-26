#pragma once
#include<string>
#include<set>

class Message {
	friend class Folder;
public:
	explicit Message(const std::string &str=""):contents(str){}//有默认参数，默认构造函数
	Message(const Message&);
	Message(Message&&);
	Message& operator=(const Message&);
	Message& operator=(Message&& m);
	~Message();
	void save(Folder&);
	void remove(Folder&);//
	friend void swap(Message&, Message&);
	void display_folders();
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folder();
	void move_Folders(Message *);
};