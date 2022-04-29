#pragma once

#include "Course.h"

/*************************** Student ***************************/
class Student {

protected:
	int id;
	string fullname;
	string department;
	float gpa;

	vector<CourseInstance*> courses;

public:
	Student(int id, string fullname, string department);
	~Student();
	
	int getId();
	void addCourse(const Course& course);
	void listCourses();
	friend ostream& operator<< (ostream& os, const Student& student);

};

/*************************** Freshman ***************************/
class Freshman : public Student {

	

public:
	Freshman(int id, string fullname, string department);
	~Freshman();
};

/*************************** Sophomore ***************************/
class Sophomore : public Freshman {

public:
	Sophomore(int id, string fullname, string department);
	~Sophomore();
};
