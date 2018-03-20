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
	io::CSVReader<13, io::trim_chars<' '>, io::double_quote_escape<',', '\"'> > in("include/marvel-wikia-data.csv");
	
	//Variables in which the columns' data will be stored
	int page_id;
	std::string name;
	std::string urlslug;
	std::string id;
	std::string alignment;
	std::string eye_color_s;
	std::string hair_color_s;
	std::string sex_s;
	std::string gsm;
	std::string alive_s;
	int appearances;
	std::string first_appearance;
	int year;

	//Reads column header names
	in.read_header(io::ignore_no_column, "page_id", "name", "urlslug", "ID", "ALIGN", "EYE", "HAIR", "SEX", "GSM", "ALIVE", "APPEARANCES", "FIRST APPEARANCE", "Year");

	while(in.read_row(page_id, name, urlslug, id, alignment, eye_color_s, hair_color_s, sex_s, gsm, alive_s,appearances, first_appearance, year)){

		std::cout << in.next_line() << std::endl;	
		//std::cout << "EYE: " << eye_color_s << std::endl;
		

	}
	
}

bool insert(const Superhero & s){
	return true;
}

Superhero & get(const std::string name){
	Superhero* rtn = new Superhero();

	return *rtn;
}


