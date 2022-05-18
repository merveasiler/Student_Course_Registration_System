#ifndef __COURSE_H__
#define __COURSE_H__


#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Student;

//////////////////////////////////////////////////////
//    DO NOT CHANGE *PUBLIC PARTS* IN THIS FILE!    //
//////////////////////////////////////////////////////

enum Grade {
	AA,
	BA,
	BB,
	CB,
	CC,
	DC,
	DD,
	FF,
	NA,
	S,
	U
};

/****************************************************/
/****               *** COURSE ***               ****/
class Course {

protected:
	
	static string name;
	static vector<const Course*> prerequisites;
	static vector<vector<const Student*>> all_course_takers;

public:
	Course(string name, int term);
	~Course();

	void addPrerequisite(const Course& course);
	const vector<const Course*> getPrerequisites() const;
	string getName() const;
	bool operator== (const Course&) const;
	//friend ostream& operator<< (ostream& os, const Course& course);
};

/****************************************************/
/****             *** OPEN COURSE ***            ****/
class OpenCourse : public Course {

protected:

	static int term;
	static int quota;
	static vector<const Student*> course_takers;

public:
	OpenCourse(const Course&, int, int);
	~OpenCourse();

};


/****************************************************/
/****          *** COURSE INSTANCE ***           ****/
class CourseInstance : public OpenCourse {

	Grade grade;

public:
	CourseInstance(const OpenCourse& course, Student& student);
	void setGrade(Grade);
	Grade getGrade();

};

#endif

