#pragma once
#include <string>
using namespace std;
class LinkedData
{
public:
	struct Node
	{
		string name;
		int age;
		string e_mail;
		string phone;
		string sex;
		string status;
		string education;
		Node* next;
	};
	Node* first;
	Node* last;
	int length;
	LinkedData();
	bool isempty();
	void search(string Name);
	int search_return(string name);
	void RemoveStudent(string Name);
	void print();
};

