#include <token.hpp>
#include <caxe_util.hpp>
#include <string>

ptr<Token> TOKEOS() { return ptr<Token>(new Token(-2)); }
ptr<Token> TOKEOF() { return ptr<Token>(new Token(-1)); }
ptr<Token> TOKSOF(const std::string& attr) {
	return ptr<Token>(new Token(-3,attr));
}

const std::string TOKSOF_data(ptr<Token> tok) { return tok->string_data; }
bool isTOKEOS(ptr<Token> tok) { return tok->id == -2; }
bool isTOKEOF(ptr<Token> tok) { return tok->id == -1; }

int INDEX(ptr<Token> tok) { return tok->id; }
