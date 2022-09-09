#include <iostream>
#include "Person.h"
using namespace std;
int main() {
	//criando dois objetos
    Person person1 = Person("Joao Paulo Oliveira de Barros Soeiro Felipe de Sobral", 60, "Feminino", "United States");
	Person person2 = Person();

	//mostra os atribubtos e dados cadastrados do objeto person1
	person1.registeredData();
	person1.print();

	//mostra os atribubtos e dados cadastrados do objeto person2
	person2.print();
	person2.registeredData();
    
	//interssante utilizar dessa forma também :)
	
	// Person *person1 = new Person("Joao Paulo Oliveira de Barros Soeiro Felipe de Sobral", 60, "Feminino", "United States");
	// Person *person2 = new Person();
	// person1 -> print();
	// person1 -> registeredData();
	// person2 -> print();
	// person2 -> registeredData();
  return 0;
}