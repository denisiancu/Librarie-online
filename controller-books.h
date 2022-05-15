#pragma once
#include "book.h"

struct ControllerBooks {
private:
	Book book[50];
	int nr_carti=0;
public:
	
	
	ControllerBooks() {
		citire();

		
	}

	void citire() {
		ifstream f("books_data.txt");
		char k[20] = "";
		int id{}, pret{};
		Data data;
		string titlu, autor, volum, editura;
		bool temp = true;

		srand(time(0));
		id = rand() % 100;
		while (temp) {
			f >> k;
			if (strcmp(k, "end") == 0)
				temp = false;
			else
			{
				while (!verficare_id(id))
					id = rand()%100;
				k[0] = '\0';
				f >> titlu >> autor >> volum >> editura >> data.zi >> data.luna >> data.an>>pret;
				titlu=toSpace(titlu);
				autor=toSpace(autor);
				editura = toSpace(editura);
				volum =toSpace(volum);
				Book book(id,titlu, pret, data, volum, editura, autor);
				implementare_carte(book);
			}

		}
	
	}
	void implementare_carte(Book b) {
		book[nr_carti++] = b;
	}
	//needs id
	void StergereCarte(int id) {
		bool temp = true;
		for (int i = 0; i < nr_carti && temp; i++)
		{
			if (book[i].GetId() == id)
			{
				for (i; i < nr_carti; i++)
					book[i] = book[i + 1];
				nr_carti--;
				temp = false;
			}
		}

	}
	void AdaugareCarte() {
		int pret{}, id{};
		Data data;
		string titlu, autor, volum, editura;
		char char_temp[250] = "";
		refresh_half(0);
		text_Align(25);
		cout << "Bine ati venit la meniul de adaugare a unei carti!";
		id = rand();
		while(!verficare_id(id))
		{
			id = rand();
		}
		cout << "\nIntroduceti titlul cartii :";

		getline(cin, titlu);

		cout << "\nIntroduceti autorul:";

		getline(cin, autor);
		
		cout << "\nIntroduceti volumul:";

		getline(cin, volum);
		
		cout << "\nIntroduceti editura:";

		getline(cin, editura);
		
		cout << "\nIntroduceti pretul:";
		cin >> char_temp;
		verficare_int(char_temp, pret);
		cout << "\nIntroduceti ziua in care a fost publicata cartea:";
		cin >> char_temp;
		verficare_int(char_temp, data.zi);
		cout << "\nIntroduceti luna:";
		cin >> char_temp;
		verficare_int(char_temp, data.luna);
		cout << "\nIntroduceti anul:";
		cin >> char_temp;
		verficare_int(char_temp, data.an);
		system("CLS");
		text_Align(9);
		cout << "Cartea a fost adaugata cu succes!!";
		Book book(id, titlu, pret, data, volum, editura, autor);
		Sleep(1000);
		implementare_carte(book);
		Sleep(1000);
		system("cls");
	}
	
	//needs id
	void Schimbare_Date(int id) {
		int nr = cautare_by_id(id);
		text_Align(25);
		cout << "Introduceti tasta corespunzatoare actiunii!:\n";
		Sleep(1000);
		int k;
		char char_temp[250] = "", s[250]="";
		bool temp = true;
		while (temp) {
			alegeri();
			cin >> char_temp;
			verficare_int(char_temp, k);
			switch (k)
			{
				
			case 1: {
				cout << "Tastati noul titlu :\n";
				string titlu;

				getline(cin, titlu);
				getline(cin, titlu);


				book[nr].SetTitlu(titlu);
				clearconsole();
				temp = false;
				break;
			}
			case 2: {
				cout << "Tastati autorul:\n";
				string autor; 
				getline(cin, autor);
				getline(cin, autor);

				book[nr].SetAutor(autor);
				clearconsole();
				temp = false;
				break;
			}
			case 3: {
				cout << "Tastati volumul:\n";
				string volum;
				getline(cin, volum);
				getline(cin, volum);

				book[nr].SetVolum(volum);

				clearconsole();
				temp = false;
				break;
			}
			case 4: {
				cout << "Tastati editura:\n";
				string editura;
				getline(cin, editura);
				getline(cin, editura);
				book[nr].SetEditura(editura);

				clearconsole();
				temp = false;
				break;
			}
			case 5: {
				change_date(id);

				clearconsole();
				temp = false;
				break;
			}
			case 6: {
				int n;
				cout << "Introduceti pretul:";
				cin >> n;
				book[nr].SetPret(n);
				clearconsole();
				temp = false;
				break;
			}

			default: {
				cout << "\n\n";
				text_Align("Alegeti o tasta care se afla in range ul nostru!!");
				Sleep(500);
				clearconsole();
				temp = true;
				break;
			}
			}


		}
		cout << "Datele au fost schimbate cu succes!";
		Sleep(1400);
		clearconsole();

	}
	//needs id
	void Schimbare_id(int id) {
		cout << "Introdu noul id:";
		char char_temp[250] = "";
		int k;
		cin >> char_temp;
		verficare_int(char_temp, k);
		int n = cautare_by_id(id);
		book[n].SetId(k);

	}

	//Schimba data:
	void change_date(int id) {
		int nr = cautare_by_id(id);
		Data data;
		char char_temp[250] = "";
		cout << "Introduceti ziua:";
		cin >> char_temp;
		verficare_int(char_temp, data.zi);
		cout << "\nIntroduceti luna:";
		cin >> char_temp;
		verficare_int(char_temp, data.luna);
		cout << "\nIntroduceti anul:";
		cin >> char_temp;
		verficare_int(char_temp, data.an);
		book[nr].SetData(data);

		}
    //Verifica daca e numar
	void verficare_int(char* aux, int& id) {
		int k = 0;
		char temp[40] = "";
		for (int i = 0; i < strlen(aux); i++)
		{
			if (aux[i] < '0' || aux[i]>'9')
				k++;
		}

		if (k != 0) {
			cout << "\nIntrodu un numar:";
			temp[0] = '\0';
			while (k != 0) {
				k = 0;
				cin >> temp;
				for (int i = 0; i < strlen(temp); i++)
				{
					if (temp[i] < '0' || temp[i]>'9')
						k++;
				}
				if (k == 0)
					id = atoi(temp);
				temp[0] = '\0';

			}
		}
		else
		{
			id = atoi(aux);
		}
		aux[0] = '\0';

	}
	bool verficare_id(int id) {
		for (int i = 0; i < nr_carti; i++)
		{
			if (id == book[i].GetId())
				return false;
		}
		return true;
	}
	void alegeri() {
		string t = "";
		t += "1. Schimba titlul cartii.\n";
		t += "2. Schimba autorul cartii.\n";
		t += "3. Schimba volumul.\n";
		t += "4. Schimba editura.\n";
		t += "5. Schimba data.\n";
		t += "6. Schimba pretul.\n";
		cout << t;


	}
	int cautare_by_id(int id) {
		for (int i = 0; i < nr_carti; i++)
			if (id == book[i].GetId())
				return i;
		return 0;
	}
	void save() {
		ofstream f("books_data.txt");
		int i;
		for (i = 0; i < nr_carti; i++)
		{
			f<< book[i].GetId() << ' ' << toUnderline(book[i].GetTitlu())<<' ';
			f << toUnderline(book[i].GetAutor()) << ' ' << toUnderline(book[i].GetVolum()) << ' ';
			f << toUnderline(book[i].GetEditura()) << ' ' << book[i].GetZi() << ' ' << book[i].GetLuna() << ' ';
			f << book[i].GetAn() << ' ' << book[i].GetPret() << endl;
		}

		f << "end";
		f.close();

	}
	int GetNrCarti() {
		return this->nr_carti;
	}


		
	


	//Afiseaza cartile pe succint:
	void afisare_carti() {
		for (int i = 0; i < nr_carti; i++) {
			book[i].descriere();
		}
	}
	//Afiseaza carti mai detaliat
	void afisare_admin() {
		for (int i = 0; i < nr_carti; i++) {
			book[i].descriere_detaliata();
		}
	}
	void afisare_carte(int id) {

		for (int i = 0; i < nr_carti; i++)
			if (id == book[i].GetId()) {
				book[i].AfisareCarte();
			}

	}
	
	Book return_byid(int id) {
		int n=cautare_by_id(id);

		return book[n];

	}
	
	
};