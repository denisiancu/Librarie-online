#pragma once
#include "functii.h"

struct Data {
	int an{}, luna{}, zi{};

};
struct Book {
private:
	Data data;
	int pret{}, id{};
	string volum, editura, titlu, autor;
public:

	Book() {
	
	}


	Book(int id,string titlu, int pret, Data data, string volum, string editura,string autor) {
		this->SetId(id);
		this->SetTitlu(titlu);
		this->SetAutor(autor);
		this->SetPret(pret);
		this->SetData(data);
		this->SetVolum(volum);
		this->SetEditura(editura);
	}
	void SetTitlu(string titlu) {
		this->titlu = titlu;
	}
	void SetId(int id) {
		this->id = id;
	}
	int GetId() {
		return this->id;
	}
	string GetTitlu() {
		return this->titlu;
	}
	void SetAutor(string autor) {
		this->autor = autor;
	}
	string GetAutor() {
		return this->autor;
	}
	void SetData(Data data1) {
		this->data.an = data1.an;
		this->data.luna = data1.luna;
		this->data.zi = data1.zi;
	}
	int GetAn() {
		return this->data.an;
	}
	int GetZi() {
		return this->data.zi;
	}
	int GetLuna() {
		return this->data.luna;
	}
	void SetPret(int n) {
		this->pret = n;
	}
	int GetPret() {
		return this->pret;
	}
	void SetVolum(string s) {
		this->volum = s;
	}
	string GetVolum() {
		return this->volum;
	}
	void SetEditura(string s) {
		this->editura = s;
	}
	string GetEditura() {
		return this->editura;
	}
	string GetLuna(int n) {
		string t;
		switch (n) {
		case 1: {
			t = "Ianuarie";
			break;
		}
		case 2: {
			t = "Februarie";
			break;
		}
		case 3: {
			t = "Martie";
			break;
		}
		case 4: {
			t = "Aprilie";
			break;
		}
		case 5: {
			t = "Mai";
			break;
		}
		case 6: {
			t = "Iunie";
			break;
		}
		case 7: {
			t = "Iulie";
			break;
		}
		case 8: {
			t = "August";
			break;
		}
		case 9: {
			t = "Septembrie";
			break;
		}
		case 10: {
			t = "Octombrie";
			break;
		}
		case 11: {
			t = "Noiembrie";
			break;
		}
		case 12: {
			t = "Decembrie";
			break;
		}
		default: {
			t =to_string(n);
			break;
		}
		}
		return t;
	}

	void descriere() {
		string t = "";
		t += "Titlu: " + GetTitlu() + "\n";
		t += "Autor: " + GetAutor() + "\n";
		t += "Data: " + to_string(GetZi()) + " , " + GetLuna(GetLuna()) + " " + to_string(GetAn()) + "\n";
		t += "Pret: " + to_string(GetPret()) + " lei \n\n";

		cout << t;
	}
	void descriere_detaliata() {
		string t = "";
		t += "Titlu: " + GetTitlu() + "\n";
		t += "Autor: " + GetAutor() + "\n";
		t += "Data: " + to_string(GetZi()) + " , " + GetLuna(GetLuna()) + " " + to_string(GetAn()) + "\n";
		t += "Pret: " + to_string(GetPret()) + " lei \n";
		t += "Editura: " + GetEditura();
		t += "\nVolum: " + GetVolum();
		t += "\n------ id: " + to_string(GetId()) + "------\n\n";
		cout << t;
	}
	void descriereadmin() {
		string t = "";
		t += "Titlu: " + GetTitlu() + "\n";
		t += "Autor: " + GetAutor() + "\n";
		t += "Data: " +to_string( GetZi()) + " , " + GetLuna(GetLuna()) + " " + to_string(GetAn()) + "\n";
		t += "Pret: " + to_string(GetPret()) + " lei \n";
		t += "------ id: " + to_string(GetId()) + "------\n\n";
		cout << t;
	}
	void AfisareCarte()
	{
		cout << GetTitlu() << " a fost scris in ";
		cout << GetZi()<<" ";
		cout << GetLuna(GetLuna())<< ",anul ";
		cout << GetAn()<< ",\nscrisa de "<<GetAutor()<<" ,a aparut in volumul : \"";
		cout << GetVolum()<<"\" ,iar editura este ";
		cout << GetEditura()<< "\nPretul e: ";
		cout << GetPret()<<" lei\n\n";
	}
};
