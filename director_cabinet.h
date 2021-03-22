#pragma once
#include "access_level.h"

class DirectorCabinet : public Cabinet {
public:
	DirectorCabinet(std::string name, User* owner) : Cabinet(name, owner) {}
};