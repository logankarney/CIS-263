#include <string>

class Celebrity{

private:
	std::string name;
	int meet_value;
	std::string craft;
	bool has_met;

public:
	std::string get_name();
	
	int get_meet_value();

	std::string get_craft();
	
	bool get_has_met();

	void set_name(std::string name);

	void set_meet_value(int meet_value);

	void set_craft(std::string craft);

	void set_has_met(bool has_met);

	Celebrity& operator<(Celebrity other);
};
