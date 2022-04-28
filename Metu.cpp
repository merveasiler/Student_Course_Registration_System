#include "Metu.h"

Metu::Metu() {

}

Metu::~Metu() {

	for (unsigned int i = 0; i < courses.size(); i++) {
		delete courses[i];
		courses[i] = NULL;
	}
	courses.clear();

	for (unsigned int i = 0; i < students.size(); i++) {
		delete students[i];
		students[i] = NULL;
	}
	students.clear();

}

Student& Metu::getStudent(int id) {
	
	for (unsigned int i = 0; i < students.size(); i++)
		if (students[i]->getId() == id)
			return *students[i];

}

void Metu::registerCourse(const Course& course) {
	
	courses.push_back(&course);
}

void Metu::registerStudent(Student& student) {
	
	students.push_back(&student);
}

void Metu::setRegionSize(int row_size, int column_size) {

	this->row_size = row_size;
	this->column_size = column_size;
}

void Metu::addTouchInfo(int from_student_id, int to_student_id, string dir) {

	// find the students in the school list
	Student* from_student = & getStudent(from_student_id);
	Student* to_student = & getStudent(to_student_id);

	// Find both students' indices in touch-in groups
	struct triple* index_f = NULL;
	struct triple* index_t = NULL;
	for (unsigned int t = 0; t < touchins.size(); t++) {
		int i = 0, j = 0;
		if (index_f == NULL)
			index_f = findStudentInTouchins(from_student_id, t, i, j);
		if (index_t == NULL)
			index_t = findStudentInTouchins(to_student_id, t, i, j);
		if (index_f && index_t)
			break;
	}

	// Set the connection
	from_student->addTouchIn(to_student, dir);

	// Set the sitting plan
	if (index_f == NULL && index_t == NULL) {
		constructNewTouchin();
		touchins[touchins.size() - 1][0][0] = from_student_id;
		addConnection(from_student_id, to_student_id, dir, touchins.size()-1, 0, 0);
	}
	else if (index_f == NULL) {
		//addConnection(from_student_id, to_student_id, dir, index_t->t, index_t->i, index_t->j);
		constructNewTouchin();
		touchins[touchins.size() - 1][0][0] = from_student_id;
		index_f = new triple(); index_f->t = touchins.size() - 1; index_f->i = 0; index_f->j = 0;
		combine2TouchinsIntoNewOne(index_f, index_t, dir);
		delete index_t;
	}
	else if (index_t == NULL) {
		//addConnection(from_student_id, to_student_id, dir, index_f->t, index_f->i, index_f->j);
		constructNewTouchin();
		touchins[touchins.size() - 1][0][0] = to_student_id;
		index_t = new triple(); index_t->t = touchins.size() - 1; index_t->i = 0; index_t->j = 0;
		combine2TouchinsIntoNewOne(index_f, index_t, dir);
		delete index_f;
	}
	else {
		combine2TouchinsIntoNewOne(index_f, index_t, dir);
		delete index_f;
		delete index_t;
	}

}

Metu::triple* Metu::findStudentInTouchins(int student_id, int t, int i, int j) {
	
	if (touchins[t][i][j] == student_id) {
		struct triple* index = new triple();
		index->t = t;
		index->i = i;
		index->j = j;
		return index;
	}

	Student& student = getStudent(touchins[t][i][j]);
	if (student.getHorizontalTouchIns() != NULL) {
		struct triple* index = findStudentInTouchins(student_id, t, i, j + 1);
		if (index) return index;
	}
	if (student.getVerticalTouchIns() != NULL) {
		struct triple* index = findStudentInTouchins(student_id, t, i + 1, j);
		if (index) return index;
	}

	return NULL;
}

void Metu::addConnection(int from_student_id, int to_student_id, string dir, int t, int i, int j) {
	
	if (touchins[t][i][j] == from_student_id) {
		if (dir == "-")
			touchins[t][i][j + 1] = to_student_id;
		else
			touchins[t][i + 1][j] = to_student_id;
	}
	else if (touchins[t][i][j] == to_student_id) {
		if (dir == "-")
			touchins[t][i][j - 1] = from_student_id;
		else
			touchins[t][i - 1][j] = from_student_id;
	}

}

void Metu::constructNewTouchin() {
	int** new_group = new int* [row_size];
	for (int i = 0; i < row_size; i++) {
		new_group[i] = new int[column_size];
		for (int j = 0; j < column_size; j++)
			new_group[i][j] = -1;
	}
	touchins.push_back(new_group);
}

void Metu::combine2TouchinsIntoNewOne(struct triple* index_f, struct triple* index_t, string dir) {

	constructNewTouchin();
	int row_shift_f = 0, row_shift_t = 0;
	int column_shift_f = 0, column_shift_t = 0;
	if (dir == "-") {
		if (index_f->i < index_t->i)
			row_shift_f = index_t->i - index_f->i;
		else
			row_shift_t = index_f->i - index_t->i;
		if (index_f->j + 1 < index_t->j)
			column_shift_f = index_t->j - (index_f->j + 1);
		else
			column_shift_t = (index_f->j + 1) - index_t->j;
	}
	else {
		if (index_f->i + 1 < index_t->i)
			row_shift_f = index_t->i - (index_f->i + 1);
		else
			row_shift_t = (index_f->i + 1) - index_t->i;
		if (index_f->j < index_t->j)
			column_shift_f = index_t->j - index_f->j;
		else
			column_shift_t = index_f->j - index_t->j;
	}

	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < column_size; j++) {
			if (touchins[index_f->t][i + row_shift_f][j + column_shift_f] != '-1')
				touchins[touchins.size() - 1][i][j] = touchins[index_f->t][i + row_shift_f][j + column_shift_f];
			if (touchins[index_t->t][i + row_shift_t][j + column_shift_t] != '-1')
				touchins[touchins.size() - 1][i][j] = touchins[index_t->t][i + row_shift_t][j + column_shift_t];
		}
	}

	destructTouchin(index_f->t);
	destructTouchin(index_t->t);
	touchins.erase(touchins.begin() + index_f->t);
	touchins.erase(touchins.begin() + index_t->t);

}

void Metu::destructTouchin(int t) {

	int** group = touchins[t];
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < column_size; j++) {
			delete& group[i][j];
			group[i * j + j] = NULL;
		}
		delete &group[i];
		group[i] = NULL;
	}
	delete group;
	group = NULL;

}

void Metu::printTouchInfo() {

	int** group = touchins[0];

	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < column_size; j++)
			if (group[i][j] < 0)
				cout << "X ";
			else
				cout << group[i][j] << " ";
		cout << endl;
	}
			
}


void Metu::upgradeStudents() {

}




