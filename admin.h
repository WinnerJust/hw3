#pragma once

class Admin : public User {
public:
	Admin(std::string name, int age) : User(name, "", age, AccessLevel::RED) {}
};