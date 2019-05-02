/* Assignment: 4
Campus: Ashdod
Author: Yaniv, ID: 204892749
*/
#include "School.h"


//#define size_layers 5

School::School()
{  
	char letter='a';
	amount_of_layers = 6;
	array_of_layers_in_school = new Layer*[amount_of_layers]; // creating a dynamic array of  6 layers at the school

	for (int i = 0; i <amount_of_layers; i++)  // for each layer we give a name from a To f and we construct a dynamic array of class
	{
		array_of_layers_in_school[i] = new Layer; // create a new Layer 
		array_of_layers_in_school[i]->set_name_chihva(letter);// give Name for each LAyer 
		array_of_layers_in_school[i]->Class_constructor_in_Layer(letter); // we call the function for create a dynamic array of class in the layer 
		letter += 1;		
	}

	array_of_all_the_person_in_school =new Person*[0];
	
	check_if_exist_manager = false;//
	
	  
}


School::~School()
{
	for (int i = 0; i < amount_of_all_the_person_in_school; i++)
	{
		delete[]array_of_all_the_person_in_school[i];
	}
	delete[] array_of_all_the_person_in_school;

}

void School::Menu()
{ 
	int option;

	bool exit = true;

	do{
		cout << " MENU:" << endl << "1)ADD PUPIL" << endl << "2)Add Teacher " << endl << "3)Add Tutor" << endl << "4)Add Manager" << endl << "5)Add Secretary" << endl << "6)Print Workers and Pupils Details " << endl << "7)Print outstandng People " << endl << "8)Print Tutor's class " <<endl<<"9)Print Worker details with Biggest Salarary " << endl << "10)EXit"<<endl;
		cout <<"Select one options" << endl;
		do{
			cin >> option;
		} while (option<1 || option>11);

		switch (option)
		{
		case 1:  ADD_PUPIL();
			break;

		case 2:
			add_teacher_in_school();
			break;
		case 3:
		     ADD_TUTOR();
			break;
		case 4:
			 ADD_Manager();
			break;
		case 5:
		    ADD_SEcretary();
			break;
		case 6:
			PRint_workers_and_pupils_details();
			break;
		case 7:
			Print_oustanding_people();
			break;
		case 8:
			Print_tutor_class();
			break;
		case 9:

			break;
		case 10:
			exit = true;
			break;

		default:

			break;
		}
	} while (exit == true);
}


void School::ADD_PUPIL() //functino for add a pupil to the school 
{
	char name_layer;
     int number_class,number_id;
	 int amara_chihva;
	 string fn,name;
	
	 cout << endl << "enter your layer (between 'a' - 'f'): " << endl;
	 do {
		 cin >> name_layer;
		 
	 } while (name_layer < 'a' || name_layer > 'f');
	if (exist_code(name_layer))
	{
		
		cout << "Enter the number of class in the Layer for add the student in it:" << endl;
		cin >> number_class;

		if ( exist_code_class(number_class) )
		{

			cout << "Enter student details:" << endl;
			cout << "Family name :"; cin >> fn; cout << "Name:"; cin >> name; cout << "Number_id:"; cin >> number_id; cout << endl;

			if (amount_of_all_the_person_in_school == 0)
			{
				array_of_all_the_person_in_school[0] = new Pupil(fn, name, number_id, name_layer, number_class);
				cout << "**************************" << endl;
				cout << "You ADD a Student in School"<<endl;
			}
			else
			{
				Person** TEMP_array_of_all_the_person_in_school = new Person*[amount_of_all_the_person_in_school + 1];

				for(int i = 0; i < amount_of_all_the_person_in_school; i++)
				{
					// allocate to temp[i]
					TEMP_array_of_all_the_person_in_school[i] = array_of_all_the_person_in_school[i]; // copy exist allpeople[i] to temp[i]
				}

				TEMP_array_of_all_the_person_in_school[amount_of_all_the_person_in_school] = new Pupil(fn, name, number_id, name_layer, number_class);

				array_of_all_the_person_in_school = TEMP_array_of_all_the_person_in_school;
			}
			amount_of_all_the_person_in_school += 1;

			for (int i = 0; i <amount_of_layers; i++)
			{
				if (array_of_layers_in_school[i]->get_name_chihva() == name_layer)
				{
					amara_chihva = i;
					break;
				}
			}

			if (dynamic_cast<Pupil*>(array_of_all_the_person_in_school[0]))
			{
				array_of_layers_in_school[amara_chihva]->return_Class_in_array_chichva(number_class - 1)->add_pupils_to_array_learning_class((Pupil*)(array_of_layers_in_school[0]));
				//cout << "Add Pupil successfully!" << endl;
				
			}
			cout << "And in CLass" << endl;
			cout << "**************************" << endl;
		}
	}
}

bool School::exist_code( char name)//Help function- check if code department exist
{
	int count = 0;
	for (int i = 0; i < amount_of_layers; i++)//check if department already exist
	{
		if (name != array_of_layers_in_school[i]->get_name_chihva())
		{
			count++;
		}
	}
	if (count == amount_of_layers)//check if department already exist
	{
		cout << " the Layer doesnt exist try again" << endl;
		return false;
	}
	else
		return true;
}

bool School::exist_code_class(int code)//Help function- check if code department exist
{
	int count = 0;

	for (int i = 0; i < amount_of_layers; i++)//check if department already exist
	{
		for (int j = 0; j < 3; j++)
		{
			if (code != array_of_layers_in_school[i]->return_Class_in_array_chichva(j)->get_number_of_the_class())
			{
				count++;
			}
		}
	}
	if (count == amount_of_layers*3)//check if department already exist
	{
		cout << " the class doesnt exist try again" << endl;
		return false;
	}
	else
		return true;
}


void School::add_teacher_in_school()
{
	string firstName, lastname;
	int id, numCourses, seniority;
	Person** TEMP_array_of_all_the_person_in_school=NULL;

	cout << "Please enter Teacher first name:"; cin >> firstName; cout << "Your last name:"; cin >> lastname; cout << "your id :"; cin >> id;

	if (Check_number_id(id))
	{
		cout << "Please enter Teacher seniority:"; cin >> seniority; cout << " the number of courses you teache:"; cin>> numCourses;
			//input class number
		

		if (amount_of_all_the_person_in_school == 0)
		{
			array_of_all_the_person_in_school[0] = new Teacher(firstName, lastname, id, numCourses, seniority);
		}
		else
		{
			Person** temp = new Person*[amount_of_all_the_person_in_school + 1];

			for (int i = 0; i < amount_of_all_the_person_in_school; i++)
			{
				temp[i] = array_of_all_the_person_in_school[i];
			}

			temp[amount_of_all_the_person_in_school] = new Teacher(firstName, lastname, id, numCourses, seniority);

			//delete[]person;
			array_of_all_the_person_in_school = temp;
		}
		amount_of_all_the_person_in_school += 1;
	}
	for (int i = 0; i < amount_of_all_the_person_in_school; i++)
	{
		cout << array_of_all_the_person_in_school[i]->get_name_person();
	}
}


void School::ADD_TUTOR()
{
	string firstName, lastname;

	int id, classNumber, convertLevel = 0, seniority, numCourses;
	char name_layer;

   cout << "Please enter Tutor first name:"; cin >> firstName; cout << "Your last name:"; cin >> lastname; cout << "your id :"; cin >> id; cout << "seniority :"; cin >> seniority;


	if (Check_number_id(id))
	{
		cout << "Please enter Layer:"; cin >> name_layer;
		cout << "Number of class:"; cin>> classNumber;
		cout << " number of courses you teach:"; cin >> numCourses; //input class number
		
		if (amount_of_all_the_person_in_school == 0)
		{
			array_of_all_the_person_in_school[0] = new Tutor(firstName, lastname, id, numCourses, seniority,name_layer, classNumber);
		}
		else
		{
			Person** temp = new Person*[amount_of_all_the_person_in_school + 1];
			for (int i = 0; i < amount_of_all_the_person_in_school; i++)
			{
				temp[i] = array_of_all_the_person_in_school[i];
			}
			temp[amount_of_all_the_person_in_school] = new Tutor(firstName, lastname, id, numCourses, seniority, name_layer, classNumber);
			//delete[]person;
			array_of_all_the_person_in_school = temp;
		}
		amount_of_all_the_person_in_school += 1;
		for (int i = 0; i < amount_of_all_the_person_in_school; i++)
		{
			if (array_of_layers_in_school[i]->get_name_chihva()== name_layer)
			{
				convertLevel = i;
				break;
			}
		}

		/*if (dynamic_cast<Tutor*>(person[0]))
		{
		layer[convertLevel]->Place_class(classNumber - 1)->setTutor(&((Tutor*)(person[0])));
		cout << "Add Tutor successfully!" << endl;
		}*/
	}
}

void School:: PRint_workers_and_pupils_details()// print all the people 
{    
	cout << "-----------------------ALLL PEOPLE IN SCHOOL --------------------------" << endl;
	for (int i = 0; i < amount_of_all_the_person_in_school; i++)
	{    
		cout << "-----------------------------------------------------------"<<endl;
		array_of_all_the_person_in_school[i]->Print_details_Person();
		cout << "-----------------------------------------------------------"<<endl;
	}
}

void School ::ADD_Manager()
{

	string firstName, lastname;
	int id, seniority;
	cout << "Please enter MAnager first name:"; cin >> firstName; cout << "Your last name:"; cin >> lastname; cout << "your id :"; cin >> id; cout << "seniority :"; cin >> seniority;
	

	if (Check_number_id(id) && (!check_if_exist_manager))
	{
		if (amount_of_all_the_person_in_school == 0)
		{
			array_of_all_the_person_in_school[0] = new Manager(firstName, lastname, id, seniority);
		}
		else
		{
			Person** temp = new Person*[amount_of_all_the_person_in_school + 1];
			for (int i = 0; i < amount_of_all_the_person_in_school; i++)
			{
				temp[i] = array_of_all_the_person_in_school[i];
			}
			temp[amount_of_all_the_person_in_school] = new Manager(firstName, lastname, id, seniority);
			//delete[]person;
			array_of_all_the_person_in_school = temp;
		}
		check_if_exist_manager = true;
		amount_of_all_the_person_in_school += 1;
	}
	for (int i = 0; i < amount_of_all_the_person_in_school; i++)
	{
		cout << array_of_all_the_person_in_school[i]->get_name_person();
	}
}

void School::ADD_SEcretary()
{
	string firstName, lastname;
	int id, seniority, amount_Of_Children;
	cout << "Please enter Secretary first name:"; cin >> firstName; cout << "Your last name:"; cin >> lastname; cout << "your id :"; cin >> id;
	cout << "seniority :"; cin >> seniority;  cout<<"amount of children:";  cin>>amount_Of_Children;
	

	if (Check_number_id(id))
	{
		if (amount_of_all_the_person_in_school == 0)
		{

			array_of_all_the_person_in_school[0] = new Secretary(firstName, lastname, id, seniority, amount_Of_Children);
		}
		else
		{
			Person** temp = new Person*[amount_of_all_the_person_in_school + 1];
			for (int i = 0; i < amount_of_all_the_person_in_school; i++)
			{
				temp[i] = array_of_all_the_person_in_school[i];
			}
			temp[amount_of_all_the_person_in_school] = new Secretary(firstName, lastname, id, seniority, amount_Of_Children);
			//delete[]person;
			array_of_all_the_person_in_school = temp;
		}
		amount_of_all_the_person_in_school += 1;
	}
	for (int i = 0; i < amount_of_all_the_person_in_school; i++)
	{
		cout << array_of_all_the_person_in_school[i]->get_name_person();
	}
}

void School::Print_oustanding_people()
{

	for (int i = 0; i < amount_of_all_the_person_in_school; i++)//ran Through all the person array
	{
		if (typeid(Pupil) == typeid(*array_of_all_the_person_in_school[i]))//print pupil details include Grades and GPA
		{
			dynamic_cast<Pupil*>(array_of_all_the_person_in_school[i])->Print_details_Person();
		}
		if (typeid(Teacher) == typeid(*array_of_all_the_person_in_school[i]))//print Teacher details include name of course he teach
		{
			dynamic_cast<Teacher*>(array_of_all_the_person_in_school[i])->Print_details_Person();
		}
		if (typeid(Tutor) == typeid(*array_of_all_the_person_in_school[i]))//print Tutor details include layer and number class
		{
			dynamic_cast<Tutor*>(array_of_all_the_person_in_school[i])->Print_details_Person();
		}
		if (typeid(Secretary) == typeid(*array_of_all_the_person_in_school[i]))//print Secretary details 
		{
			dynamic_cast<Secretary*>(array_of_all_the_person_in_school[i])->Print_details_Person();
		}
		if (typeid(Manager) == typeid(*array_of_all_the_person_in_school[i]))//print Manager details 
		{
			dynamic_cast<Manager*>(array_of_all_the_person_in_school[i])->Print_details_Person();
		}



	}
}

bool School::Check_number_id(int id)
{
           for (int i = 0; i < amount_of_all_the_person_in_school; i++) // check if the id is already exist
           {
               	if ( array_of_all_the_person_in_school[i]->get_number_id_person()==id)
	                 {
	                    	cout << "the id is already exist,try another one" << endl;
	                      	return false;
                      	}
             	else{
                 		return true;
	                }
            }

}

void School::Print_tutor_class()
{
	int id;
	cout << "Enter tutor id" << endl;
	cin >> id;
	for (int i = 0; i < amount_of_all_the_person_in_school; i++)//ran Through all the person array
	{
		if (typeid(Tutor) == typeid(*array_of_all_the_person_in_school[i]))//print outstanding Tutor details include layer and number class
		{
			if (array_of_all_the_person_in_school[i]->get_number_id_person() == id)//check if id tutor exist
			{
				dynamic_cast<Tutor*>(array_of_all_the_person_in_school[i])->Print_details_Person();//if tutor is Outstanding print details
			}
		}
	}
}

void School::Print_worker_details_with_biggest_salray()
{

	//int Salary = 0, index = 0;
	//string name;
	//for (int i = 0; i < amount_of_all_the_person_in_school; i++)//ran Through all the person array
	//{
	//	if (typeid(Teacher) == typeid(*array_of_all_the_person_in_school[i]))//check if it employee is Teacher
	//	{
	//		if ((dynamic_cast<Teacher*>(array_of_all_the_person_in_school[i])->return_salary_worker())-> Salary)//calculat how has a Higher salary
	//		{
	//			Salary = (dynamic_cast<Teacher*>(array_of_all_the_person_in_school[i])->return_salary_worker());//save higher salary
	//			index = i;
	//			name = "Teacher";
	//		}
	//	}
	//	if (typeid(Tutor) == typeid(*array_of_all_the_person_in_school[i]))//check if it employee is Tutor
	//	{
	//		if ((dynamic_cast<Tutor*>(array_of_all_the_person_in_school[i])-) > Salary)//calculat how has a Higher salary
	//		{
	//			Salary = dynamic_cast<Tutor*>(person[i])->Salary();//save higher salary
	//			index = i;
	//			name = "Tutor";
	//		}
	//	}
	//	if (typeid(Secretary) == typeid(*person[i]))//check if it employee is Secretary
	//	{
	//		if ((dynamic_cast<Secretary*>(person[i])->Salary_secretary()) > Salary)//calculat how has a Higher salary
	//		{
	//			Salary = dynamic_cast<Secretary*>(person[i])->Salary_secretary();//save higher salary
	//			index = i;
	//			name = "Secretary";
	//		}
	//	}
	//	if (typeid(Manager) == typeid(*person[i]))///check if it employee is Manager 
	//	{
	//		if ((dynamic_cast<Manager*>(person[i])->Salary_manager()) > Salary)//calculat how has a Higher salary
	//		{
	//			Salary = dynamic_cast<Manager*>(person[i])->Salary_manager();//save higher salary
	//			index = i;
	//			name = "Manager";
	//		}
	//	}
	//}
	//if (name == "Teacher")//check employee type(tutor/teacher/manager/Secretary)
	//	dynamic_cast<Teacher*>(person[index])->Print_teacher();//print teacher details
	//if (name == "Tutor")//check employee type(tutor/teacher/manager/Secretary)
	//	dynamic_cast<Tutor*>(person[index])->Print_tutor();//print Tutor details
	//if (name == "Secretary")//check employee type(tutor/teacher/manager/Secretary)
	//	dynamic_cast<Secretary*>(person[index])->Print_secretary();//print Secretary details
	//if (name == "Manager")//check employee type(tutor/teacher/manager/Secretary)
	//	dynamic_cast<Manager*>(person[index])->Print_manager();//print Manager details

}