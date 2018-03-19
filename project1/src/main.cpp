#include <iostream>
#include <vector>
#include "my_hash.h"
#include "superhero.h"
#include "csv.h"

int main(){
	//creation of vector
	//std::vector<Superhero> heros(17011);
	My_Hash* hash = new My_Hash(17011);

	//http://www.cplusplus.com/forum/general/17771/	
	io::CSVReader<13, trim_chars<','>> in("marvel-wikia-data.csv");

	
	
}

bool insert(const Superhero & s){
	return true;
}

Superhero & get(const std::string name){
	Superhero* rtn = new Superhero();

	return *rtn;
}


