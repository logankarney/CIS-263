#include <stdlib.h>
#include <iostream>
#include "my_hash.h"
#include "superhero.h"

/*
 * Constructor
 *
 * @param size
 * 	instantiates vector with space for size elements
 * @param method
 * 	determines which hashing method will be used
 */
My_Hash::My_Hash(int size, char method){
	heros = std::vector<Superhero>(size);
	this -> method = method;
}

/*
 * Constuctor
 *
 * @param size
 * 	instantiates vector with space for size elements
 */
My_Hash::My_Hash(int size){
        heros = std::vector<Superhero>(size);
	
	//Default method to be used is hasher1
	this -> method = 'a';
}

/*
 * Default Destructor
 */
My_Hash::~My_Hash(){
	delete &heros;
}

/*
 * Method that inserts s into the vector
 *
 * @param s
 * 	Superhero object being added
 */
bool My_Hash::insert(const Superhero & s){
	
	//var used to determine whether the element was inserted without a collision
	bool rtn = true;

	Superhero tmp = s;

	unsigned int insertion_point;
	
	//Determines which hashing method is to be used
	if(method == 'c')
		insertion_point = hasher3(tmp.get_name());
	else if(method == 'b')
		insertion_point = hasher2(tmp.get_name());
	else
		insertion_point = hasher1(tmp.get_name());
	
	//Finds an empty element
	if(heros[insertion_point % heros.size()].get_name().compare("") == 0)
		heros[insertion_point % heros.size()] = tmp;
	else{
		//There was a collision
		rtn = false;

		while(heros[insertion_point % heros.size()].get_name().compare("") != 0){

		//Linear Probing
		insertion_point++;
		}
	}


	return rtn;
}

/*
 * Returns the matching Superhero object based off of name
 *
 * @param name
 * 	string used to compare the objects in the vector with
 */
Superhero & My_Hash::get(const std::string name){
	
	Superhero *rtn = new Superhero();
	
	unsigned int extraction_point;

	//Determines what hashing function was used
	if(method == 'c')
                extraction_point = hasher3(name);
        else if(method == 'b')
                extraction_point = hasher2(name);
        else
                extraction_point = hasher1(name);
	
	int start = extraction_point;

	while(heros[extraction_point % heros.size()].get_name().compare(name) != 0){
		extraction_point++;
	
		//breaks out of loop if name does not match any elements
		if(abs(extraction_point % heros.size()) == start){
			return *rtn;
		}
	}

	rtn = &heros[extraction_point];

	return *rtn;
}


//https://stackoverflow.com/questions/8317508/hash-function-for-a-string
/*
 *First hashing method
 *
 *@param name
 *	var used to create hash value
 */
int My_Hash::hasher1(std::string name){
        int sum = 0;
        for (int k = 0; k < abs(name.length()); k++){
                sum = sum + int(name[k]);
        }
        return sum % heros.size();
}

//https://stackoverflow.com/questions/8317508/hash-function-for-a-string
/*
 *Second hashing method
 *
 *@param name
 *	var used to create hash value
 */
int My_Hash::hasher2(std::string name){
        int seed = 616;
        unsigned long hash = 0;
        for(int i = 0; i < abs(name.length()); i++){
                hash = (hash * seed) + name[i];
        }
   return hash % heros.size();
}

/*
 *Third Hashing method
 *
 *@param name
 *	var used to create hash value
 */
int My_Hash::hasher3(std::string name){
	int seed = 420;
	unsigned long hash = 0;
	for(int i = 0; i < abs(name.length()); i++){
		hash = name[0] + 27 * name[1] + seed * name[3];
	}
   return hash % heros.size();
}

