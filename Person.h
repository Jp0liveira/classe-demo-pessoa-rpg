#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
using namespace std;
class Person{
// Vi que o ideal é sempre manter eles privados :)
	private:
		string name;
		int age;
		string sex;
		string nationality;
	public:
		Person(string Aname = "Joao", int Aage = 21, string Asex = "Masculino", string Anationality = "Brasileiro");
		void registeredData();
		void print();
};

#endif
