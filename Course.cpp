#include "Course.h"


/****************************************************/
/****               *** COURSE ***               ****/

Course::Course(string name) {
	
	this->name = name;
}

Course::~Course() {

	this->prerequisites.clear();
	this->all_course_takers.clear();
}

Course::Course(const Course& course) {

	this->name = course.name;
	for (int i = 0; i < course.prerequisites.size(); i++)
		this->prerequisites.push_back(course.prerequisites[i]);

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

/****************************************************/
/****             *** OPEN COURSE ***            ****/

OpenCourse::OpenCourse(const Course& course, string term, int course_index, int quota) : Course(course) {

	this->term = term;
	this->course_index = course_index;
	this->quota = quota;
	vector<Student*> this_course_takers;
	this->all_course_takers.push_back(this_course_takers);
}

OpenCourse::~OpenCourse() {

	this->all_course_takers[this->course_index].clear();
}

OpenCourse::OpenCourse(const OpenCourse& opencourse) : Course(opencourse) {

	this->term = opencourse.term;
	this->course_index = opencourse.course_index;
	this->quota = opencourse.quota;
}

const vector<int> OpenCourse::showStudentList() const {

	vector<int> student_ids;
	for (int i = 0; i < all_course_takers[this->course_index].size(); i++)
		student_ids.push_back(all_course_takers[this->course_index][i]->getId());
	
	return student_ids;
}

void OpenCourse::finalize() {

	for (int i = 0; i < all_course_takers[this->course_index].size(); i++)
		all_course_takers[this->course_index][i]->gradeCourse(*this);
}


/****************************************************/
/****          *** COURSE INSTANCE ***           ****/

CourseInstance::CourseInstance(const OpenCourse& opencourse, Student& student) : OpenCourse(opencourse) {
	
	this->grade = NA;
	this->all_course_takers[this->course_index].push_back(&student);
}

void CourseInstance::setGrade(enum Grade grade) {

	this->grade = grade;
}

enum Grade CourseInstance::getGrade() {

	return this->grade;
}