#pragma once
#include <vector>
#include <string>
#include "access_level.h"
#include "user.h"

class Room {
protected:
	std::string name;
	AccessLevel accessLevel;
	std::vector<User*> allowedUsers;
	std::vector<User*> bannedUsers;

	void addUser(User* newUser) {
		allowedUsers.push_back(newUser);
	}

	void removeUser(User* userToRemove) {
		auto pos = std::find(allowedUsers.begin(), allowedUsers.end(), userToRemove);
		if (pos != allowedUsers.end()) {
			allowedUsers.erase(pos);
		}
	}

	void banUser(User* toBanUser) {
		bannedUsers.push_back(toBanUser);
	}

	void unbanUser(User* toUnbanUser) {
		auto pos = std::find(bannedUsers.begin(), bannedUsers.end(), toUnbanUser);
		if (pos != bannedUsers.end()) {
			bannedUsers.erase(pos);
		}
	}

	bool isAllowed(User* user) {
		return std::find(this->allowedUsers.begin(), this->allowedUsers.end(), user) != this->allowedUsers.end();
	}

	bool isBanned(User* user) {
		return std::find(this->bannedUsers.begin(), this->bannedUsers.end(), user) != this->bannedUsers.end();
	}

public:
	Room(std::string name, AccessLevel accessLevel) : name(name), accessLevel(accessLevel) {}

	std::string getName() {
		return name;
	}

	AccessLevel getAccessLevel() {
		return accessLevel;
	}

	friend class AccessSystem;
};