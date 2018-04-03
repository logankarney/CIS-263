#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include "celebrity.h"

void create(int size);

int main(int c, char *argv[]){
	if(c == 2){
		//https://stackoverflow.com/questions/2797813/
		//how-to-convert-a-command-line-argument-to-int
		std::istringstream iss(argv[1]);
		int size;
		if(iss >> size){
			create(size);
			return 0;
		}
	}

	return 1;
}

void create(int size){
	std::vector<Celebrity> arry(size);
}
