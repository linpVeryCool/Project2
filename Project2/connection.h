#include<string>
struct connection {
	std::string *suc = new std::string("success");
	std::string *fail = new std::string("fail");
	
};
void disconnect(connection *c) {
	delete c->suc;
	delete c->fail;
}