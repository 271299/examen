#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

class students{
	map<string , string> m;
public:
	students(){}
	students(string login, string parol)
	{
		auto it = m.find(login);
		if (it == m.end())
		{
			m.insert({ login , parol });
		}
	}
	void to_register()
	{
		cout << "Registration : ";
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
	bool check_login()
	{
		string login;
		cout << "Enter your login : ";
		cin >> login;
		auto it = m.find(login);
		if (it != m.end())
		{
			return true;
		}
		else return false;
	}
};
class admin {
	string login;
	string password;
public:
	admin()
	{
		this->login = " ";
		this->password = " ";
	}
	admin(string ligin, string password)
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
class questions {
	string question;
	list<answer> answers;
	int  correct_answer;
public:
	questions() { this->question = " "; }
	questions(string question, list<answer> a , int b )
	{
		this->question = question;
		this->answers = a;
		this->correct_answer = b;
	}
	void print_question()
	{
		cout << question<<"\n";
	}
	void print_answer()
	{
		for (auto it=answers.begin(); it!=answers.end(); it++)
		{
			it->print();
		}
	}
	string get_question()
	{
		return question;
	}
	int get_number_of_correct_answer()
	{
		return correct_answer;
	}
	
};
	
class test {
	list<questions> t;
	int rating;
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
};
class system {
	admin a;
	students s;
public:


};
int main()
{
	students s("anna" , "maukh");
	if (s.check_login() == true)
	{
	
		cout << "user find !";
	}
	else {
		s.to_register();
	}
	return 0;

}