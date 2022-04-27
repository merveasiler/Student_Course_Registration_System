#include "Course.h"

/*************************** Course ***************************/

Course::Course(string name) {
	
	this->name = name;
}

Course::~Course() {

}

Course::Course(const Course& course) {

	this->name = course.name;
	//number_of_takers++;
}

void Course::addPrerequisite(const Course& course) {

}

ostream& operator<< (ostream& os, const Course& course) {
	os << course.name << endl;
	return os;
}

/*************************** CourseInstance ***************************/

CourseInstance::CourseInstance(const Course& course) : Course(course) {
	//deneme
}