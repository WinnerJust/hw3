#include "users.h"
#include "rooms.h"

//Including raw data about users from outside rather than storing it here
//In order not to make a mess in .cpp file
std::vector<userRaw> Users::usersRaw
#include "database.txt"
;

//Main user database which should be initialized
std::vector<User*> Users::database;



//Implementation of single method in Users class
void Users::initialize() {
	for (auto& user : Users::usersRaw) {
		//All substring which are to be found omit first letters to support upper and lower case

		//We provide directors with personal cabinets, as well as admins and professors
		if (user.occupation.find("ector") != -1) {
			Users::database.push_back(new Director(user.name, user.occupation, user.age));
			Rooms::database.push_back(new DirectorCabinet(user.name + "'s cabinet", Users::database.back()));
		}
		else if (user.occupation.find("dmin") != -1) {
			Users::database.push_back(new Admin(user.name, user.age));
			Rooms::database.push_back(new Cabinet(user.name + "'s cabinet", Users::database.back()));
		}
		else if (user.occupation.find("rofessor") != -1) {
			Users::database.push_back(new Professor(user.name, user.occupation, user.subject, user.age, user.subjYears));
			Rooms::database.push_back(new Cabinet(user.name + "'s cabinet", Users::database.back()));
		}
		else if (user.occupation.find("tudent") != -1) {
			Users::database.push_back(new Student(user.name, user.occupation, user.subject, user.age, user.subjYears));
		}
		else {
			//Others are lab employees
			Users::database.push_back(new Employee(user.name, user.occupation, user.subject, user.age, user.subjYears));
		}
	}
}