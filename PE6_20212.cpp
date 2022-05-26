// PE6_20212.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Course.h"
#include "Student.h"
#include "Metu.h"

void testSeatingPlan();
void scenario1();

int main() {

    Metu* metu = new Metu();
    vector<Freshman*> freshmans;
    vector<Sophomore*> sophomores;
    vector<Junior*> juniors;
    vector<Senior*> seniors;

    Course* ceng242 = new Course("Programming Languages");  // define base course
    metu->registerCourse(*ceng242);



    OpenCourse& open_ceng242 = metu->openCourse(*ceng242, "20212", 1, freshmans, sophomores, juniors, seniors);

    return 0;
}


void scenario1()
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

}

void testSeatingPlan() {

    Metu* metu = new Metu();

    for (int i = 1; i <= 100; i++) {
        Student* student = new Student(i, "Stu Dent", "CENG");
        metu->registerStudent(student);
    }
 
    /* 
    //        TEST-1
     metu->setClassroomSize(3, 6);
    metu->addCheatInfo(18, 35, "-");
    metu->addCheatInfo(18, 13, "|");
    metu->addCheatInfo(35, 36, "-");
    metu->addCheatInfo(36, 47, "-");
    metu->addCheatInfo(47, 30, "|");
    metu->addCheatInfo(30, 11, "-");
    metu->addCheatInfo(82, 80, "-");
    metu->addCheatInfo(65, 80, "|");
    metu->addCheatInfo(1, 65, "-");
    metu->addCheatInfo(12, 13, "-");
    metu->addCheatInfo(35, 1, "|");
    */

    metu->setClassroomSize(7, 7);
    metu->addCheatInfo(18, 35, "-");
    metu->addCheatInfo(18, 13, "|");
    metu->addCheatInfo(7, 19, "|");
    metu->addCheatInfo(23, 26, "-");
    metu->addCheatInfo(51, 36, "-");
    metu->addCheatInfo(36, 47, "-");
    metu->addCheatInfo(47, 30, "|");
    metu->addCheatInfo(30, 11, "-");
    metu->addCheatInfo(82, 80, "-");
    metu->addCheatInfo(65, 80, "|");
    metu->addCheatInfo(1, 65, "-");
    metu->addCheatInfo(12, 13, "-");
    metu->addCheatInfo(35, 10, "|");
    metu->addCheatInfo(10, 45, "-");
    metu->addCheatInfo(19, 20, "-");
    metu->addCheatInfo(65, 58, "-");
    metu->addCheatInfo(58, 51, "-");
    metu->addCheatInfo(32, 49, "-");
    metu->addCheatInfo(24, 32, "|");
    metu->addCheatInfo(23, 24, "|");
    metu->addCheatInfo(12, 26, "|");
    metu->addCheatInfo(30, 29, "|");
    metu->addCheatInfo(45, 7, "|");
    metu->addCheatInfo(7, 3, "-");
    metu->addCheatInfo(4, 6, "|");
    metu->addCheatInfo(2, 6, "-");
    metu->addCheatInfo(49, 2, "-");
    metu->addCheatInfo(51, 39, "|");
    metu->addCheatInfo(39, 35, "|");
    
    metu->printSeatingPlan();

    delete metu;
}

enum Grade learnGrade(string course_name, int student_id) {

    return NA;
}