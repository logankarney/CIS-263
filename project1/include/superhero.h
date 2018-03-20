#ifndef SUPERHERO_H_
#define SUPERHERO_H_

#include <string>

class Superhero
{
public:
	/*
 	Constructors
 	*/
	Superhero();
	
	Superhero(int page_id, std::string name, std::string urlslug,
        std::string id, std::string alignment, char eye_color,
        char hair_color, char sex, std::string gsm, bool alive,
        int appearances, std::string first_appearance, int year);


      	/*
        Destructor      
        */
	~Superhero();

	
	/** Accessor methods */
	int get_page_id();
	std::string get_name();
	std::string get_urlslug();
	std::string get_id();
	std::string get_alignment();
	char get_eye_color();
	char get_hair_color();
	char get_sex();
	std::string get_gsm();
	bool get_alive();
	int get_appearances();
	std::string get_first_appearance();
	int get_year();


	/** Mutator methods */
	void set_page_id(int page_id);
	void set_name(std::string name);
	void set_urlslug(std::string urlslug);
	void set_alignment(std::string alignment);
	void set_eye_color(char eye_color);
	void set_hair_color(char hair_color);
	void set_sex(char sex);
	void set_gsm(std::string gsm);
	void set_alive(bool alive);
	void set_appearances(int appearances);
	void set_first_appearance(std::string first_appearance);
	void set_year(int year);

private:

	char str_to_char(std::string s);

	/** Instance variables */
	int page_id;
	std::string name;
	std::string urlslug;
	std::string id;
	std::string alignment;
	char eye_color;
	char hair_color;
	char sex;
	std::string gsm;
	bool alive;
	int appearances;
	std::string first_appearance;
	int year;
};

#endif
