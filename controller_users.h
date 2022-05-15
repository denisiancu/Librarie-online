#pragma once
#include "user.h"

struct ControllerUser {
private:
	User useri[50];
	int id, nr_users = 0;
	string nume,prenume, email, parola;

public:
	

	ControllerUser() {
		Citire();
		save();
	}

	void Citire() {
		ifstream f("user_data.txt");
		char aux[250] = "";
		string nume1,prenume1, email1, parola1;
		int id1{};
		bool temp = true;
		srand(time(0)+2);
		id1 = rand() % 100;

		while (temp) {
			f >> aux;
			if (strcmp(aux, "end") == 0) {
				temp = false;
			}
			else
			{
				while (!verificareid(id1))
					id1 = rand() % 100;


				f >> nume1;	
				f >> prenume1;
				f >> email1;

				f >> parola1;

				aux[0] = '\0';
				User u(id1, nume1,prenume1, email1, parola1);
				ImplementareUser(u);
				
			}
		}
	}
	void ImplementareUser(User u){
		useri[nr_users++] = u;
		}

	void AdaugareUser() {
		
		cout << "Introduceti numele: ";
		getline(cin, nume);
		cout << "Introduceti prenumele: ";
		getline(cin, prenume);
		cout << "\nIntroduceti email-ul: ";
		getline(cin, email);
		email = verificare_email(email);
		cout << "\nIntroduceti parola: ";
		getline(cin, parola);
		User u(id, nume,prenume, email, parola);
		ImplementareUser(u);
		clearconsole();
		text_Align(10);
		cout << "Adaugarea a fost facuta cu succes!\n";
	}

	void StergereUser(int id) {
		int n=cautare_byid(id);
		for (int i = n; i < (nr_users-1); i++)
		{
			useri[i] = useri[i + 1];
		}
		nr_users--;
	}
	
	string verificare_email(string t) {
		int n = 0;
		for (int i = 0; i < nr_users; i++)
			if (useri[i].GetEmail() == t)
				n++;
		if (n)
		{
			bool temp = true;
			while (temp) {
				cout << "\nAdresa de email deja folosita!\nVa rugam introduceti alta:";
				getline(cin, email);
				email = verificare_email(email);
				temp = false;
				return email;
			}
		}
		else
		{
			return t;
		}


	}
	//needs id
	int cautare_byid(int id) {

		for (int i = 0; i < nr_users ; i++)
		{
			if (id == useri[i].GetId())
				return i;
		}

		return 0;


	}
	
	//returneaza id ul --needs email
	int cautare_byemail(string email) {
		for (int i = 0; i < nr_users; i++)
			if (useri[i].GetEmail() == email)
				return useri[i].GetId();
	}
	
	bool verificareid(int id) {
		for (int i = 0; i < nr_users; i++)
		{
			if (useri[i].GetId() == id)
				return false;
		}
		return true;

	}
	//Save
	void save() {
		ofstream f("user_data.txt");
		int i;
		for (i = 0; i < nr_users; i++) {
			f << to_string(useri[i].GetId());
			f << " " << useri[i].GetNume() << ' ' << useri[i].GetPrenume() << ' ' << useri[i].GetEmail();
			f << ' ' << useri[i].GetParola() << endl;

		}
		f << "end";


	}

	void afisare_useri() {
		for (int i = 0; i < nr_users; i++)
			useri[i].descriere_privata();

	}
	//afisare separata-needs id
	void afisare_user(int id){
		bool temp = true;
		for (int i = 0; i < nr_users && temp; i++)
		{
			if (id == useri[i].GetId())
			{
				useri[i].descriere_privata();
				temp = false;
			}
		}
	}

	
};
