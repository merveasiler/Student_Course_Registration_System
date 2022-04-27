#pragma once

#include "Course.h"

/*************************** Student ***************************/
class Student {

	Student** horizontal;
	Student** vertical;
	vector<CourseInstance*> courses;

protected:
	int id;
	string fullname;
	string department;
	float gpa;

public:
	Student(int id, string fullname, string department);
	~Student();
	
	int getId();
	Student** getHorizontalTouchIns();
	Student** getVerticalTouchIns();
	void addCourse(const Course& course);
	void listCourses();
	void addTouchIn(Student* student, string dir);
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
