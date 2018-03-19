#ifndef MY_HASH_H_
#define MY_HASH_H_

#include <string>
#include <vector>
#include "superhero.h"

class My_Hash{
public:
	/*
   	Constructors
   	*/
	My_Hash(int size);

	My_Hash();

	~My_Hash();

	bool insert(const Superhero & s);
	Superhero & get(const std::string name);

private:
	int hasher1(std::string name);
	int hasher2(std::string name);

	/** Array used to store hashed elements */
	std::vector<Superhero> heros;
};

#endif
