#pragma once

#include "Course.h"

class Student {

protected:
	int id;
public:
	Student(int id, string fullname);
	~Student();
	void listCourses();
	void addCourse();

};

class Freshman : public Student {

	

public:
	Freshman();
	~Freshman();

};

class Sophomore : public Freshman {

public:
	Sophomore();
	~Sophomore();
};
