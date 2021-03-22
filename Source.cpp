#include "access_system.h"

void testCase1() {
	Users::database[0]->goToRoom(Rooms::database[0]);
	Users::database[0]->forbidUser(Users::database[0], Rooms::database[0]);
	Users::database[0]->goToRoom(Rooms::database[0]);

	//Kirill Semenikhin is not an admin, so he cannot manipulate the access to rooms
}

void testCase2() {
	Users::database[0]->goToRoom(Rooms::database[0]);
	Users::database[0]->forbidUser(Users::database[0], Rooms::database[0]);
	Users::database[0]->goToRoom(Rooms::database[0]);
	Users::database[0]->allowUser(Users::database[0], Rooms::database[0]);
	Users::database[0]->goToRoom(Rooms::database[0]);

	//Again:
	//Kirill Semenikhin is not an admin, so he cannot manipulate the access to rooms
}

void testCase3() {
	Users::database[1]->goToRoom(Rooms::database[0]);
	//Tormasov Alexander Gennadievich is not allowed to visit Kirill Semenikhin's cabinet
	Users::database[2]->allowUser(Users::database[1], Rooms::database[0]);
	//Unless he is invited
	Users::database[1]->goToRoom(Rooms::database[0]);

	Users::database[1]->goToRoom(Rooms::database[10]);
	Users::database[1]->goToRoom(Rooms::database[20]);
	//But still, Tormasov Alexander Gennadievich cannot visit other professors' cabinets

	Users::database[1]->goToRoom(Rooms::database[30]);
	//But he can visit reading hall

	Users::database[2]->forbidUser(Users::database[1], Rooms::database[30]);
	Users::database[1]->goToRoom(Rooms::database[30]);
	//LOL, but now he can't

	Users::database[2]->forbidUser(Users::database[1], Rooms::database[30]);
	Users::database[1]->goToRoom(Rooms::database[30]);
	//He is already banned! Admin, calm down!

	Users::database[5]->allowUser(Users::database[1], Rooms::database[30]);
	Users::database[1]->goToRoom(Rooms::database[30]);
	//Finally, other admin put the things in order
}

void testCase4() {
	Users::database[50]->goToRoom(Rooms::database[0]);

	Users::database[2]->forbidUser(Users::database[50], Rooms::database[0]);
	Users::database[50]->goToRoom(Rooms::database[0]);

	Users::database[5]->allowUser(Users::database[50], Rooms::database[0]);
	Users::database[50]->goToRoom(Rooms::database[0]);

	//Another candidate to enter Kirill Semenikhin's cabinet
}

void testCase5() {
	Users::database[59]->goToRoom(Rooms::database[36]);

	Users::database[2]->forbidUser(Users::database[59], Rooms::database[36]);
	Users::database[59]->goToRoom(Rooms::database[36]);

	Users::database[5]->allowUser(Users::database[59], Rooms::database[36]);
	Users::database[59]->goToRoom(Rooms::database[36]);

	//Admin is just playing
}


void testCase6() {
	Users::database[50]->goToRoom(Rooms::database[36]);
	Users::database[2]->forbidUser(Users::database[50], Rooms::database[36]);
	Users::database[50]->goToRoom(Rooms::database[36]);
	Users::database[2]->allowUser(Users::database[50], Rooms::database[36]);
	Users::database[50]->goToRoom(Rooms::database[36]);

	//Admin is just playing one more time

	Users::database[50]->forbidUser(Users::database[50], Rooms::database[36]);
}

//Test cases after access system update!

void testCase7() {
	Users::database[58]->goToRoom(Rooms::database[42]);
	//Employee cannot get access to conference room on the second floor
	//Everything's okay

	AccessSystem::sys.activateEmergency();
	Users::database[58]->goToRoom(Rooms::database[42]);
	//Oh, no! Emergency! Now he can enter it!

	Users::database[58]->goToRoom(Rooms::database[0]);
	//And even Kirill Semenikhin's cabinet

	Users::database[0]->goToRoom(Rooms::database[42]);
	//Kirill Semenikhin still can access some random room

	AccessSystem::sys.deactivateEmergency();
	Users::database[58]->goToRoom(Rooms::database[42]);
	Users::database[58]->goToRoom(Rooms::database[0]);
	//Now everything as it is supposed to be

	Users::database[0]->goToRoom(Rooms::database[42]);
}

void testCase8() {
	//Creating a user and checking its access to different rooms (and also during the emergency)
	int userID = AccessSystem::sys.createUserAccount();

	Users::database[userID]->goToRoom(Rooms::database[45]);
	Users::database[userID]->goToRoom(Rooms::database[31]);
	Users::database[userID]->goToRoom(Rooms::database[0]);
	Users::database[userID]->goToRoom(Rooms::database[35]);
	Users::database[userID]->goToRoom(Rooms::database[40]);

	AccessSystem::sys.activateEmergency();

	Users::database[userID]->goToRoom(Rooms::database[45]);
	Users::database[userID]->goToRoom(Rooms::database[31]);
	Users::database[userID]->goToRoom(Rooms::database[0]);
	Users::database[userID]->goToRoom(Rooms::database[35]);
	Users::database[userID]->goToRoom(Rooms::database[40]);

	AccessSystem::sys.deactivateEmergency();

	Users::database[userID]->goToRoom(Rooms::database[45]);
	Users::database[userID]->goToRoom(Rooms::database[31]);
	Users::database[userID]->goToRoom(Rooms::database[0]);
	Users::database[userID]->goToRoom(Rooms::database[35]);
	Users::database[userID]->goToRoom(Rooms::database[40]);

	//Just in case, trying to add another user
	userID = AccessSystem::sys.createUserAccount();
}



int main() {
	//These are required before using Access System
	Users::initialize();
	Rooms::initialize();
	
	//You can try 1-8 example cases
	testCase8();

	return 0;
}