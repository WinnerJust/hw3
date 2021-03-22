#pragma once
#include "room.h"
#include "class_room.h"
#include "lecture_room.h"
#include "cabinet.h"
#include "conference_room.h"
#include "director_cabinet.h"

class Rooms {
	static std::vector<std::string> roomsRaw;

public:
	static std::vector<Room*> database;

	static void initialize();
};