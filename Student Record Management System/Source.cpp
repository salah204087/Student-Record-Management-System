#include <iostream>
using namespace std;
#include"GetData.h"
#include <algorithm>
int main()
{
	GetData system;
	string choose;
	string secondchoose;
	while (true)
	{
		cout << "1-Add new student\n" << "2-Search about student\n" << "3-Remove student\n" << "4-Edit student informtion\n" << "5-Show all student\n" << "6-Number of student in system\n"<<"7-Exit\n";
		cout << "Please enter your choice:";
		getline(cin >> ws, choose);
		for_each(choose.begin(), choose.end(), [](char& c) {
			c = ::tolower(c); });
		if (choose == "1" || choose == "add new student")
		{
			while (true)
			{
				system.GetAllData();
				cout << "Do you want add another student?\n" << "1-Yes\n" << "2-No\n";
				cout << "Enter your choose:";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}

		}
		else if (choose == "2" || choose == "search about student")
		{
			while (true)
			{
				string namesearch;
				cout << "Enter name of student you want to search about him:";
				getline(cin >> ws, namesearch);
				for_each(namesearch.begin(), namesearch.end(), [](char& c) {
					c = ::tolower(c); });
				system.search(namesearch);
				cout << "Do you want search about another student?\n" << "1-Yes\n" << "2-No\n";
				cout << "Enter your choose:";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}

		}
		else if (choose == "3" || choose == "remove student")
		{
			while (true)
			{
				string deletestudent;
				cout << "Enter name of student you remove:";
				getline(cin >> ws, deletestudent);
				for_each(deletestudent.begin(), deletestudent.end(), [](char& c) {
					c = ::tolower(c); });
				system.RemoveStudent(deletestudent);
				cout << "Do you want remove another student?\n" << "1-Yes\n" << "2-No\n";
				cout << "Enter your choose:";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}

		}
		else if (choose == "4" || choose == "edit student informtion")
		{
			while (true)
			{
				string editstudent;
				cout << "Enter name of student you to edit:";
				getline(cin >> ws, editstudent);
				for_each(editstudent.begin(), editstudent.end(), [](char& c) {
					c = ::tolower(c); });
				system.EditData(editstudent);
				cout << "Do you want edit another student?\n" << "1-Yes\n" << "2-No\n";
				cout << "Enter your choose:";
				getline(cin >> ws, secondchoose);
				for_each(secondchoose.begin(), secondchoose.end(), [](char& c) {
					c = ::tolower(c); });
				if (secondchoose == "1" || secondchoose == "yes")
					continue;
				else
					break;
			}

		}
		else if (choose == "5" || choose == "show all student")
			system.print();
		else if (choose == "6" || choose == "number of student in system")
			cout << "Number of students in system is:" << system.length << endl;
		else if (choose == "7" || choose == "exit")
			break;
		else
			cout << "Please enter valid choice" << endl;
	}
}