/* Assignment: 1
Campus: Ashdod
Author: Yaniv Bohbot, ID: 204892749
*/
#include"MyString.h"

int main()
{
	MyString str;//create a new object who is containt a poiner str ,and length	
	char string[N], charactere; //a table string with size 80 
	int count_upper = 0, count_lower = 0, count_num = 0,numb;
	str.Print();
	cout << "Enter a string :" << endl;

	cin >> string;
	cout << " we allocate memory for the string:" << endl;

	MyString str2(string);// we create a new string 	
	str2.Print();// we print the string
	//cout << "-------------------------" << endl;
	//str.Print();// we print 
	MyString str3(str2); // we copy the object 2 to the object3 
	cout << "we copy the string in new object's string:" << endl;
	str3.Print(); // print the object copied 
	cout <<endl <<"Now Enter a new string for change:" << endl;
	
	cin >> string;
	str.Change_tableaux_str(string); //callfunction for  change the string 
	cout <<endl <<"We change the string to:" << endl;
	str.Print();
	cout <<endl <<"The lenght of the string:" << endl;
	cout << str.getLength() << endl; // call the function for get the size of the table 
	
	cout <<endl <<"Now Enter a chararactere:" << endl;
	cin >> charactere;// chaaractere inserteed by user 
   
	cout <<endl<<"the number of this charactere in the string is:"<<str.Counter_Char(charactere) << endl; // print the numb of this charactere in the string 
	cout << endl << "Wich Word do you want display?"<<endl;
	cout << endl << "Now Enter a the number:" << endl;	
	cin >>numb; // number inserted by user to print the word corresponding to this number 
	
	cout << endl << "the words is:" << str.Find_Word(numb) << endl; // print the word corresponding to this number

	str.by_reference(count_upper, count_lower, count_num);// call the function for update the variable by reference 
	
	cout <<endl <<"NUmber of CAPITAL LETTERS:"<<count_upper << " Number of LOWER Letters:" << count_lower << " Number of Numbers:" << count_num << endl;

	cout <<endl <<"Enter a New str to concatenate to the old:" << endl;
	cin >> string; // the string inserted by user to concatanete to the old one 
	MyString str4(string); // call the constructor 
	 str.Concetanation(str4); 	 // call the function for concatat=nete the string from the new object to the old one 
	cout <<endl<<"the string in big LETTER: "<<endl;
		str.LItlle_to_Upper();// function to convert the UPPER LETTER 
	cout << endl<<"the string in Lower letter:" <<endl;
      str.Bigger_ToLower();// fnction to convert to LOWER LETTER 
	  cout << endl<<endl;

	return 0;
}