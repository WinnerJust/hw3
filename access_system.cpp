#include <iostream>
#include "access_system.h"



//Implementing singleton
AccessSystem AccessSystem::sys = AccessSystem();



//There follows implementation of AccessSystem class

AccessSystem::AccessSystem() : logEnabled(true), emergencyStatus(false) {}

//The following two function enable and disable log to admin's console
void AccessSystem::enableLog() {
	logEnabled = true;
}

void AccessSystem::disableLog() {
	logEnabled = false;
}

void AccessSystem::activateEmergency() {
	emergencyStatus = true;
	if (logEnabled) {
		std::cout << "Attention! Emergency situation! Please, leave the building immediately using emergency exits.\n";
	}
}

void AccessSystem::deactivateEmergency() {
	emergencyStatus = false;
	if (logEnabled) {
		std::cout << "Emergency is cancelled.\n";
	}
}

bool AccessSystem::checkAccess(User* user, Room* room) {
	if (emergencyStatus) {
		if (logEnabled) {
			std::cout << "Emergency! " << user->getName() + " got temporary access to room " + room->getName() << '\n';
		}
		return true;
	}

	bool resp = false;
	
	//First check processes access levels
	if (room->getAccessLevel() == AccessLevel::NO_LEVEL) {
		resp = room->isAllowed(user);
	} else {
		resp = room->getAccessLevel() <= user->getAccessibleLevel();
	}

	//Second check is in ban list or in white list
	if (resp) {
		resp = !room->isBanned(user);
	} else {
		resp = room->isAllowed(user);
	}
	
	//Doing log if it's needed
	if (logEnabled) {
		if (resp) {
			std::cout << user->getName() + " got access to room " + room->getName() << '\n';
		} else {
			std::cout << user->getName() + " didn't get access to room " + room->getName() << '\n';
		}
	}

	return resp;
}

bool AccessSystem::grantCustomAccess(User* user, Room* room) {

	//Disabling log temporary for internal access check
	disableLog();
	bool resp = checkAccess(user, room);
	enableLog();

	//Granting access only if needed
	if (!resp) {
		room->unbanUser(user);
		room->addUser(user);
	}

	if (logEnabled) {
		if (!resp) {
			std::cout << user->getName() + " was granted a custom access to room " + room->getName() << '\n';
		}
		else {
			std::cout << user->getName() + " already has an access to room " + room->getName() << '\n';
		}
	}
	return !resp;
}

bool AccessSystem::withdrawAccess(User* user, Room* room) {

	//Disabling log temporary for internal access check
	disableLog();
	bool resp = checkAccess(user, room);
	enableLog();

	//Withdrawing access only if it wasn't done yet
	if (resp) {
		room->removeUser(user);
		room->banUser(user);
	}

	if (logEnabled) {
		if (resp) {
			std::cout << user->getName() + " was banned from room " + room->getName() << '\n';
		}
		else {
			std::cout << user->getName() + " already doesn't have an access to room " + room->getName() << '\n';
		}
	}
	return resp;
}

//Creates a user account directly from the admin console
//These accounts will not be written into the database (therefore they will be deleted after reboot of the Access System)
//Those are typically used for temporary pass cards that are to be used by guests or until the proper card is made
int AccessSystem::createUserAccount() {
	std::cout << "Sign up\n";
	std::cout << "Note: Access System can only register guest account.\n";
	std::cout << "To sign up as student or professor, please contact IT department.\n\n";
	std::cout << "Full name: ";

	std::string name;
	int age = 0, id;

	std::getline(std::cin, name);
	while (name.size() < 5 || name.find(" ") == -1) {
		std::cout << "Full name should consist at least of given name and family name. Please, try again.\n";
		std::cout << "Full name: ";
		std::getline(std::cin, name);
	}

	std::cout << "Age: ";
	
	std::cin >> age;
	while (age < 5 || age > 130) {
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "Please, enter proper age.\n";
		std::cout << "Age: ";
		std::cin >> age;
	}

	std::cin.clear();
	std::cin.ignore(INT32_MAX, '\n');

	Users::database.push_back(new Guest(name, age));

	id = Users::database.size() - 1;

	std::cout << "\nHello " << name << "! Your ID in system is " << id << '\n';

	return id;
}