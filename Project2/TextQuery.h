#pragma once
#include<vector>
#include<string>
#include<fstream>
#include<memory>
#include<map>
#include<set>
#include<iostream>
using std::vector;
using std::string;
using std::ifstream;
using std::shared_ptr;
using std::map;
using std::set;
//����������ʹ����ifstream��shared_ptr,map,set
class QueryResult;
class TextQuery {
public :
	using line_NO = vector<string>::size_type;
	TextQuery(ifstream& fin);
	QueryResult query(const string&);
private:
	shared_ptr<vector<string>> texts;///ʹ�ù���ָ�빲������
	map<string, shared_ptr<set<line_NO>>> wm;
};
class QueryResult {
	friend std::ostream& print(std::ostream& os, const QueryResult& qr);
private:
	string sought;
	shared_ptr<set<TextQuery::line_NO>> line_NOs;
	shared_ptr<vector<string>> texts;
public:
	QueryResult(string s, shared_ptr<set<TextQuery::line_NO>> lines, shared_ptr<vector<string>> sps):
		sought(s),line_NOs(lines),texts(sps){}
	set<TextQuery::line_NO>::iterator begin();
	set<TextQuery::line_NO>::iterator end();
	shared_ptr<vector<string>> get_file();
};
std::ostream& print(std::ostream& os, const QueryResult& qr);