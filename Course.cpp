#include "Course.h"


/****************************************************/
/****               *** COURSE ***               ****/

Course::Course(string name, int term) {
	
	this->name = name;
}

Course::~Course() {

	this->prerequisites.clear();
	this->all_course_takers.clear();
}

void Course::addPrerequisite(const Course& course) {

	this->prerequisites.push_back(&course);
}

const vector<const Course*> Course::getPrerequisites() const {

	return this->prerequisites;
}

string Course::getName() const {

	return this->name;
}

bool Course::operator== (const Course& rhs) const {

	return this->name == rhs.name;
}

/*
ostream& operator<< (ostream& os, const Course& course) {
	os << course.name << endl;
	return os;
}
*/

/****************************************************/
/****             *** OPEN COURSE ***            ****/

OpenCourse::OpenCourse(const Course& course, int term, int quota) : Course(course) {

	this->term = term;
	this->quota = quota;
}

OpenCourse::~OpenCourse() {

	this->course_takers.clear();
}


/****************************************************/
/****          *** COURSE INSTANCE ***           ****/

CourseInstance::CourseInstance(const OpenCourse& opencourse, Student& student) : OpenCourse(opencourse) {
	
	this->grade = NA;
	this->course_takers.push_back(&student);

}

void CourseInstance::setGrade(Grade grade) {

	this->grade = grade;
}

Grade CourseInstance::getGrade() {

	return this->grade;
}