
/*Full Name:Yaniv Bohbot
ID :204892749
Campus :Ashdod
*/#define _CRT_SECURE_NO_WARNINGS
#include "College.h"
#include "Departement.h"
#include "Student.h"
#include "Course.h"
#include <string>

Student::Student()
{
	name_student=" ";
	gender = NULL;
	student_id = 0;
	age = 0;
	amount_of_course = 0;
	array_of_course = NULL;
	array_of_department=NULL;
}
//void Student::set_student(string n, int numb_id, char sex, int âge,int amount)
//{    
//	int size_course;
//	 name_student=n;
//     student_id = numb_id;
//     gender = sex;
//	 age = âge;
//	 size_course = return_amount_course(amount);
//
//	 array_of_course = new Course*[size_course];
//
//	 for (int i = 0; i <size_course;i++)
//		 array_of_course[i] = new Course[i];
//}


Student::~Student()
{
	for (int i = 0; i <10; ++i)
		delete[]array_of_course[i];
	delete[] array_of_course;
}
Student & Student ::operator=(const Student &s) // operateur assama
{
	name_student=s.name_student;
	student_id=s.student_id;
	gender=s.gender;
	age=s.age;
	amount_of_course = s.amount_of_course;
	return *this;
}
bool Student::operator==(Departement& dept) // operat
{
	for (int i = 0; i <dept.get_size_of_student_in_dept(); i++)
	{
		if (int(dept.get_array_of_student_in_department()[i]->student_id) == student_id)
		{
		
			return false;
		}
	}
	return true;
}
bool Student::operator>(const Student &stud)const
{
	Course c;
	c.return_grade_average();

	return true;

}
void Student::operator+=(Course& cours)
{   
	Course** pointeur_course = NULL;
	pointeur_course = new Course*[amount_of_course];// allocate new memory and copy the elements
	for (int i = 0; i < amount_of_course; i++)
	{
		pointeur_course[i] = new Course;
		pointeur_course[i] = array_of_course[i];
	}
	array_of_course = new Course*[amount_of_course];//assign the new memory to the object
	for (int i = 0; i <= amount_of_course; i++)
	{
		array_of_course[i] = new Course;
		if (i == amount_of_course)//set last cell
		{
			array_of_course[i]->set_name_course(cours.get_name_of_course());//set name course
		}
		else//set all cell
		{
			array_of_course[i] = pointeur_course[i];
		}
	}
	amount_of_course += 1;
}
void Student::print_course()
{
	for (int i = 0; i < amount_of_course; i++)
	{
		array_of_course[i];
	}
}
Course* Student ::operator[](int index)
{
	while (index >= amount_of_course)
	{
		cout << "You did a mistake is out of bound try  again:";
		cin >> index;
	}
	return array_of_course[index];

}

bool Student::operator-=(Course& course)//Delete course to the student's courses
{
	int flag = 0;
	Course** pointeur_array_of_course = NULL;
	pointeur_array_of_course = new Course*[amount_of_course];// allocate new memory and copy the elements
	cout << "The original list of Course:" << " ";
	for (int i = 0; i < amount_of_course; i++)
	{
		cout << array_of_course[i]->get_name_of_course() << " " << array_of_course[i]->get_numb_of_course() << " ";
	}
	cout << endl;
	for (int i = 0; i < amount_of_course; i++)
	{
		if (course.get_numb_of_course() != array_of_department->get_array_of_course_in_departmnt()[i]->get_numb_of_course())
		{
			pointeur_array_of_course[i] = new Course;
			pointeur_array_of_course[i] = array_of_course[i];
			flag = 1;
		}
	}
	amount_of_course-= 1;//decrease the size of department
	array_of_course = new Course*[amount_of_course];//assign the new memory to the object
	for (int i = 0; i < amount_of_course; i++)
	{
		array_of_course[i] = pointeur_array_of_course[i];
	}
	cout << "The new list of courses:" << " ";
	for (int i = 0; i <= amount_of_course; i++)
	{
		if (amount_of_course == 0)
			cout << "No Course exist" << endl;
		else
			cout << array_of_course[i]->get_name_of_course() << " " << array_of_course[i]->get_numb_of_course() << " ";
	}
	cout << endl;
	if ((flag== 0 && amount_of_course == 0) || flag == 1)
		return true;
	else
		return false;
}

ostream& operator<<(ostream &os, Student &stud)// operator cout print the elemetn
{
	os << "Name:" << stud.name_student << endl << "id:" << stud.student_id << endl << "gender:" << stud.gender << endl << "age:" << stud.age << endl;
	for (int i = 0; i < stud.get_amount_of_course(); i++)
	{
		os << "Courses:" << stud.array_of_course[i]->get_name_of_course() << " " << endl << "NUmber of course :" << stud.array_of_course[i]->get_numb_of_course() << endl;
	}
	return os;

};