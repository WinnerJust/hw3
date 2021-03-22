#pragma once
#include <vector>
#include "users.h"
#include "rooms.h"

class AccessSystem {
	bool logEnabled;
	bool emergencyStatus;

	//Constructor is private but callable in static member initialization
	//Perfect for singleton
	AccessSystem();

public:

	static AccessSystem sys;

	void enableLog();
	void disableLog();
	void activateEmergency();
	void deactivateEmergency();
	bool checkAccess(User* user, Room* room);
	bool grantCustomAccess(User* user, Room* room);
	bool withdrawAccess(User* user, Room* room);
	int createUserAccount();
};