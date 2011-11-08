#pragma once

#include <string>
#include <iostream>
#include <caxe_util.hpp>
#include <token.hpp>
class Lexer : public Thread {
	ref<tsDeque<ptr<Token> > > tokens;
	ref<tsDeque<std::string> > files;
	size_t run();
	void lexfile(const std::string&, char**, int&);
public:
	Lexer();
	void init(tsDeque<std::string>&, tsDeque<ptr<Token> >&);
};
