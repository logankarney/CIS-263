#define CATCH_CONFIG_MAIN
#include <string>
#include <stack>
#include <iostream>
#include "functions.h"

int main(){
	std::string input = "a + b * c + d ";
	input = " A + B + C + D ";
	input = "a + b * c + ( d * e + f ) * g ";

	functions f;

	//char ay[] = {'9', '8'};
	
	//f.precedence('c', inputs);

	//int size = sizeof(inputs)/sizeof(inputs[0]);

	/*std::cout << std::endl;
	for(int i = 0; i < size; i++){
		std::cout << inputs[i] << std::endl << f.balancedSymbols(inputs[i]) << std::endl << std::endl;
	}*/
	if(input[input.size()-1] != ' ')
		input += " ";

	std::cout << std::endl << "Infix:   "<< input << std::endl << "Postfix: " << f.iToP(input) << std::endl << std::endl;
}

functions::functions(){
}

functions::~functions(){
}

bool functions::balancedSymbols(std::string input){
	std::stack<char> pile;
        char left[] = {'(', '[', '{' };
        char right[] = {')', ']', '}'};

	int size = sizeof(input)/sizeof(input[0]);

       for(char c : input){
                for(int i = 0; i < size; i++){
                        if(c == left[i]){
                                pile.push(c);
                        } else if ( c == right[i]){
                                if(pile.size() == 0 || pile.top() != left[i]){
                                        //std::cout << "Error, unbalanced input" << std::endl;
                                        return false;
                                }
                                pile.pop();
                        }
                } 
        }
	return true;
}

std::string functions::iToP(std::string input){
	std::stack<std::string> pile;
	std::string output;

	//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	std::string delimiter = " ";
	std::string token;

	size_t element = 0;
	int counter = 0;

	while((element = input.find(delimiter)) != std::string::npos){
		token = input.substr(0, element);

		if(is_operator(token)){
			//std::cout << "operator " << token << std::endl;
			
			//right parenthesis
			if(precedence(token) == 0){
				while(pile.size() != 0 && !is_left(pile.top())){
					output += pile.top() + " ";
					pile.pop();
				}
				//pile.pop();
			}			

			else if(pile.size() == 0 || precedence(pile.top()) < precedence(token))
				pile.push(token);
			else{
				//handles when the top of the pile has a higher or equal precedence than the current "token" operator
				int size_copy = pile.size();
				while(size_copy != 0){
					if(!is_left(pile.top())){
						output += pile.top() + " ";
						pile.pop();
					}
					
					size_copy--;
				}
				pile.push(token);
			}
		}
		else{
			//std::cout << "operand " << token << std::endl;
			if(token.compare(" ") != 0)
				output += token + " ";
		}

		input.erase(0, element + delimiter.length());
		counter++;
	}

	for(int i = 0; (i = pile.size()); i++){
		if(!is_left(pile.top()))
			output += pile.top() + " ";
		pile.pop();
	}

	
	return output;
}

bool functions::is_operator(std::string s){	
	//ADD BRACKETS
	std::string operators[] = {"(", ")", "{", "}", "[", "]", "*", "/", "+", "-"};

	for(std::string o : operators){
		if( s.compare(o) == 0)
			return true;
	}
	return false;
}

int functions::precedence(std::string s){

	if(is_left(s))
		return 3;
	else if(s.compare("*") == 0 || s.compare("/") == 0)
		return 2;
	else if(s.compare("+") == 0 || s.compare("-") == 0)
		return 1;
	else if(is_right(s))
		return 0;

	return -1;
}

bool functions::is_left(std::string s){
	if(s.compare("(") == 0 || s.compare("{") == 0 || s.compare("[") == 0)
                return true;
	return false;
}

bool functions::is_right(std::string s){
	if(s.compare(")") == 0 || s.compare("}") == 0 || s.compare("]") == 0)
                return true;
	return false;
}

