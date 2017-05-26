#include"TextQuery.h"
#include<sstream>
using namespace std;
TextQuery::TextQuery(ifstream& fin) :texts(new vector<string>) {
	string line;
	while (getline(fin, line)) {
		texts->push_back(line);
		int n = texts->size() - 1;
		istringstream iss(line);
		string word;
		while (iss >> word) {
			auto &sp = wm[word];//
			if (!sp) {
				sp.reset(new set<TextQuery::line_NO>);
			}
			sp->insert(n);
		}
	}
}
QueryResult TextQuery::query(const string &s) {
	static shared_ptr<set<line_NO>> no_data(new set<line_NO>);
	auto loc = wm.find(s);
	if (loc == wm.end())
		return QueryResult(s, no_data, texts);
	else
		return QueryResult(s, loc->second, texts);
}
ostream &print(ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.line_NOs->size() << " times" << endl;
	for (auto i : *qr.line_NOs)
		os << "\t(line¡¡" << i + 1 << ")" << " " << (*qr.texts)[i] << endl;
	return os;
}
set<TextQuery::line_NO>::iterator QueryResult::begin() {
	return line_NOs->begin();
}
set<TextQuery::line_NO>::iterator QueryResult::end() {
	return line_NOs->end();
}
shared_ptr<vector<string>> QueryResult::get_file() {
	return texts;
}