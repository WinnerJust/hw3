#pragma once
#include "access_level.h"

class Cabinet : public Room {
public:
	Cabinet(std::string name, User* owner) : Room(name, AccessLevel::NO_LEVEL) {
		this->addUser(owner);
	}
};