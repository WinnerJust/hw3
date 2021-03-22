#pragma once

class Professor : public User {
	std::string teachingSubject;
	int teachingYears;

public:

	Professor(std::string name, std::string occupation, std::string teachingSubject, int age, int teachingYears)
		: User(name, occupation, age, AccessLevel::RED), teachingYears(teachingYears), teachingSubject(teachingSubject) {}

	std::string getTeachingSubject() {
		return teachingSubject;

	}
	int getTeachingYears() {
		return teachingYears;
	}
};