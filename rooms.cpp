#include "rooms.h"

//Including raw data about rooms from outside rather than storing it here
//In order not to make a mess in .cpp file
std::vector<std::string> Rooms::roomsRaw
#include "room-database.txt"
;

//Main room database which should be initialized
std::vector<Room*> Rooms::database;


//Implementation of single method in Rooms class which fill the database
void Rooms::initialize() {
	for (auto& room : roomsRaw) {
		if (room.find("#105") != -1 || room.find("#106") != -1 || room.find("#107") != -1 || room.find("#108") != -1) {
			Rooms::database.push_back(new LectureRoom(room));
		}
		else if (room.find("University Room #1") != -1) { //The remaining rooms on the 1st floor aren't class rooms, therefore they're conference rooms
			Rooms::database.push_back(new ConferenceRoom(room, AccessLevel::BLUE));
		}
		else if (room.find("Lecture Room") != -1) { //These are actually small rooms for <= 60 people (for labs)
			Rooms::database.push_back(new ClassRoom(room));
		}
		else if (room.find("University Room #3") != -1) { //The rest that are not lecture and not class rooms are conference rooms
			Rooms::database.push_back(new ConferenceRoom(room));
		}
		else { //These are the high access level conference rooms on the 4th floor
			Rooms::database.push_back(new ConferenceRoom(room, AccessLevel::RED));
		}
	}
}