#pragma once
#include "functii.h"

struct User {
private:
	int id{};
	string nume,prenume, email, parola;


public:
	User() {}

	User(int id, string nume,string prenume, string email, string parola) {
		this->id = id;
		this->prenume = prenume;
		this->nume = nume;
		this->email = email;
		this->parola = parola;
	}

	void SetNume(string nume)
	{
		this->nume = nume;
	}
	void SetPrenume(string prenume){
		this->prenume = prenume;
	}
	void SetId(int id) {
		this->id = id;
	}
	void SetEmail(string email) {
		this->email = email;
	}
	void SetParola(string parola) {
		this->parola = parola;
	}
	string GetNume() {
		return this->nume;
	}
	string GetPrenume() {
		return this->prenume;
	}
	string GetEmail() {
		return this->email;
	}
	string GetParola() {
		return this->parola;
	}
	int GetId() {
		return this->id;
	}
	
	void descriere_persoana() {
		string t = "";
		t += "Nume: " + GetNume() + " " + GetPrenume() + "\n";
		t += "Email: " + GetEmail() + "\n";

		cout << t;
	}
	void descriere_privata() {
		string t="";
		t += "Nume: " + GetNume() + " " + GetPrenume() + "\n";
		t += "Email: " + GetEmail() + "\n";
		t += "Parola: " + GetParola() + "\n";
		t += "--------id: " + to_string(GetId()) + "----------\n\n";

		cout << t;
	}


};
