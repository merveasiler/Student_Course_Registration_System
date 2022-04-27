#include "Metu.h"

Metu::Metu() {

}

Metu::~Metu() {

	for (unsigned int i = 0; i < courses.size(); i++) {
		delete courses[i];
		courses[i] = NULL;
	}
	courses.clear();

	for (unsigned int i = 0; i < students.size(); i++) {
		delete students[i];
		students[i] = NULL;
	}
	students.clear();

}

Student& Metu::getStudent(int id) {
	
	for (unsigned int i = 0; i < students.size(); i++)
		if (students[i]->getId() == id)
			return *students[i];

}

void Metu::registerCourse(const Course& course) {
	
	courses.push_back(&course);
}

void Metu::registerStudent(Student& student) {
	
	students.push_back(&student);
}

void Metu::addTouchInfo(int from_student_id, int to_student_id, string dir) {

	// find the students in the school list
	Student* from_student = & getStudent(from_student_id);
	Student* to_student = & getStudent(to_student_id);

	// Set the connection
	from_student->addTouchIn(to_student, dir);

	// Set the sitting plan
	for (unsigned int t = 0; t < touchins.size(); t++) {
		int i = 0, j = 0;
		if (checkStudent(from_student_id, to_student_id, dir, t, i, j)) {
			for (unsigned int s = t+1; s < touchins.size(); s++)
				if (checkStudent(from_student_id, to_student_id, dir, s, i, j))
		}
	}
}

bool Metu::checkStudent(int from_student_id, int to_student_id, string dir, int t, int i, int j) {
	if (touchins[t][i][j] == from_student_id || touchins[t][i][j] == to_student_id) {
		if (touchins[t][i][j] == from_student_id) {
			if (dir == "-")
				touchins[t][i][j + 1] = to_student_id;
			else
				touchins[t][i + 1][j] = to_student_id;
		}
		else if (touchins[t][i][j] == to_student_id) {
			if (dir == "-")
				touchins[t][i][j - 1] = from_student_id;
			else
				touchins[t][i - 1][j] = from_student_id;
		}
		return true;
	}
	else {
		Student* student = &getStudent(touchins[t][i][j]);
		if (student->getHorizontalTouchIns() != NULL)
			if (checkStudent(from_student_id, to_student_id, dir, t, i, j + 1))
				return true;
		if (student->getVerticalTouchIns() != NULL)
			if (checkStudent(from_student_id, to_student_id, dir, t, i+1, j))
				return true;
		return false;
	}
}

void Metu::upgradeStudents() {

}




