/*Full Name:Yaniv Bohbot
ID :204892749
Campus :Ashdod
*/
#define _CRT_SECURE_NO_WARNINGS
#include "College.h"
#include "Departement.h"
#include "Student.h"
#include "Course.h"
#include <string>


College::College()
{
}


College::~College()
{
	for (int i = 0; i <amount_departement; i++)
	{
		delete[] array_of_departement_in_college[i];
	}
	delete[] array_of_departement_in_college;
}
void College::menu()
{
	int option, flag = 1,finish=1;

	Departement dept;
	Student student;
	Course course;
	/*while (flag)*/
	while (finish)
	{
		cout << "MENU:" << endl << "1)Add Departement" << endl << "2)Add course Department" << endl << "3)Add Student" << endl << "4)Register student to course" << endl << "5)grading student in course" <<endl<< "6)Print course information" << endl << "7)Print student information" << endl << "8)Print departement Information" << endl << "9)Find Student with bad academic status" << endl << "10)Remove student from course" << endl << "11)Exit" << endl;
		cout <<endl<<"Enter your choice :"<<endl;
		cin >> option;


		switch (option)
		{
		case 1:add_department_to_college(dept); //function call for addiing department  
			break;
		case 2: Add_course_to_department(dept, course);// function for adding course to department 
			break;
		case 3:add_student_to_departemnt(dept, student); // function for adding students for the department 
			break;
		case 4:Register_student_to_course(dept, student, course); // funciton for regitster student for the course 
			break;
		case 5:Grading_student_in_course(dept, course);// function call for grading each student in the course 
			break;
		case 6:print_course_information(dept, course);// function call for print all the informatoint about the course 
			break;
		case 7:print_student_information(dept, student);// funciton for print all the information about the student;
			break;
		case 8:print_department_information(dept, student);//funciton for print all the information about the department 
			break;
		case 9:find_students_with_bad_academic_status(dept, student, course);//funtion call to find all the sutdent with bad grade
			break;
		case 10:Remove_student_from_course(dept,student,course);//function call to remove the students form the course 
			break;
		case 11:
			cout << "good bye"<<endl;
			exit(finish); // function call to exit 
			break;


		default:cout << "you did mistake ! try again " << endl;

			break;
		}

	}
}

void College::add_department_to_college(Departement& dep)
{ 
	Departement** tempd;
	cout << "Please enter name of department and code" << endl; //get input from user
	cin >> dep;
	if (amount_departement == 0) // if list of department is empty add a department to the list.
	{
		array_of_departement_in_college = new Departement*; //Memory allocation
		array_of_departement_in_college[0] = new Departement;//Memory allocation
		array_of_departement_in_college[0]->set_name_departement(dep.get_name_departement());//set name
		array_of_departement_in_college[0]->set_id_department(dep.get_code_departement());//set code
		amount_departement += 1;//Increases the size of department
	}
	else
	{
		for (int i = 0; i < amount_departement; i++)//check if department already exist
		{
			if (dep.get_code_departement() == array_of_departement_in_college[i]->get_code_departement())
			{
				cout << "exist code" << endl;
				return;
			}
		}
		tempd = new Departement*[amount_departement];//Memory allocation to temp list
		for (int i = 0; i < amount_departement; i++)
		{
			tempd[i] = new Departement;
			tempd[i] = array_of_departement_in_college[i];
		}
		//	delete[](DepartmentList);//free memory
		array_of_departement_in_college = new Departement*[amount_departement];// new Memory allocation to original list
		for (int i = 0; i <= amount_departement; i++)
		{
			array_of_departement_in_college[i] = new Departement;
			if (i == amount_departement)//set last cell
			{
				array_of_departement_in_college[i]->set_name_departement(dep.get_name_departement());
				array_of_departement_in_college[i]->set_id_department(dep.get_code_departement());
			}
			else//set all cell
			{
				array_of_departement_in_college[i] = tempd[i];
			}
		}

		amount_departement += 1;//Increases the size of department
	}

	
}
void College::Add_course_to_department(Departement& d, Course& c)
{	
	int code_dep;
	cout<<"Enter the code of Departement"<<endl;
	cin>>code_dep;
	if (verify_code_departement(code_dep))
	{
		cout <<endl<<"Enter Course details: (name , number)" << endl;
		cin>>c;
		if (c == d)
		{
			d += c;
		}
		else
		{
			cout << "The Course already exists you can't add course again !" << endl;
		}
	
	}
}
void College::add_student_to_departemnt(Departement& dept, Student& student)
{
	int code_dept, count = 0;
	cout << "Enter code of department" << endl;
	cin >> code_dept;
	if (verify_code_departement(code_dept))
	{
		cout << "Enter Student details (Name,Id,,Gender,age):";
		cin >> student;

		if (student == dept)//return true if the messages are equal, false otherwise
		{
			dept += student;


		}
		else{
			cout << " The student exist  you cant add him again " << endl;
		}
		array_of_total_student_college = new Student*[amount_of_total_student];
		for (int i = 0; i <= amount_of_total_student; i++)
		{
			array_of_total_student_college[i] = new Student;
			student.set_student_departemnt(&dept);
			array_of_total_student_college[amount_of_total_student] = &student;
		}
		amount_of_total_student += 1;
	}
	
}
void College::Register_student_to_course(Departement& dept, Student& student, Course &course)
{
	int code_dept, student_id, code_course, count = 0;

	cout << "Enter code of department:";
	cin >> code_dept;
	if (verify_code_departement(code_dept))
	{
		cout << "Enter code of the Course:";
		cin >> code_course;
		course.set_code_course(code_course);
		if (!(course == dept))
		{
			cout << endl << "Enter Student Id:";
			cin >> student_id;

			course.setpointer_Depatment(&dept);
			if (student == dept)
			{
				student += course;// adding a course for the student 
				course += student;// adding student to the course 

			}
			else
			{
				cout << " the Student  is already exist " << endl;
			}
		}
		else{
			cout << " the Course is already exist " << endl;
		}
	}
}
void College::Grading_student_in_course(Departement& dept, Course &course)
{
	{
		int course_code, count = 0, grade = 0;
		cout << "Enter course code" << endl;
		cin >> course_code;
		course.set_code_course(course_code);
		for (int index1 = 0; index1 < amount_departement; index1++)//Through all the Department in college.
		{
			for (int index2 = 0; index2 < dept.get_AmountCourse(); index2++)//Through all the courses in the Department
			{
				if (!(course == dept))//code course exists
				{
					for (int index3= 0; index3 < course.get_amount_student(); index3++)//Through all the student in the course
					{

						cout << "Please enter grade for student:" << course.get_array_of_student()[index3]->get_student_name() << endl;
						cin >> grade;// input grade
						course.set_array_of_grade(index2, grade);//set grade in list of grade
						cout << course.get_array_of_grades(index2);
						count++;
					}
				}
			}
		}
		if (count == 0)//code course no exists
			cout << "Sorry the code course no exists" << endl;
	}
}
void College::print_course_information(Departement& d, Course& c)
{
	int code_course,flag = 0, grade = 0, size = 0;
	cout << "Enter course code" << endl;
	cin >> code_course;
	c.set_code_course(code_course);
	for (int i = 0; i <amount_departement; i++)//Through all the Department in college.
	{
		for (int j = 0; j <d.get_AmountCourse(); j++)//Through all the courses in the Department
		{
			if (!(c == d))//code course exists
			{
				cout << "Name Department:" << " " << d.get_name_departement() << " " << "code Department:" << d.get_code_departement() << endl;
				flag = 1;
			cout << c;
				break;
			}
		}
	}
	if (flag == 0)//code course no exists
		cout << "the code course doesnt exists" << endl;
}
void College ::print_student_information(Departement &dept ,Student &student)
{
	int   code_student, flag= 0;

	cout << "Enter your number of Id:";
	cin >> code_student;
	for (int i = 0; i <amount_of_total_student; i++)//check if department already exist
	{
		if (code_student ==   array_of_total_student_college[i]->get_student_id())
		{
			cout << endl << "Name of departement :" << dept.get_name_departement() << endl << "Numb of Department:" << dept.get_code_departement() << endl;
			cout << student;
			flag = 1;
			break;
		}
		if (flag == 0)
		{
			cout << "sorry the student is not in the college "<<endl;
		}

	}

}
bool College::verify_code_departement(const int code)
{
	int count = 0;
	for (int i = 0; i <amount_departement; i++)//check if department already exist
	{
		if (code != int (array_of_departement_in_college[i]->get_code_departement()))
		{
			count++;
		}
	}
	if (count == amount_departement)//check if department already exist
	{
		cout << " No exist code" << endl;
		return false;
	}
	else
		return true;
}

bool College::verify_code_student(const int code)
{
	int count = 0;
	for (int i = 0; i <amount_of_total_student; i++)//check if department already exist
	{
		if (code != array_of_total_student_college[i]->get_student_id())
		{
			count++;
		}
	}
	if (count == amount_departement)//check if department already exist
	{
		cout << " No exist code" << endl;
		return false;
	}
	else
		return true;
}
void College::print_department_information(Departement &dept, Student &student)
{
	int   code_dept, counter = 0;

	cout << "Enter code of department:";
	cin >> code_dept;
	if (verify_code_departement(code_dept))
	{
		cout << dept;
		for (int i = 0; i < dept.get_AmountCourse(); i++)//check if department already exist
		{
		
			cout << "Name of course in departement: " << dept.get_array_of_course_in_departmnt()[i]->get_name_of_course() << endl;
			cout << "Name of students in departement: " << dept.get_array_of_student_in_department()[i]->get_student_name() << endl;
		}
		
		if (counter == 0)
		{
			cout << "sorry the student is not in the college " << endl;
		}

	}

}
void College::find_students_with_bad_academic_status(Departement &dept, Student& student, Course& course)
{
	int student_id, course_code, code;
	for (int i = 0; i < amount_departement; i++)
	{
		code = array_of_departement_in_college[i]->get_code_departement();
		if (verify_code_departement(code))
		{
			cout << "Enter course code" << endl;
			cin >> course_code;
			course.set_code_course(course_code);
			if (!(course == dept))
			{
				cout << "Enter student id" << endl;
				cin >> student_id;
				course.setpointer_Depatment(&dept);
				if (!(student == dept))
				{
					if (student -= course)//Delete course to the student's courses
						cout << "Delete course to the student's courses was successful" << endl;
					if (course -= student)//Delete student to student course list
						cout << "Delete student to student course list was successful" << endl;
				}
				else
					cout << "Sorry the Student no exists you cannot add student" << endl;
			}
			else
				cout << "Sorry the code course no exists you cannot add course" << endl;
		}
	}

}
void College::Remove_student_from_course(Departement& dept, Student& student, Course& course)
{
	int student_id, course_code, code;
	for (int i = 0; i < amount_departement; i++)
	{
		code = array_of_departement_in_college[i]->get_code_departement();
		if (verify_code_departement(code))
		{
			cout << "Enter course code" << endl;
			cin >> course_code;
			course.set_code_course(course_code);
			if (!(course == dept))
			{
				cout << "Enter student id" << endl;
				cin >> student_id;
				course.setpointer_Depatment(&dept);
				if (!(student == dept))
				{
					if (student -= course)//Delete course to the student's courses
						cout << "Delete course to the student's courses was successful" << endl;
					if (course -= student)//Delete student to student course list
						cout << "Delete student to student course list was successful" << endl;
				}
				else
					cout << "Sorry the Student no exists you cannot add student" << endl;
			}
			else
				cout << "Sorry the code course no exists you cannot add course" << endl;
		}
	}
}
 int College::exit(int finish)
{
	finish = 0;
	return finish;
}