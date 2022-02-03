#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
using namespace std;

class student {
	map<string, string> m;
public:
	student(string login, string parol)
	{
		auto it = m.find(login);
		if (it == m.end())
		{
		
			m.insert({ login , parol });
			
		}
	
	}
	void set()
	{
		string login,  parol ;
		cout << "Enter your login : ";
		cin >> login;
		cout << "Enter your parol : ";
		cin >> parol;
		auto it = m.find(login);
		if (it == m.end())
		{

			m.insert({ login , parol });

		}
	}
	void add_new_student()
	{

	}
};
int main()
{

	return 0;

}