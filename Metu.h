#pragma once

#include "Student.h"

class Metu {

	vector<const Course*> courses;
	vector<Student*> students;
	vector<int**> touchins;

	int row_size, column_size;


	bool checkStudent(int from_student_id, int to_student_id, string dir, int t, int i, int j);
public:
	Metu();
	~Metu();

	Student& getStudent(int id);
	void registerCourse(const Course& course);
	void registerStudent(Student& student);
	void addTouchInfo(int from_student_id, int to_student_id, string dir);
	void upgradeStudents();

};