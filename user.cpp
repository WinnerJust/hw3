#include <typeinfo>
#include <iostream>
#include "access_system.h"
#include "user.h"
class Room;

User::User(std::string name, std::string occupation, int age, AccessLevel accessibleLevel)
	: name(name), occupation(occupation), age(age), accessibleLevel(accessibleLevel) {}

std::string User::getName() {
	return name;
}

std::string User::getOccupation() {
	return occupation;
}

int User::getAge() {
	return age;
}

AccessLevel User::getAccessibleLevel() {
	return accessibleLevel;
}

void User::goToRoom(Room* room) {
	AccessSystem::sys.checkAccess(this, room);
}

void User::allowUser(User* user, Room* room) {
	//Checking if this is an Admin
	if (dynamic_cast<Admin*>(this)) {
		AccessSystem::sys.grantCustomAccess(user, room);
	} else {
		std::cout << "Request to change the access level of user denied. Not enough rights.\n";
	}
}

void User::forbidUser(User* user, Room* room) {
	//Checking if this is an Admin
	if (dynamic_cast<Admin*>(this)) {
		AccessSystem::sys.withdrawAccess(user, room);
	} else {
		std::cout << "Request to change the access level of user denied. Not enough rights.\n";
	}
}