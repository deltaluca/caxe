#pragma once

#include <string>
#include <iostream>
#include <caxe_util.hpp>
struct TOKEN {
	char id;
	Dynamic data;
	TOKEN();
	TOKEN(char);
	TOKEN(char, const Dynamic&);
};
std::ostream& operator<<(std::ostream&,const TOKEN&);
class Lexer : public Thread {
	ref<tsDeque<ptr<TOKEN> > > tokens;
	ref<tsDeque<std::string> > files;
	size_t run();
	void lexfile(const std::string&, char**, int&);
public:
	Lexer();
	void init(tsDeque<std::string>&, tsDeque<ptr<TOKEN> >&);
};
