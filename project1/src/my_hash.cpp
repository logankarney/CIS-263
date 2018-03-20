#include <stdlib.h>
#include <iostream>
#include "my_hash.h"
#include "superhero.h"

My_Hash::My_Hash(int size, char method){
	heros = std::vector<Superhero>(size);
	this -> method = method;
}

My_Hash::My_Hash(int size){
        heros = std::vector<Superhero>(size);

	this -> method = 'a';
}

My_Hash::~My_Hash(){
	delete &heros;
}

bool My_Hash::insert(const Superhero & s){
	
	bool rtn = true;

	Superhero tmp = s;

	unsigned int insertion_point;

	if(method == 'c')
		insertion_point = hasher3(tmp.get_name());
	else if(method == 'b')
		insertion_point = hasher2(tmp.get_name());
	else
		insertion_point = hasher1(tmp.get_name());


	if(heros[insertion_point % heros.size()].get_name().compare("") == 0)
		heros[insertion_point % heros.size()] = tmp;
	else{
		rtn = false;

		while(heros[insertion_point % heros.size()].get_name().compare("") != 0){

		//Probing
		insertion_point++;
		}
	}


	return rtn;
}

Superhero & My_Hash::get(const std::string name){
	
	Superhero *rtn = new Superhero();
	
	unsigned int extraction_point;

	if(method == 'c')
                extraction_point = hasher3(name);
        else if(method == 'b')
                extraction_point = hasher2(name);
        else
                extraction_point = hasher1(name);
	
	int start = extraction_point;

	while(heros[extraction_point % heros.size()].get_name().compare(name) != 0){
		extraction_point++;
		if(abs(extraction_point % heros.size()) == start){
			return *rtn;
		}
	}

	rtn = &heros[extraction_point];

	return *rtn;
}


//https://stackoverflow.com/questions/8317508/hash-function-for-a-string
int My_Hash::hasher1(std::string name){
        int sum = 0;
        for (int k = 0; k < abs(name.length()); k++){
                sum = sum + int(name[k]);
        }
        return sum % heros.size();
}

//https://stackoverflow.com/questions/8317508/hash-function-for-a-string
int My_Hash::hasher2(std::string name){
        int seed = 616;
        unsigned long hash = 0;
        for(int i = 0; i < abs(name.length()); i++){
                hash = (hash * seed) + name[i];
        }
   return hash % heros.size();
}

int My_Hash::hasher3(std::string name){
	int seed = 420;
	unsigned long hash = 0;
	for(int i = 0; i < abs(name.length()); i++){
		hash = name[0] + 27 * name[1] + seed * name[3];
	}
   return hash % heros.size();
}

