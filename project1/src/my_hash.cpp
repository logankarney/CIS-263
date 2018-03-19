#include "my_hash.h"

My_Hash::My_Hash(int size){
        heros = std::vector<Superhero>(size);
}

My_Hash::~My_Hash(){
	delete &heros;
}

int My_Hash::hasher1(std::string name){
        int seed = 616;
        unsigned long hash = 0;
        for(int i = 0; i < abs(name.length()); i++){
                hash = (hash * seed) + name[i];
        }
   return hash % heros.size();
}

