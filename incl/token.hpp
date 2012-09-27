#pragma once

#include <caxe_util.hpp>
#include <string>

enum TOKID {
	tIdent,tString,tRegExp,tInteger,tFloater,
	tMScope,tMBrack,
	tLBrace, tRBrace, tLParen, tRParen, tComma,
	tDot, tSemi, tArrow, tSlash, tDollar,
	tCons,
	tPackage, tImport, tDefine, tMixin, tExpand, tStr,
	tGlobal, tFile, tLocal, tObject, tMethod,
	tNoise,
    tDoc, tDocStr
};

struct Token {
	int id;
	std::string string_data;
	int int_data;

	Token(int id):id(id) {}
	Token(int id, const std::string& str):id(id),string_data(str) {}
	Token(int id, int idat):id(id),int_data(idat) {}
};

ptr<Token> TOKEOS();
ptr<Token> TOKEOF();
ptr<Token> TOKSOF(const std::string&);

const std::string TOKSOF_data(ptr<Token>);
bool isTOKEOS(ptr<Token>);
bool isTOKEOF(ptr<Token>);

int INDEX(ptr<Token>);
