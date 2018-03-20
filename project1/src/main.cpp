#include <iostream>
#include <vector>
#include "my_hash.h"
#include "superhero.h"
#include "csv.h"

char str_to_char(std::string s, char type);

int main(){
	//Creation of vector
	//std::vector<Superhero> heros(17011);
	My_Hash* hash1 = new My_Hash(17011, 'a');
	My_Hash* hash2 = new My_Hash(17011, 'b');
	My_Hash* hash3 = new My_Hash(17011, 'c');

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

		//std::cout << in.next_line() << std::endl;	
		Superhero tmp(page_id, name, urlslug, id, alignment, ' ', ' ', ' ', gsm, ' ', appearances, first_appearance, year);		

		tmp.set_eye_color(str_to_char(eye_color_s, 'e'));
		tmp.set_hair_color(str_to_char(hair_color_s, 'h'));
		tmp.set_sex(str_to_char(sex_s, 's'));
		tmp.set_alive(str_to_char(alive_s, 'a'));

		//std::cout << hash -> insert(tmp) << std::endl;
		hash1 -> insert(tmp);
		hash2 -> insert(tmp);
		hash3 -> insert(tmp);

	}
	
}

bool insert(const Superhero & s){
	return true;
}

Superhero & get(const std::string name){
	Superhero* rtn = new Superhero();

	return *rtn;
}

char str_to_char(std::string s, char t){
	if(t == 'e'){
		/** eye_color  */
		if(s.compare("Hazel Eyes") == 0)
			return 'H';
		else if(s.compare("Blue Eyes") == 0)
			return 'B';
		else if(s.compare("Brown Eyes") == 0)
			return 'b';
		else if(s.compare("Green Eyes") == 0)
                	return 'G';
		else if(s.compare("Grey Eyes") == 0)
                	return 'g';
		else if(s.compare("Yellow Eyes") == 0)
                	return 'Y';
		else if(s.compare("Gold Eyes") == 0)
                	return 'U';
		else if(s.compare("Red Eyes") == 0)
                	return 'R';
		else if(s.compare("Black Eyeballs") == 0)
                	return 'd';
		else if(s.compare("Amber Eyes") == 0)
                	return 'A';
		else if(s.compare("Variable Eyes") == 0)
                	return 'V';
		else if(s.compare("Black Eyes") == 0)
                	return 'D';
		else if(s.compare("White Eyes") == 0)
                	return 'W';
		else if(s.compare("Orange Eyes") == 0)
                	return 'O';
		else if(s.compare("Silver Eyes") == 0)
                	return 'S';
		else if(s.compare("Purple Eyes") == 0)
                	return 'P';
		else if(s.compare("Pink Eyes") == 0)
                	return 'p';
		else if(s.compare("One Eye") == 0)
                	return 'o';
		else if(s.compare("Violet Eyes") == 0)
                	return 'v';
		else if(s.compare("Multiple Eyes") == 0)
                	return 'M';
		else if(s.compare("Magenta Eyes") == 0)
                	return 'm';
		else if(s.compare("Yellow Eyeballs") == 0)
                	return 'y';
		else if(s.compare("No Eyes") == 0)
                	return 'N';
		else if(s.compare("Compound Eyes") == 0)
                	return 'C';

	} else if(t == 'h'){
		/** hair color */
		if(s.compare("Brown Hair") == 0)
			 return 'B';
		 else if(s.compare("White Hair") == 0)
                	return 'W';
        	else if(s.compare("Black Hair") == 0)
                	return 'b';
        	else if(s.compare("Blonde Hair") == 0)
                	return 'l';
        	else if(s.compare("No Hair") == 0)
                	return 'n';
        	else if(s.compare("Blue Hair") == 0)
                	return 'q';
        	else if(s.compare("Red Hair") == 0)
                	return 'r';
        	else if(s.compare("Bald") == 0)
                	return 'd';
        	else if(s.compare("Auburn Hair") == 0)
                	return 'A';
        	else if(s.compare("Grey Hair") == 0)
                	return 'G';
        	else if(s.compare("Silver Hair") == 0)
                	return 'S';
        	else if(s.compare("Purple Hair") == 0)
                	return 'P';
        	else if(s.compare("Strawberry Blond Hair") == 0)
                	return 's';
        	else if(s.compare("Green Hair") == 0)
                	return 'g';
        	else if(s.compare("Reddish Brown Hair") == 0)
                	return 'R';
        	else if(s.compare("Gold Hair") == 0)
                	return 'a';
        	else if(s.compare("Orange Hair") == 0)
                	return 'O';
        	else if(s.compare("Pink Hair") == 0)
                	return 'p';
        	else if(s.compare("Variable Hair") == 0)
                	return 'v';
        	else if(s.compare("Yellow Hair") == 0)
                	return 'y';
        	else if(s.compare("Light Brown Hair") == 0)
                	return 'L';
        	else if(s.compare("Magenta Hair") == 0)
                	return 'M';
        	else if(s.compare("Bronze Hair") == 0)
                	return 'o';
        	else if(s.compare("Dyed Hair") == 0)
                	return 'd';
        	else if(s.compare("Orange-brown Hair") == 0)
                	return 'n';


	} else if(t == 's'){
		/** sex */
		if(s.compare("Male Characters") == 0)
			return 'M';
		else if(s.compare("Female Characters") == 0)
                	return 'F';
		else if(s.compare("Genderfluid Characters") == 0)
                	return 'G';
		else if(s.compare("Agender Characters") == 0)
                	return 'A';
	
	} else if(t == 'a'){
		/** alive */
		if(s.compare("Living Characters") == 0)
			return 'L';
		else if(s.compare("Deceased Characters") == 0)
			return 'D';
	}

	return ' ';
}
