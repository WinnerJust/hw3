#pragma once
#include "access_level.h"

class ClassRoom : public Room {
public:
	ClassRoom(std::string name, AccessLevel access = AccessLevel::GREEN) : Room(name, access) {}
};