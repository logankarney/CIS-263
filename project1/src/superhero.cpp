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
