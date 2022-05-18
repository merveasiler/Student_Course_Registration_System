#include "Student.h"

/****************************************************/
/****               *** STUDENT ***              ****/

Student::Student(int _id, string _fullname, string _department) : id(_id), fullname(_fullname), department(_department) {

	this->gpa = 4.0;
}

Student::~Student() {

	for (unsigned int i = 0; i < courses.size(); i++) {
		delete courses[i];
		courses[i] = NULL;
	}
	courses.clear();
}

// shallow copy
Student::Student(const Student& student) : id(student.id), fullname(student.fullname), department(student.department) {

	this->gpa = student.gpa;
	for (unsigned int i = 0; i < student.courses.size(); i++) {
		this->courses.push_back(student.courses[i]);
	}

}

int Student::getId() const {

	return this->id;
}

vector<const CourseInstance*> Student::listCourses() {
	
	vector<const CourseInstance*> constCourses;
	for (int i = 0; i < courses.size(); i++)
		constCourses.push_back(courses[i]);
	return constCourses;
}

/****************************************************/
/****              *** FRESHMAN ***              ****/

Freshman::Freshman(int id, string fullname, string department) : Student(id, fullname, department) {

}

Freshman::~Freshman() {

}

Freshman::Freshman(const Freshman& freshman) : Student(freshman) {

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
	this->internship2 = false;
}

Sophomore::Sophomore(const Freshman& freshman) : Freshman(freshman) {

	this->internship1 = false;
	this->internship2 = false;
}

Sophomore::~Sophomore() {

}

Sophomore::Sophomore(const Sophomore& sophomore) : Freshman(sophomore) {

	this->internship1 = sophomore.internship1;
	this->internship2 = sophomore.internship2;
}

void Sophomore::doAnInternship(int intership_no) {

	if (intership_no == 1) {
		enum Grade grade = learnGrade("INTERNSHIP-1", this->id);
		if (grade == S)
			internship1 = true;
		else
			internship1 = false;
	}
	else {
		enum Grade grade = learnGrade("INTERNSHIP-2", this->id);
		if (grade == S)
			internship2 = true;
		else
			internship2 = false;
	}
}

/****************************************************/
/****                *** JUNIOR ***              ****/

Junior::Junior(int id, string fullname, string department) : Sophomore(id, fullname, department) {
	
}

Junior::Junior(const Sophomore& sophomore) : Sophomore(sophomore) {

}

Junior::~Junior() {

}

Junior::Junior(const Junior& junior) : Sophomore(junior)
{

}

void Junior::selectElectiveCourse() {

}

/****************************************************/
/****                *** SENIOR ***              ****/

Senior::Senior(int id, string fullname, string department) : Junior(id, fullname, department) {

	this->graduation = false;
}

Senior::Senior(const Junior& junior) : Junior(junior) {

	this->graduation = false;
}

Senior::~Senior() {

}

Senior::Senior(const Senior& senior) : Junior(senior) {

	this->graduation = senior.graduation;
}

bool Senior::graduate() {

}

