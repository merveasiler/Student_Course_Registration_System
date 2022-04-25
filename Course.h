#pragma once

#include <string>
#include <vector>

using namespace std;

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

};

class CourseInstance : public Course {

public:
	CourseInstance(const Course& course);
};