#include "Student.h"

/****************************************************/
/****               *** STUDENT ***              ****/

Student::Student(int _id, string _fullname, string _department) : id(_id), fullname(_fullname), department(_department) {

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

void Student::listCourses() {
	
	for (unsigned int i = 0; i < courses.size(); i++)
		cout << *courses[i] << endl;
}

/****************************************************/
/****              *** FRESHMAN ***              ****/

Freshman::Freshman(int id, string fullname, string department) : Student(id, fullname, department) {

}

Freshman::~Freshman() {

}

bool Freshman::addCourse(const OpenCourse& opencourse) {

	for (int i = 0; i < opencourse.getPrerequisites().size(); i++) {
		const Course* prerequisite = opencourse.getPrerequisites()[i];
		bool satisfy = false;
		for (int j = 0; j < this->courses.size(); j++)
			if (*this->courses[j] == *prerequisite) {
				satisfy = true;
				break;
			}
		if (satisfy == false)
			return false;
	}

	CourseInstance* course_instance = new CourseInstance(opencourse, *this);
	this->courses.push_back(course_instance);
	return true;
}

void Freshman::gradeCourse(CourseInstance& courseInstance) {

	courseInstance.setGrade(learnGrade(courseInstance.getName(), this->id));
}

/****************************************************/
/****              *** SOPHOMORE ***             ****/

Sophomore::Sophomore(int id, string fullname, string department) : Freshman(id, fullname, department) {

	this->internship1 = false;
}

Sophomore::~Sophomore() {

}

void Sophomore::doAnInternship() {

	Grade grade = learnGrade("INTERNSHIP-1", this->id);
	if (grade == S)
		internship1 = true;
	else
		internship1 = false;
}

/****************************************************/
/****                *** JUNIOR ***              ****/

Junior::Junior(int id, string fullname, string department) : Sophomore(id, fullname, department) {

}

Junior::~Junior() {

}

void Junior::selectElectiveCourse() {

}

/****************************************************/
/****                *** SENIOR ***              ****/

Senior::Senior(int id, string fullname, string department) : Junior(id, fullname, department) {

}

Senior::~Senior() {

}

bool Senior::graduate() {

}

