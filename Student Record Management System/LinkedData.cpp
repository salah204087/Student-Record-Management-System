#include "LinkedData.h"
#include <cstddef>
#include<iostream>
using namespace std;
LinkedData::LinkedData()
{
	first = last = NULL;
	length = 0;
}

bool LinkedData::isempty()
{
	return length == 0;
}

void LinkedData::search(string Name)
{
	Node* curr = first;
	int pos = 0;
	int check = 0;
	while (curr != NULL)
	{
		if (curr->name == Name)
		{
			cout << "					Found at position:" << pos<<endl;
			cout << "Name:" << curr->name << endl;
			cout << "Age:" << curr->age << endl;
			cout << "Sex:" << curr->sex << endl;
			cout << "E-Mail:" << curr->e_mail << endl;
			cout << "Phone Number:" << curr->phone << endl;
			cout << "Status:" << curr->status << endl;
			cout << "Education:" << curr->education << endl;
			check++;
		}
		curr = curr->next;
		pos++;
	}
	if(check==0)
		cout<<"Not found"<<endl;
}

int LinkedData::search_return(string name)
{
	Node* curr = first;
	int pos = 0;
	while (curr != NULL)
	{
		if (curr->name == name)
			return pos;
		curr = curr->next;
		pos++;
	}
		return -1;
}

void LinkedData::RemoveStudent(string Name)
{
	if (isempty())
	{
		cout << "The system is empty" << endl;
	}
	else
	{
		Node* curr, * prev;
		if (first->name == Name)
		{
			Node* curr = first;
			first = first->next;
			delete curr;
			length--;
		}
		else
		{
			curr = first->next;
			prev = first;
			while (curr != NULL)
			{
				if (curr->name == Name)
					break;
				prev = curr;
				curr = curr->next;
			}

			if (curr == NULL)
				cout << "student is not the system" << endl;
			else
			{
				prev->next = curr->next;
				if (last == curr)
					last = prev;
				delete curr;
				length--;
			}
		}
	}
}

void LinkedData::print()
{
	Node* curr = first;
	while (curr != NULL)
	{
		cout << "Name:" << curr->name << endl;
		cout << "Age:" << curr->age << endl;
		cout << "Sex:" << curr->sex << endl;
		cout << "E-Mail:" << curr->e_mail << endl;
		cout << "Phone Number:" << curr->phone<<endl;
		cout << "Status:" << curr->status << endl;
		cout << "Education:" << curr->education << endl;
		cout << "			**********************************************************************			"<<endl;
		curr = curr->next;
	}
	cout << endl;
}
