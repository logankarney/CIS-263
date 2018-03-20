#include <stdlib.h>
#include "my_hash.h"

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
	return true;
}

//Superhero & My_Hash::get(const std::string name){
//}


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

