#pragma once

class Employee : public User {
	std::string workSubject;
	int workingYears;

public:

	Employee(std::string name, std::string occupation, std::string workSubject, int age, int workingYears) 
		: User(name, occupation, age, AccessLevel::YELLOW), workingYears(workingYears), workSubject(workSubject) {}

	std::string getWorkSubject() {
		return workSubject;
	}

	int getWorkingYears() {
		return workingYears;
	}
};