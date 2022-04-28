#pragma once

#include "Student.h"

class Metu {

	vector<const Course*> courses;
	vector<Student*> students;
	vector<int**> touchins;

	int row_size, column_size;
	struct triple {
		int t;
		int i;
		int j;
	};

	struct triple* findStudentInTouchins(int student_id, int t, int i, int j);
	void addConnection(int from_student_id, int to_student_id, string dir, int t, int i, int j);
	void constructNewTouchin();
	void destructTouchin(int t);
	void combine2TouchinsIntoNewOne(struct triple* index_f, struct triple* index_t, string dir);

public:
	Metu();
	~Metu();

	Student& getStudent(int id);
	void registerCourse(const Course& course);
	void registerStudent(Student& student);
	void setRegionSize(int row_size, int column_size);
	void addTouchInfo(int from_student_id, int to_student_id, string dir);
	void printTouchInfo();
	void upgradeStudents();

};