#include <string>
#include "superhero.h"

Superhero::Superhero(){
}

Superhero::Superhero(int page_id, std::string name, std::string urlslug,
        std::string id, std::string alignment, char eye_color,
        char hair_color, char sex, std::string gsm, bool alive,
        int appearances, std::string first_appearance, int year){
	
	this -> page_id = page_id;
	this -> name = name;
	this -> urlslug = urlslug;
	this -> id = id;
	this -> alignment = alignment;
	this -> eye_color = eye_color;
	this -> hair_color = hair_color;
	this -> sex = sex;
	this -> gsm = gsm;
	this -> alive = alive;
	this -> appearances = appearances;
	this -> first_appearance = first_appearance;
	this -> year = year;
}

Superhero::~Superhero(){
}


/** Accessor methods */
int Superhero::get_page_id(){
	return page_id;
}

std::string Superhero::get_name(){
	return name;
}

std::string Superhero::get_urlslug(){
	return urlslug;
}

std::string Superhero::get_id(){
	return id;
}

std::string Superhero::get_alignment(){
	return alignment;
}

char Superhero::get_eye_color(){
	return eye_color;
}

char Superhero::get_hair_color(){
	return hair_color;
}

char Superhero::get_sex(){
	return sex;
}

std::string Superhero::get_gsm(){
	return gsm;
}

bool Superhero::get_alive(){
	return alive;
}

int Superhero::get_appearances(){
	return appearances;
}

std::string Superhero::get_first_appearance(){
	return first_appearance;
}

int Superhero::get_year(){
	return year;
}


/** Mutator methods */
void Superhero::set_page_id(int page_id){
	this -> page_id = page_id;
}

void Superhero::set_name(std::string name){
	this -> name = name;
}

void Superhero::set_urlslug(std::string urlslug){
	this -> urlslug = urlslug;
}

void Superhero::set_alignment(std::string alignment){
	this -> alignment = alignment;
}

void Superhero::set_eye_color(char eye_color){
	this -> eye_color = eye_color;
}

void Superhero::set_hair_color(char hair_color){
	this -> hair_color = hair_color;
}

void Superhero::set_sex(char sex){
	this -> sex = sex;
}

void Superhero::set_gsm(std::string gsm){
	this -> gsm = gsm;
}

void Superhero::set_alive(bool alive){
	this -> alive = alive;
}
void Superhero::set_appearances(int appearances){
	this -> appearances = appearances;
}

void Superhero::set_first_appearance(std::string first_appearance){
	this -> first_appearance = first_appearance;
}

void Superhero::set_year(int year){
	this -> year = year;
}

char Superhero::str_to_char(std::string s){
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


	return ' ';
}
