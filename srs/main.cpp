#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedIn();

int main()
{
	int choice;

	cout << "1: Register\n";
	cout << "2: Login\n";

	cout << "Your choice: ";
	cin >> choice;

	if(choice == 1)
	{
		string username, password;

		cout << "Select a username: ";
		cin >> username;

		cout << "Select a password: ";
		cin >> password;

		ofstream file;
		file.open("c:" + username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	} 

	if(choice == 2) 
	{
		bool status = isLoggedIn();

		if(!status) 
		{
			cout << "False login!" << endl;
			system("pause");
			return 0;
		}
		else
		{
			cout << "Successfully logged in!" << endl;
			system("pause");
			return 1;
		}
	}
}

bool isLoggedIn() 
{
	string username, password, un, pw;

	cout << "Enter username: ";
	cin >> username;

	cout << "Enter password: ";
	cin >> password;

	ifstream read("c:" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	if(un == username && pw == password) 
	{
		return true;
	} 
	else
	{
		return false;
	}
}