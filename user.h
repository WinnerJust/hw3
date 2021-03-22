#pragma once
#include <string>
#include "access_level.h"
class Room;

class User {
protected:
	std::string name;
	std::string occupation;
	int age;
	AccessLevel accessibleLevel;

public:
	User(std::string name, std::string occupation, int age, AccessLevel accessibleLevel);

	//Getters
	std::string getName();
	std::string getOccupation();
	int getAge();
	AccessLevel getAccessibleLevel();

	//Actions
	void goToRoom(Room* room);
	virtual void allowUser(User* user, Room* room);
	virtual void forbidUser(User* user, Room* room);
	//Making the last two virtual is order for dynamic_cast to work
};
