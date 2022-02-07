#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class students{
	map<string , string> m;
	string path;
	fstream fs;
public:
	students(){}

	void to_register(string path)
	{
		cout << "   Registration !\n";
		string login,  parol ;
		cout << "Create your login : ";
		cin >> login;
		cout << "Create your parol : ";
		cin >> parol;
		auto it = m.find(login);
		if (it != m.end())
		{

			cout << "This user already exists !";
		}
		else {
			m.insert({ login , parol });

			fs.open( path, fstream::out);
			if (!fs.is_open())
			{
				cout << "Error open file !";
			}
			else
			{
				fs << login  <<" "<< parol;
			}
			fs.close();
		}
	}
	bool check_login(string path)
	{
		string login ,password , login1 , password1;
		cout << "Enter your login : ";
		cin >> login;
		cout << "Enter your password : ";
		cin >> password;
			fs.open(path, fstream::in);
			while (!fs.eof()) {
				fs >> login1 >> password1;
				if (login == login1 && password ==password1) {
					return true;
				}
			}
			fs.close();
		return false;
		
	}
};
class admin {
	string login;
	string password;
	string path;
	fstream fs;
public:
	admin()
	{
		this->login = " ";
		this->password = " ";
	}
	admin(string login, string password)
	{
		this->login = login;
		this->password = password;
	}
	string get_login()
	{
		return login;
	}
	string get_password()
	{
		return  password;
	}
	void save_in_file(string path)
	{
		fs.open(path, fstream::out);
		if (!fs.is_open())
		{
			cout << "Error open file !";
		}
		else
		{
			fs << login << " " << password;
		}
		fs.close();
	}
	bool cheak_admin(string path)
	{
		string login, password, login1, password1;
		cout << "Enter your login : ";
		cin >> login;
		cout << "Enter your password : ";
		cin >> password;
		fs.open(path, fstream::in);
		while (!fs.eof()) {
			fs >> login1 >> password1;
			if (login == login1 && password == password1) {
				return true;
			}
		}
		fs.close();
		return false;

	}
};
class answer {
	string a;
	int number_of_answer;
public:
	answer() { this->a = "no set"; this->number_of_answer = 0; }
	answer(string a , int number_of_answer) 
	{ 
		this->a = a;
		this->number_of_answer = number_of_answer;
	}
	void print()
	{
		cout << number_of_answer<<" ";
		cout << a << "\n";
	}
	string get_answer()
	{
		return a;
	}
	int get_number()
	{
		return number_of_answer;
	}
	void set_answer()
	{
		cout << "Number of answer : ";
		cin >> number_of_answer;
		cout << "Enter answer : ";
		cin >> a;
	}
	bool right_answer(int number)
	{
		if (this->number_of_answer == number)
		{
			return true;
		}
		else return false;
	}
};
class questions : answer {
	string q;
	list<answer> answers;
	int  correct_answer;
	string path;
	fstream fs;
public:
	questions() { this->q = " "; }
	questions(string q, list<answer> a , int b )
	{
		this->q = q;
		this->answers = a;
		this->correct_answer = b;
	}
	void print_question()
	{
		cout << q<<"\n";
		for (auto it = answers.begin(); it != answers.end(); it++)
		{
			it->print();
		}
	}
	void save_in_file(string path)
	{
		fs.open(path, fstream::out);
		if (!fs.is_open())
		{
			cout << "Error open file !";
		}
		else
		{
			fs << q;
			for (auto it = answers.begin(); it != answers.end(); it++)
			{
				fs<<it->get_number()<<" " << it->get_answer() << " ";

			}
		}
		fs.close();
	}
	void read_from_file(string path)
	{
		fs.open(path, fstream::in);
		if (!fs.is_open())
		{
			cout << "Error open file !";
		}
		else
		{
			string  new_qestion;
			string new_answer;
			int num;
			map<string, int> n;
			fs >> new_qestion;
			while (!fs.eof()) {
				fs >> new_answer >> num;
				
			}
		}
		fs.close();
	}
	string get_question()
	{
		return q;
	}
	int get_number_of_correct_answer()
	{
		return correct_answer;
	}
	
};
	
class test :questions {
	list<questions> t;
	int rating;
	string path;
	fstream fs;
public:
	test() { rating = 0; }
	test(list<questions> q)
	{
		this->t = q;
		int rating = 0;
	}
	void do_test()
	{
		int answer;
		for (auto it=t.begin();it!=t.end(); it++)
		{
			it->print_question();

			cout << "Enter answer : ";
			cin >> answer;
			if (it->get_number_of_correct_answer() == answer)
			{
				cout << "It is correct ! \n";
				rating++;
			}
			else {
				cout << "It is not correct answer ! \n";
				cout << "The number of the correct answer " << it->get_number_of_correct_answer();
			}
			
		}
	}
	int get_rating()
	{
		return (rating*100)/t.size();
	}
	void save_in_file()
	{
		fs.open(path, fstream::out);
		if (!fs.is_open())
		{
			cout << "Error open file !";
		}
		else
		{
			for (auto it = t.begin(); it != t.end(); it++)
			{
				it->save_in_file(path);
				cout << "\n";
				
			}
		}
		fs.close();
	}
	void read_from_file(string path)
	{
		fs.open(path, fstream::in);
		if (!fs.is_open())
		{
			cout << "Error open file !";
		}
		else
		{
			for (auto it = t.begin(); it != t.end(); it++)
			{
				it->read_from_file(path);
				cout << "\n";

			}
		}
		fs.close();
	}
};
int main()
{
	questions q("Znayditʹ- 6 i 7", list<answer>{ { "5", 4  }, { "5", 5 }} , 4);
	string path = "students";
	string path1 = "admin";
	students s;
	s.to_register(path);
	admin a("anna", "makukh");
	a.save_in_file(path1);


	return 0;

}