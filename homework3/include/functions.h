#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <string>

class functions{

public:
	functions();
	functions(std::string input);
	~functions();

	bool balancedSymbols(std::string input);

	std::string iToP(std::string input);

private:
	//const std::string operators[];
	
	bool is_operator(std::string s);
	int precedence(std::string s);
	bool is_left(std::string s);
	bool is_right(std::string s);
};

#endif
