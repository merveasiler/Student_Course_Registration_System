#ifndef __STUDENT_H__
#define __STUDENT_H__


#include "Course.h"

//////////////////////////////////////////////////////
//    DO NOT CHANGE *PUBLIC PARTS* IN THIS FILE!    //
//////////////////////////////////////////////////////

Grade learnGrade(string course_name, int student_id);

/****************************************************/
/****               *** STUDENT ***              ****/
class Student {

protected:
	const int id;
	const string fullname;
	const string department;
	float gpa;

	vector<CourseInstance*> courses;

public:
	Student(int id, string fullname, string department);
	~Student();	
	int getId();
	void listCourses();
	friend ostream& operator<< (ostream& os, const Student& student);

};

/****************************************************/
/****              *** FRESHMAN ***              ****/
class Freshman : public Student {

protected:
	

public:
	Freshman(int id, string fullname, string department);
	~Freshman();
	bool addCourse(const OpenCourse&);
	void gradeCourse(CourseInstance& courseInstance);

};

/****************************************************/
/****              *** SOPHOMORE ***             ****/
class Sophomore : public Freshman {

protected:
	bool internship1;

public:
	Sophomore(int id, string fullname, string department);
	~Sophomore();
	void doAnInternship();
};

/****************************************************/
/****                *** JUNIOR ***              ****/
class Junior : public Sophomore {

	bool internship2;
	vector<CourseInstance*> electives;

public:
	Junior(int id, string fullname, string department);
	~Junior();
	void selectElectiveCourse();
};

/****************************************************/
/****                *** SENIOR ***              ****/
class Senior : public Junior {

	bool graduation;

public:
	Senior(int id, string fullname, string department);
	~Senior();
	bool graduate();
};

#endif

