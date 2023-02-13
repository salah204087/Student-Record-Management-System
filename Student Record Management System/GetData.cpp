#include "GetData.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int GetData::isWhitespace(string& str)
{
	int count = 0;
	int length = str.length();
	for (int i = 0; i < length; i++) {
		int c = str[i];
		if (isspace(c))
			count++;
	}
	return count;
}

string GetData::GetName()
{
	string name;
	regex regx("[@_!#$%^&*()<>?/|}{~:.]");
	cout << "Enter student's name:";
	while (true)
	{
		getline(cin >> ws, name);
		if (any_of(name.begin(), name.end(), ::isdigit)|| regex_search(name, regx) != 0)
		{
			cout << "Please enter valid name doesn't containing digits or symbols:";
		}
		else
			break;
	}
	for_each(name.begin(), name.end(), [](char& c) {
		c = ::tolower(c); });
	return name;
}

string GetData::GetPhoneNumber()
{
	string phone;
	regex regx("[@_!#$%^&*()<>?/|}{~:.]");
	cout << "Enter a student's phone number:";
	while (true)
	{
		getline(cin >> ws, phone);
		string first_three= phone.substr(0, 3);
		if (isWhitespace(phone)!=0 
			||( first_three != "010"
			&& first_three != "011"
			&& first_three != "012"
			&& first_three != "015")
			||phone.size()!=11
			||any_of(phone.begin(), phone.end(), ::isalpha)
			|| regex_search(phone, regx) != 0)
			cout << "Please enter valid phone number:";
		else
			break;
	}
	return phone;
}

string GetData::GetMail()
{
	string mail;
	regex regx("[!#$%^&*()<>?/|}{~:]");
	cout << "Enter the student's e_mail:";
	while (true)
	{
		string check = "not found";
		getline(cin >> ws, mail);
		if (mail.find("@") != std::string::npos
			&& mail.find(".") != std::string::npos) {
			check = "found";
		}
		else
			check = "not found";
		if (regex_search(mail, regx) != 0
			|| isWhitespace(mail) != 0
			||check=="not found")
			cout << "Please enter valid mail it doesn't contain this symbols([!#$%^&*()<>?/|}{~:],white space and must containing (@) and (.):";
		else
			break;
	}
	return mail;
}

int GetData::GetAge()
{
	int age = 0;
	cout << "Enter your age:";
	while (true)
	{
		cin >> age;
		if (age < 6)
			cout << "Please enter valid age(The legal age to enter school is six years):";
		else
			break;
	}
	return age;
}

string GetData::GetGender()
{
	string gender;
	cout << "1-male\n" << "2-female\n";
	while (true)
	{
		getline(cin, gender);
		for_each(gender.begin(), gender.end(), [](char& c) {
			c = ::tolower(c); });
		if (gender == "1" || gender == "male")
			return gender = "male";
		else if (gender == "2" || gender == "female")
			return gender = "female";
		else
		{
			cout << "please enter valid gender:";
			continue;
		}
	}
}

string GetData::GetRelationship(int age)
{
	string status;
	cout << "1-single\n" << "2-married\n";
	while (true)
	{
		getline(cin>>ws, status);
		for_each(status.begin(), status.end(), [](char& c) {
			c = ::tolower(c); });
		 if(age<18&&(status=="2"||status=="married"))
		{
			cout << "please enter valid gender(The legal age for marriage is 18 years):";
			continue;
		}
		 else
		 {
			
			 if (status == "1" || status == "single")
				 return status = "single";
			 else if (status == "2" || status == "married")
				 return status = "married";
			 else
				 continue;
		 }
	}
}

string GetData::GetEducationalLevel(int age)
{
	string education;
	string level;
	string faculty;
	cout << "1-Primary stage\n" << "2-middle stage\n" << "3-High stage\n" << "4-University stage\n";
	cout << "Enter student's Educational Level:" << endl;
	while (true)
	{
		getline(cin >> ws, education);
		for_each(education.begin(), education.end(), [](char& c) {
			c = ::tolower(c); });
		if (education == "1" || education == "primary stage")
		{
			cout << "1-First grade\n" << "2-Second grade\n" << "3-Third grade\n" << "4-Fourth grade\n" << "5-Fifth grade\n" << "6-Sixth grade\n";
			cout << "Enter primary stage level:";
			while (true)
			{
				getline(cin >> ws, level);
				for_each(level.begin(), level.end(), [](char& c) {
					c = ::tolower(c); });
				if (level == "1" || level == "first grade")
					return "Primary stage, first grade";
				else if (level == "2" || level == "second grade")
					return "Primary stage, second grade";
				else if (level == "3" || level == "third grade")
					return "Primary stage, third grade";
				else if (level == "4" || level == "fourth grade")
					return "Primary stage, second grade";
				else if (level == "5" || level == "fifth grade")
					return "Primary stage, fifth grade";
				else if (level == "6" || level == "sixth grade")
					return "Primary stage, sixth grade";
				else
				{
					cout << "please enter valid level:";
					continue;
				}
			}
			
		}
		else if ((education == "2" || education == "middle stage")&&age>11)
		{
			cout << "1-First grade\n" << "2-Second grade\n" << "3-Third grade\n";
			cout << "Enter middel stage level:";
			while (true)
			{
				getline(cin >> ws, level);
				for_each(level.begin(), level.end(), [](char& c) {
					c = ::tolower(c); });
				if (level == "1" || level == "first grade")
					return "middle stage, first grade";
				else if (level == "2" || level == "second grade")
					return "middle stage, second grade";
				else if (level == "3" || level == "third grade")
					return "middle stage, third grade";
				else
				{
					cout << "please enter valid level(The specified age to enter thew middle stage is 12 years old):";
					continue;
				}
			}
		}
		else if ((education == "3" || education == "High stage")&&age>14)
		{
			cout << "1-First grade\n" << "2-Second grade\n" << "3-Third grade\n";
			cout << "Enter High stage level:";
			while (true)
			{
				getline(cin >> ws, level);
				for_each(level.begin(), level.end(), [](char& c) {
					c = ::tolower(c); });
				if (level == "1" || level == "first grade")
					return "High stage, first grade";
				else if (level == "2" || level == "second grade")
					return "High stage, second grade";
				else if (level == "3" || level == "third grade")
					return "High stage, third grade";
				else
				{
					cout << "please enter valid level(The specified age to enter the high stage is 15 years old):";
					continue;
				}
			}

		}
		else if ((education == "4" || education == "University stage")&&age>17)
		{
			cout << "1-Faculty of Engineering\n" <<"2-Faculty of medicine\n" << "3-Faculty of computers and Artificial Intelligence\n" << "4-faculty of Pharmacy\n" << "5-faculty of Agriculture\n" << "6-faculty of Science\n"<<"7-Faculty of Economics and Political Science\n"<<"8-factly of media\n"<<"9-Faculty of Archaeology\n"<<"10-Faculty of Literature\n"<<"11-Faculty of Commerce\n"<<"12-Faculty of education quality\n"<<"13-Faculty of Nursing\n"<<"14-Faculty of Law"<<"15-Faculty of Physiotherapy\n"<<"16-Faculty of Dentistry\n"<<"17-Faculty of Veterinary Medicine\n"<<"18-Faculty of Dar Al Uloom\n"<<"19-Faculty of Early Childhood Education\n";
			cout << "Enter student's facutly:";
			while (true)
			{
				getline(cin >> ws, faculty);
				for_each(faculty.begin(), faculty.end(), [](char& c) {
					c = ::tolower(c); });
				if (faculty == "1" || faculty == "faculty of engineering")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n"<<"4-Fourth Division\n"<<"5-Fifth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the College of Engineering";
						else if (level == "2" || level == "second division")
							return "Second Division of the College of Engineering";
						else if (level == "3" || level == "third division")
							return "Third Division of the College of Engineering";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the College of Engineering";
						else if (level == "5" || level == "fifth division")
							return "Fifth Division of the College of Engineering";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "2" || faculty == "faculty of medicine")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n" << "5-Fifth Division\n"<<"6-Sixth Division\n"<<"7-Seventh Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the College of Medicine";
						else if (level == "2" || level == "second division")
							return "Second Division of the College of Medicine";
						else if (level == "3" || level == "third division")
							return "Third Division of the College of Medicine";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the College of Medicine";
						else if (level == "5" || level == "fifth division")
							return "Fifth Division of the College of Medicine";
						else if (level == "6" || level == "sixth division")
							return "Sixth Division of the College of Medicine";
						else if (level == "7" || level == "seventh division")
							return "Seventh Division of the College of Medicine";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "3" || faculty == "faculty of computers and artificial intelligence")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Computers and Artificial Intelligence";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Computers and Artificial Intelligence";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Computers and Artificial Intelligence";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Computers and Artificial Intelligence";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "4" || faculty == "faculty of pharmacy")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n" << "5-Fifth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the College of Pharmacy";
						else if (level == "2" || level == "second division")
							return "Second Division of the College of Pharmacy";
						else if (level == "3" || level == "third division")
							return "Third Division of the College of Pharmacy";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the College of Pharmacy";
						else if (level == "5" || level == "fifth division")
							return "Fifth Division of the College of Pharmacy";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "5" || faculty == "faculty of agriculture")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Agriculture";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Agriculture";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Agriculture";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Agriculture";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "6" || faculty == "faculty of science")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Science";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Science";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Science";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Science";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "7" || faculty == "faculty of economics and political science")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Economics and Political Science";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Economics and Political Science";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Economics and Political Science";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Economics and Political Science";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "8" || faculty == "faculty of media")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of media";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of media";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of media";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of media";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "9" || faculty == "faculty of archaeology")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Archaeology";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Archaeology";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Archaeology";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Archaeology";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "10" || faculty == "faculty of literature")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Literature";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Literature";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Literature";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Literature";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "11" || faculty == "faculty of commerce")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Commerce";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Commerce";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Commerce";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Commerce";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "12" || faculty == "faculty of education quality")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of education quality";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of education quality";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of education quality";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of education quality";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "13" || faculty == "faculty of nursing")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Nursing";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Nursing";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Nursing";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Nursing";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "14" || faculty == "faculty of law")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Law";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Law";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Law";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Law";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "15" || faculty == "faculty of physiotherapy")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Physiotherapy";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Physiotherapy";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Physiotherapy";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Physiotherapy";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "16" || faculty == "faculty of dentistry")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n"<<"5-Fifth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Dentistry";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Dentistry";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Dentistry";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Dentistry";
						else if (level == "5" || level == "fifth division")
							return "Fifth Division of the Faculty of Dentistry";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "17" || faculty == "faculty of veterinary medicine")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n" << "5-Fifth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Veterinary Medicine";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Veterinary Medicine";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Veterinary Medicine";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Veterinary Medicine";
						else if (level == "5" || level == "fifth division")
							return "Fifth Division of the Faculty of Veterinary Medicine";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "18" || faculty == "faculty of dar al uloom")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Dar Al Uloom";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Dar Al Uloom";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Dar Al Uloom";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Dar Al Uloom";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}
				else if (faculty == "19" || faculty == "faculty of early childhood education")
				{
					cout << "1-First Division\n" << "2-Second Division\n" << "3-Third Division\n" << "4-Fourth Division\n";
					cout << "Enter University stage Division:";
					while (true)
					{
						getline(cin >> ws, level);
						for_each(level.begin(), level.end(), [](char& c) {
							c = ::tolower(c); });
						if (level == "1" || level == "first division")
							return "First Division of the Faculty of Early Childhood Education";
						else if (level == "2" || level == "second division")
							return "Second Division of the Faculty of Early Childhood Education";
						else if (level == "3" || level == "third division")
							return "Third Division of the Faculty of Early Childhood Education";
						else if (level == "4" || level == "fourth division")
							return "Fourth Division of the Faculty of Early Childhood Education";
						else
						{
							cout << "please enter valid level:";
							continue;
						}
					}
				}

			}
		}
		else
		{
			cout << "please Enter valid education(The specified age to enter the university stage is 18 years old):";
			continue;
		}

	}
}

void GetData::GetAllData()
{

	Node* newnode = new Node;
	newnode->name = GetName();
	newnode->phone = GetPhoneNumber();
	newnode->e_mail = GetMail();
	int age=newnode->age = GetAge();
	newnode->sex = GetGender();
	newnode->status = GetRelationship(age);
	newnode->education = GetEducationalLevel(age);
	if (isempty())
	{
		first = last = newnode;
		newnode->next = NULL;
	}
	else
	{
		last->next = newnode;
		newnode->next = NULL;
		last = newnode;
	}
	length++;
}

void GetData::GetNumberOfStudent()
{
	cout << "Number of student in system is:" << length;
}

void GetData::EditData(string name)
{
	int pos=search_return(name);
	if (pos != -1)
	{
		string choose;
		string secondchoose;
		search(name);
		Node* curr = first;
		for (int i = 0; i < pos; i++)
			curr = curr->next;
		while (true)
		{
			cout << "1-Edit name\n" << "2-Edit Phone Number\n" << "3-Edit E-Mail\n" << "4-Edit Age\n" << "5-Edit Gender\n" << "6-Edit Relationship\n" << "7-Edit Education\n" << "8-Edit all\n"<<"9-Return to main screen\n";
			cout << "Please enter valid choice:";
			getline(cin >> ws, choose);
			for_each(choose.begin(), choose.end(), [](char& c) {
				c = ::tolower(c); });
			if (choose == "1" || choose == "edit name")
			{
				curr->name = GetName();
				cout << "Do you want edit another thing?\n"<<"1-Yes\n"<<"2-No\n";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}
			else if (choose == "2" || choose == "edit phone number")
			{
				curr->phone = GetPhoneNumber();
				cout << "Do you want edit another thing?\n" << "1-Yes\n" << "2-No\n";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}
			else if (choose == "3" || choose == "edit e-mail")
			{
				curr->e_mail = GetMail();
				cout << "Do you want edit another thing?\n" << "1-Yes\n" << "2-No\n";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}
			else if (choose == "4" || choose == "edit age")
			{
				curr->age = GetAge();
				cout << "Do you want edit another thing?\n" << "1-Yes\n" << "2-No\n";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}
			else if (choose == "5" || choose == "edit gender")
			{
				curr->sex = GetGender();
				cout << "Do you want edit another thing?\n" << "1-Yes\n" << "2-No\n";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}
			else if (choose == "6" || choose == "edit relationship")
			{
				curr->status = GetRelationship(curr->age);
				cout << "Do you want edit another thing?\n" << "1-Yes\n" << "2-No\n";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}
			else if (choose == "7" || choose == "edit education")
			{
				curr->education = GetEducationalLevel(curr->age);
				cout << "Do you want edit another thing?\n" << "1-Yes\n" << "2-No\n";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}
			else if (choose == "8" || choose == "edit all")
			{
				curr->name = GetName();
				curr->phone = GetPhoneNumber();
				curr->e_mail = GetMail();
				curr->age = GetAge();
				curr->sex = GetGender();
				curr->status = GetRelationship(curr->age);
				curr->education = GetEducationalLevel(curr->age);
				cout << "Do you want edit another thing?\n" << "1-Yes\n" << "2-No\n";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}
			else if (choose == "9" || choose == "return to main screen")
				break;
			else
			{
				continue;
			}

		}
	}
	else
		cout << "Name not found"<<endl;
	
	
}
