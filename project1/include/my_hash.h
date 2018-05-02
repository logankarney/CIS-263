#ifndef MY_HASH_H_
#define MY_HASH_H_

#include <string>
#include <vector>
#include "superhero.h"

/*
 * Hashing class for Superhero objects
 *
 * @author Logan Karney, George Daudlin
 * @version Winter 2018
 */
class My_Hash{
public:
	/*
   	Constructors
   	*/
	My_Hash(int size, char method);
	
	My_Hash(int size);

	My_Hash();

	/*
 	Default Destructor
 	*/
	~My_Hash();

	/** Inserts s into the vector  */
	bool insert(const Superhero & s);

	/** returns a Superhero reference based on name  */
	Superhero & get(const std::string name);

private:
	/** hashing methods  */
	int hasher1(std::string name);
	int hasher2(std::string name);
	int hasher3(std::string name);

	/** Array used to store hashed elements */
	std::vector<Superhero> heros;
	
	/** determins which hashing function is being used  */
	char method;
};

#endif
