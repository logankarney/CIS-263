#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "my_hash.h"
#include "superhero.h"

int main(){
	//creation of vector
	std::vector<Superhero> heros(17011);

	//http://www.cplusplus.com/forum/general/17771/
	std::ifstream infile( "include/marvel-wikia-data.csv");	
	
	if(infile == NULL){
		std::cout << "Error loading file" << std::endl;
		return 1;
	}	


	while(infile){
		std::string s;
		
		//terminates loop when the csv runs out of input lines
		//sets s to next line
		if (!getline( infile, s )) 
			break;
		
		//TODO: use s to  input data into superhero vector, add to heros
		//std::cout << s << std::endl << std::endl;

	}

	return 0;
}
