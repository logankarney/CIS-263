#include <iostream>
#include <vector>
#include "my_hash.h"
#include "superhero.h"
#include "csv.h"

int main(){
	//Creation of vector
	//std::vector<Superhero> heros(17011);
	My_Hash* hash = new My_Hash(17011);

	//Loads the file
	io::CSVReader<13, io::trim_chars<' '>, io::double_quote_escape<',', '\n'> > in("include/marvel-wikia-data.csv");
	
	//Variables in which the columns' data will be stored
	int page_id;
	std::string name;
	std::string urlslug;
	std::string id;
	std::string alignment;
	std::string eye_color;
	std::string hair_color;
	std::string sex;
	std::string gsm;
	std::string alive;
	int appearances;
	std::string first_appearance;
	int year;

	//Reads column header names
	in.read_header(io::ignore_no_column, "page_id", "name", "urlslug", "ID", "ALIGN", "EYE", "HAIR", "SEX", "GSM", "ALIVE", "APPEARANCES", "FIRST APPEARANCE", "Year");

	while(in.read_row(page_id, name, urlslug, id, alignment, eye_color, hair_color, sex, gsm, alive ,appearances, first_appearance, year)){

		//std::cout << in.next_line() << std::endl;	
		//std::cout << "NAME: " << name << std::endl;

	}
	
}

bool insert(const Superhero & s){
	return true;
}

Superhero & get(const std::string name){
	Superhero* rtn = new Superhero();

	return *rtn;
}


