#pragma once
#include "LinkedData.h"
#include <string>
using namespace std;
class GetData:public LinkedData
{
private:
	LinkedData Data;
public:
	int isWhitespace(string& str);
	string GetName();
	string GetPhoneNumber();
	string GetMail();
	int GetAge();
	string GetGender();
	string GetRelationship(int age);
	string GetEducationalLevel(int age);
	void GetAllData();
	void GetNumberOfStudent();
	void EditData(string name);
	

};

