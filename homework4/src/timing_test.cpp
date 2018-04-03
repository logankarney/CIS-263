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

	std::string crafts[] = {"Actor","Artisan", "GVSU Faculty", "Producer", "Writer", "Astronaut", "Body-Builder", "Stunt-Double", "Superhero", "Supervillain"};

	std::srand(time(NULL));	
	for(int i = 0; i < abs(arry.size()); i++){
		
		std::string name = "";
		int desire = 0;
		std::string craft = "";
		bool met = false;
			
		//Makes random name
		for(int j = 0; j < 8; j++){
			name += 'a' + std::rand() % 26;
		}
		name[0]=toupper(name[0]);
		
		//Makes random desire level
		desire = std::rand() % 11;
		
		//Chooses a random craft
		craft = crafts[std::rand() % sizeof(crafts)/sizeof(crafts[0])];

		//Makes random bool for met
		met = std::rand() % 2;	

		std::cout << name << std::endl;
		std::cout << desire << std::endl;
		std::cout << craft << std::endl;
		std::cout << met << std::endl << std::endl;
		
		//Celebrity *c = new Celebrity(name, desire, craft, met);
		//arry.push_back(*c);
		//delete(c);
	}

	//for(int i = 0; i < abs(arry.size()); i++){
		//std::cout << arry[1].get_name() << std::endl;
	//}
}
