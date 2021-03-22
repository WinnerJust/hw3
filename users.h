#pragma once
#include <vector>
#include "user.h"
#include "director.h"
#include "admin.h"
#include "employee.h"
#include "professor.h"
#include "student.h"
#include "guest.h"

//The format of raw data about users
struct userRaw {
	std::string name, occupation, subject;
	int age, subjYears;
};

class Users {
	static std::vector<userRaw> usersRaw;

public:
	static std::vector<User*> database;

	static void initialize();
};