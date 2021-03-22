#pragma once

class Director : public User {
	std::string position;

public:
	Director(std::string name, std::string position, int age) : User(name, "", age, AccessLevel::RED), position(position) {}

	std::string getPosition() {
		return position;
	}
};