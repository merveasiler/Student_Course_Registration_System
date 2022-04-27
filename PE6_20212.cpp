// PE6_20212.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Course.h"
#include "Student.h"
#include "Metu.h"

int main()
{
    Metu metu;
    Course* course = new Course("Programming Languages");
    Freshman* freshman_student = new Freshman(1234567, "Fresh Man", "CENG");

    metu.registerCourse(*course);
    metu.registerStudent(*freshman_student);

    freshman_student->addCourse(*course);
    freshman_student->listCourses();

}

void addTouchIns() {

    Metu metu;

    metu.addTouchInfo(18, 35);
    metu.addTouchInfo(20, 17);
    metu.addTouchInfo(10, 30);
    metu.addTouchInfo(80, 100);
    metu.addTouchInfo(35, 43);
    metu.addTouchInfo(20, 19);
    metu.addTouchInfo(65, 26);
    metu.addTouchInfo(48, 60);
    metu.addTouchInfo(10, 44);
    metu.addTouchInfo(10, 12);
    metu.addTouchInfo(65, 10);
    metu.addTouchInfo(48, 70);
    metu.addTouchInfo(20, 18);
    metu.addTouchInfo(17, 16);
    metu.addTouchInfo(48, 80);
    metu.addTouchInfo(18, 42);
    metu.addTouchInfo(48, 90);

}

