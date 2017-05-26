#pragma once
#include<string>
#include<set>

class Message {
	friend class Folder;
public:
	explicit Message(const std::string &str=""):contents(str){}//��Ĭ�ϲ�����Ĭ�Ϲ��캯��
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