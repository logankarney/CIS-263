#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "celebrity.h"

void create(int size, std::vector<Celebrity> *arry);

int main(int c, char *argv[]){
	if(c == 2){
		//https://stackoverflow.com/questions/2797813/
		//how-to-convert-a-command-line-argument-to-int
		std::istringstream iss(argv[1]);
		int size;
		std::vector<Celebrity> *arry = new std::vector<Celebrity>(size);
		if(iss >> size){
			create(size, arry);

			for(Celebrity c : *arry){
				std::cout << c.get_name() << std::endl;
			}
		}

	}

	return 1;
}

void create(int size, std::vector<Celebrity> *arry){
	//std::vector<Celebrity> arry(size);

	std::string crafts[] = {"Actor","Artisan", "GVSU Faculty", "Producer", "Writer", "Astronaut", "Body-Builder", "Stunt-Double", "Superhero", "Supervillain"};

	std::srand(time(NULL));	
	for(int i = 0; i < size; i++){
		
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

		
		Celebrity c;

		c.set_name(name);
		c.set_meet_value(desire);
		c.set_craft(craft);
		c.set_meet_value(met);

		arry -> push_back(c);
	}
	
}
