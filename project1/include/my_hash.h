#ifndef MY_HASH_H_
#define MY_HASH_H_

#include <string>
#include "superhero.h"

class my_hash{
public:
	bool insert(const Superhero & s);
	Superhero & get(const std::string name);

private:
	//three private hash methods
};

#endif
