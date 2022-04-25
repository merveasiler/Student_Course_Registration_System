#include "Course.h"

Course::Course(string name) {
	
	this->name = name;
}

Course::~Course() {

}

Course::Course(const Course& course) {

	this->name = course.name;
	number_of_takers++;
}

CourseInstance::CourseInstance(const Course& course) : Course(course) {
	//deneme
}