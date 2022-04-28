#include "Student.h"

/*************************** Student ***************************/

Student::Student(int id, string fullname, string department) {
	this->id = id;
	this->fullname = fullname;
	this->department = department;

	this->horizontal = NULL;
	this->vertical = NULL;
}

Student::~Student() {

	for (unsigned int i = 0; i < courses.size(); i++) {
		delete courses[i];
		courses[i] = NULL;
	}
	courses.clear();
}

int Student::getId() {

	return id;
}

Student* Student::getHorizontalTouchIns() {

	return horizontal;
}

Student* Student::getVerticalTouchIns() {

	return vertical;
}

void Student::addCourse(const Course& course) {
	CourseInstance* course_instance = new CourseInstance(course);
	this->courses.push_back(course_instance);
}

void Student::listCourses() {
	
	for (unsigned int i = 0; i < courses.size(); i++)
		cout << *courses[i] << endl;
}

void Student::addTouchIn(Student* student, string dir) {

	if (dir == "-")
		this->horizontal = student;
	else 
		this->vertical = student;

}

/*************************** Freshman ***************************/

Freshman::Freshman(int id, string fullname, string department) : Student(id, fullname, department) {

}

Freshman::~Freshman() {

}

/*************************** Sophomore ***************************/

Sophomore::Sophomore(int id, string fullname, string department) : Freshman(id, fullname, department) {

}

Sophomore::~Sophomore() {

}