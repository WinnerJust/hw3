#pragma once

class Student : public User {
	std::string favouriteSubject;
	int studyYears;

public:

	Student(std::string name, std::string occupation, std::string favouriteSubject, int age, int studyYears) 
		: User(name, occupation, age, AccessLevel::GREEN), studyYears(studyYears), favouriteSubject(favouriteSubject) {}

	std::string getFavouriteSubject() {
		return favouriteSubject;
	}

	int getStudyYears() {
		return studyYears;
	}
};