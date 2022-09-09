#include <iostream>
#include "Person.h"
using namespace std;

int main() {
    Person person1 = Person("Joao Paulo Oliveira de Barros Soeiro Felipe de Sobral", 60, "Feminino", "United States");
	Person person2 = Person();

	person1.print();
	person1.registeredData();

	person2.print();
	person2.registeredData();
    
	// Person *person1 = new Person("Joao Paulo Oliveira de Barros Soeiro Felipe de Sobral", 60, "Feminino", "United States");
	// Person *person2 = new Person();
	// person1 -> print();
	// person1 -> registeredData();
	// person2 -> print();
	// person2 -> registeredData();
  return 0;
}