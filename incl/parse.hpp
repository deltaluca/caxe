#pragma once
#include <string>
#include <iostream>
#include <caxe_util.hpp>
#include <lexer.hpp>
#include <token.hpp>
struct ParserResult {
	std::string file_name;
	 Dynamic  data;
	ParserResult();
	ParserResult(std::string& file_name, const  Dynamic & data);
};
std::ostream& operator<<(std::ostream&, const ParserResult&);
class Parser : public Thread {
	ref<tsDeque<ptr<Token> > > tokens;
	ref<tsDeque<ParserResult> > results;
	size_t run();
public:
	Parser();
	void init(tsDeque<ptr<Token> >& tokens, tsDeque<ParserResult>& results);
};
