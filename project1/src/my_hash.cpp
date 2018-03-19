#include "my_hash.h"

My_Hash::My_Hash(int size){
        heros = std::vector<Superhero>(size);
}

My_Hash::~My_Hash(){
}

int My_Hash::hasher1(std::string name){
        int seed = 616;
        unsigned long hash = 0;
        for(int i = 0; i < name.length(); i++){
                hash = (hash * seed) + name[i];
        }
   return hash % heros.size();
}

int My_Hash::hasher2(std::string name){
	int seed = 420;
	unsigned long hash = 0;
	for(int i = 0; i < name.length(); i++){
		hash = name[0] + 27 * name[1] + seed * name[3];
	}
   return hash % heros.size();
}

