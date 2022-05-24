#ifndef __METU_H__
#define __METU_H__


#include "Course.h"
#include "Student.h"

//////////////////////////////////////////////////////
//    DO NOT CHANGE *PUBLIC PARTS* IN THIS FILE!    //
//////////////////////////////////////////////////////

/****************************************************/
/****                *** METU ***                ****/

class Metu {

	vector<const Course*> courses;
	vector<OpenCourse*> openCourses;
	vector<Student*> students;
	vector<int**> touchins;

	// extra variables
	int row_size, column_size;
	struct triple {
		int t = -1;
		int i = 0;
		int j = 0;
	};

	struct triple* findStudentInTouchins(int student_id, int t);
	struct triple* addNewTouchin(triple* index_f, triple* index_t, int from_student_id, int to_student_id, string dir);
	void combine2TouchinsIntoNewOne(triple* index_f, triple* index_t, string dir, int* shifts);
	int* computeShifts(triple* index_f, triple* index_t, string dir);
	void constructNewTouchin();
	void destructTouchin(int t);

	void upgradeStudentHelper(Student* oldStudent, Student* newStudent);

public:
	Metu();
	~Metu();

	Student& getStudent(int);
	void registerStudent(Student*);
	void registerCourse(const Course&);
	OpenCourse& openCourse(const Course& course, string term, int quota, vector<Freshman*>, vector<Sophomore*>, vector<Junior*>, vector<Senior*>);

	Sophomore* upgradeStudent(Freshman&);
	Junior* upgradeStudent(Sophomore&);
	Senior* upgradeStudent(Junior&);

	void setRegionSize(int row_size, int column_size);
	void addTouchInfo(int from_student_id, int to_student_id, string dir);
	void printTouchInfo();

};

#endif
