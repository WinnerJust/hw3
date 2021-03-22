#pragma once

class Guest : public User {
public:
	Guest(std::string name, int age) : User(name, "", age, AccessLevel::BLUE) {}
};