// PE6_20212.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Course.h"
#include "Student.h"
#include "Metu.h"

void testTouchins();

int main()
{
    Metu metu;
    Course* course = new Course("Programming Languages");
    Freshman* freshman_student = new Freshman(1234567, "Fresh Man", "CENG");

    metu.registerCourse(*course);
    metu.registerStudent(*freshman_student);

    freshman_student->addCourse(*course);
    freshman_student->listCourses();

    testTouchins();

    return 0;

}

void testTouchins() {

    Metu* metu = new Metu();

    for (int i = 1; i <= 100; i++) {
        Student* student = new Student(i, "Fresh Man", "CENG");
        metu->registerStudent(*student);
    }

    metu->setRegionSize(7, 7);

    metu->addTouchInfo(18, 35, "-");
    metu->addTouchInfo(18, 13, "|");
    metu->addTouchInfo(7, 19, "|");
    metu->addTouchInfo(23, 26, "-");
    metu->addTouchInfo(51, 36, "-");
    metu->addTouchInfo(36, 47, "-");
    metu->addTouchInfo(47, 30, "|");
    metu->addTouchInfo(30, 11, "-");
    metu->addTouchInfo(82, 80, "-");
    metu->addTouchInfo(65, 80, "|");
    metu->addTouchInfo(1, 65, "-");
    metu->addTouchInfo(12, 13, "-");
    metu->addTouchInfo(35, 10, "|");
    metu->addTouchInfo(10, 45, "-");
    metu->addTouchInfo(19, 20, "-");
    metu->addTouchInfo(65, 58, "-");
    metu->addTouchInfo(58, 51, "-");
    metu->addTouchInfo(32, 49, "-");
    metu->addTouchInfo(24, 32, "|");
    metu->addTouchInfo(23, 24, "|");
    metu->addTouchInfo(12, 26, "|");
    metu->addTouchInfo(30, 19, "|");
    metu->addTouchInfo(45, 7, "|");
    metu->addTouchInfo(7, 3, "-");
    metu->addTouchInfo(3, 20, "|");
    metu->addTouchInfo(4, 6, "|");
    metu->addTouchInfo(2, 6, "-");
    metu->addTouchInfo(49, 2, "-");

    metu->printTouchInfo();

    delete metu;
}

