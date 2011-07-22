#pragma once
#include <string>
#include <iostream>
#include <caxe_util.hpp>
#include <lexer.hpp>
struct ParserResult {
	std::string file_name;
	Dynamic data;
	ParserResult();
	ParserResult(std::string& file_name, const Dynamic& data);
};
std::ostream& operator<<(std::ostream&, const ParserResult&);
class Parser : public Thread {
	ref<tsDeque<ptr<TOKEN> > > tokens;
	ref<tsDeque<ParserResult> > results;
	int run();
public:
	Parser();
	void init(tsDeque<ptr<TOKEN> >& tokens, tsDeque<ParserResult>& results);
};
