#include <iostream>
#include "Person.h"
using namespace std;


Person::Person(string Aname, int Aage, string Asex, string Anationality){
	name = Aname;
	age = Aage;
	sex = Asex;
	nationality = Anationality;
};

void Person::registeredData(){
	cout << "\n\t~ Registerd Data ~\n" << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Sexo: " << sex << endl;
	cout << "Natinality: " << nationality << endl;
	cout << "---------------------------------" << endl;
};

void Person::print(){
	cout << "\t~ Assigned Characteristics ~\n" << endl;
	if (name.size() > 30){
		cout << "your name is very big." << endl;
	}else{
		cout << "Your name is normal." << endl;
	}

	if (nationality == "brasileiro" || nationality == "Brasileiro"){
		cout << "What the fuck to be Brazilian!" << endl;
	}else{
		cout << "What the fuck!" << endl;
	}
	
	if (age <= 0){
		cout << "Invalid age error!" << endl;
	}else if(age < 18){
		cout << "The user is a minor!" << endl; 
	}else if (age >= 18 && age < 30){
		cout << "The user is an adult!" << endl;
	}else if (age >= 30 && age <= 60){
		cout << "The user is a gentleman!" << endl;
	}else{
		cout << "The user has a long life!" << endl;
	}
	
};