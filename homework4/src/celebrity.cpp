#include <string>
#include "celebrity.h"

Celebrity::Celebrity() {};

Celebrity::Celebrity(std::name, int meet_value, std::string craft, bool has_met) {
	this->name = name;
	this->meet_value = meet_value;
	this->craft = craft;
	this->has_met = has_met;
}

//Name accessor
std::string Celebrity::get_name() {
	return this->name;
}

//Meet value accessor
int Celebrity::get_meet_value() {
	return this->meet_value;
}

//Craft accessor
std::string Celebrity::get_craft() {
	return this->craft;
}

//Has met accessor
bool Celebrity::get_has_met() {
	return this-> has_met;
}

//Name mutator
void Celebrity::set_name(std::string name) {
	this->name = name;
}

//Meet value mutator
void Celebrity::set_meet_value(int meet_value) {
	this->meet_value = meet_value;
}

//Craft mutator
void Celebrity::set_craft(std::string craft) {
	this->craft = craft;
}

//Has met mutator
void Celebrity::set_has_met(bool has_met) {
	this->has_met = has_met;
}

//Override < operator
Celebrity& Celebrity::operator<(Celebrity other) {
	if(this->meet_value < other.meet_value)
		return *this;
	else if(this->meet_value == other.meet_value) {
		if(this->has_met < other.has_met)
			return *this;
		else if(this->has_met == other.has_met) {
			if(this->name.compare(other.name) > 0)
				return other;
			else
				return *this;
		}
		else
			return other;
	}
	else
		return other;
}

