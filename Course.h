#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*************************** Course ***************************/
class Course {

protected:
	
	string name;
	vector<const Course*> prerequisites;

public:
	static int number_of_takers;
	
	Course(string name);
	~Course();
	Course(const Course& course);

	void addPrerequisite(const Course& course);
	friend ostream& operator<< (ostream& os, const Course& course);
};

/*************************** CourseInstance ***************************/
class CourseInstance : public Course {

	float grade;

public:
	CourseInstance(const Course& course);
};