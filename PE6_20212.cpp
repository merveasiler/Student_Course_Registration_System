// PE6_20212.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Course.h"
#include "Student.h"
#include "Metu.h"

void testTouchins();

int main()
{
    Metu* metu = new Metu();

    Course* ceng111 = new Course("Introduction To Computer Engineering Concepts");
    metu->registerCourse(*ceng111);

    Course* ceng242 = new Course("Programming Languages");
    ceng242->addPrerequisite(*ceng111);
    metu->registerCourse(*ceng242);

    vector<Freshman*> freshmans;
    Freshman* freshman_student = new Freshman(1234567, "Fresh Man", "CENG");
    metu->registerStudent(freshman_student);
    freshmans.push_back(freshman_student);

    vector<Sophomore*> sophomores;
    Sophomore* sophomore_student = new Sophomore(2345671, "Sopho More", "CENG");
    metu->registerStudent(sophomore_student);
    sophomores.push_back(sophomore_student);

    vector<Junior*> juniors;
    vector<Senior*> seniors;

    OpenCourse& open_ceng111 = metu->openCourse(*ceng111, "20201", 20, freshmans, sophomores, juniors, seniors);
    OpenCourse& open_ceng242 = metu->openCourse(*ceng242, "20212", 1, freshmans, sophomores, juniors, seniors);
    
    cout << "Courses Taken" << endl;
    for (int i = 0; i < freshman_student->listCourses().size(); i++)
        cout << freshman_student->listCourses()[i]->getName() << endl;

    Sophomore* upgraded_freshman_student = metu->upgradeStudent(*freshman_student);
    delete metu;

    //testTouchins();

    return 0;

}

void testTouchins() {

    Metu* metu = new Metu();

    for (int i = 1; i <= 100; i++) {
        Student* student = new Student(i, "Stu Dent", "CENG");
        metu->registerStudent(student);
    }
 
    /* 
    //        TEST-1
     metu->setRegionSize(3, 6);
    metu->addTouchInfo(18, 35, "-");
    metu->addTouchInfo(18, 13, "|");
    metu->addTouchInfo(35, 36, "-");
    metu->addTouchInfo(36, 47, "-");
    metu->addTouchInfo(47, 30, "|");
    metu->addTouchInfo(30, 11, "-");
    metu->addTouchInfo(82, 80, "-");
    metu->addTouchInfo(65, 80, "|");
    metu->addTouchInfo(1, 65, "-");
    metu->addTouchInfo(12, 13, "-");
    metu->addTouchInfo(35, 1, "|");
    */

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
    metu->addTouchInfo(30, 29, "|");
    metu->addTouchInfo(45, 7, "|");
    metu->addTouchInfo(7, 3, "-");
    metu->addTouchInfo(4, 6, "|");
    metu->addTouchInfo(2, 6, "-");
    metu->addTouchInfo(49, 2, "-");
    metu->addTouchInfo(51, 39, "|");
    metu->addTouchInfo(39, 35, "|");
    
    metu->printTouchInfo();

    delete metu;
}

enum Grade learnGrade(string course_name, int student_id) {

    return NA;
}