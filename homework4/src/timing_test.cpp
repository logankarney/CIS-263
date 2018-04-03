#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
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

	std::srand(time(NULL));	
	for(int i = 0; i < abs(arry.size()); i++){
		
		std::string name = "";
		int desire = 0;
		bool met = false;
			
		//Makes random name
		for(int j = 0; j < 8; j++){
			name += 'a' + std::rand() % 26;
		}
		name[0]=toupper(name[0]);
		
		//Makes random desire level
		desire = std::rand() % 11;
		
		//Makes random bool for met
		met = std::rand() % 2;	

	}
}
