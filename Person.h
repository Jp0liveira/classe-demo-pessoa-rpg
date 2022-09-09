#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
using namespace std;
class Person{
// Vi que o ideal é sempre manter eles privados :)
	private:
		//atributos
		string name, sex, nationality;
		int age;
	public:
		//prototipando os métodos
		Person(string Aname = "Joao", int Aage = 21, string Asex = "Masculino", string Anationality = "Brasileiro");//método construtor
		void registeredData();//método para mostrar os dados cadastrados
		void print();//método que "avalia" algumas caracteristicas e exibe
};

#endif
