#pragma once
#include "functii.h"
#include "controller-books.h"
#include"controller_users.h"
#include "controller_enrollment.h"


struct meniu {
private:
	ControllerBooks cnt_b;
	ControllerUser cnt_u;
	ControllerEnrollment cnt_e;
public:

	meniu() {
		//play();
	}

	void play() {
		cout << "----------------Bine ati venit la Libraria online----------------";
		
		bool temp1 = false, exit = false;
		char temp[250] = "";
		Sleep(800);
		loading_faster();
		while (!temp1 && !exit) {
			clearconsole();
			choices();
			play1(temp1); //true cand iese
			system("pause");
			//loading_faster();
			if (temp1) {
				clearconsole();
				text_Align("Ati dori sa iesiti din aplicatie?\n");
				char s[250] = "";
				cin.getline(s, 10);
				if (strcmp(s, "da") == 0 || strcmp(s, "DA") == 0 || strcmp(s, "yes") == 0 || strcmp(s, "yeah") == 0 || strcmp(s, "y") == 0)
					exit = true;
				else {
					exit = false;
					temp1 = false;
				}
			}
			

			
		}
		

	}
	void play1(bool& temp1) {

		bool temp = true;
		while (temp) {
			char char_temp[250] = "";
			int k;
			cin.getline(char_temp, 20);
			verficare_int(char_temp, k);

			switch (k)
			{
				   //Afisare
			case 1: {
				cnt_b.afisare_carti();
				temp = false;
				break;
			}
				  //Afisare detaliata
			case 2: {
				cnt_b.afisare_detaliata();
				temp = false;
				break;
			}
				  //Stergere
			case 3: {
				string titlu;
				if (login_admin()) {
					cnt_b.return_titluri();
					cout << "Introdu titlul cartii care doresti sa fie stearsa:";
					getline(cin, titlu);
					int n = cnt_b.cautareid_bytitlu(titlu);

					cnt_b.StergereCarte(n);
					cnt_b.save();
				}
				temp = false;
				break;
			}
				  //Schimbare 
			case 4: {
				string titlu;
				if (login_admin()) {
					cnt_b.return_titluri();
					cout << "Introdu titlul cartii caruia vrei sa i faci schimbari:\n";
					getline(cin, titlu);

					int n = cnt_b.cautareid_bytitlu(titlu);

					cnt_b.Schimbare_Date(n);
					cnt_b.save();
				}
				temp = false;
				break;
			}
				  //Adauga o carte noua 
			case 5: {
				if (login_admin()) {
					cnt_b.AdaugareCarte();
					cnt_b.save();
				}

				temp = false;
				break;
			}
				  //aff datele personale
			case 6: {
				string email;

				cout << "Introduceti emailul:";
				getline(cin, email);
				email = cnt_u.existing_email(email);

				if (login_user(email)) {
					int n = cnt_u.cautare_byemail(email);
					cnt_u.afisare_user(n);
					cout << cnt_e.return_carti(n) << endl;
				}
				temp = false;
				break;
			}
				  //buy book
			case 7: {
				bool ver = true;
				string email = "";
				login(ver, email);
				
				if (ver) {
					string titlu;
					User u = cnt_u.search_byemail(email);

					cnt_b.return_titluri();
					cout << "Soldul dumneavostra: " << u.GetBalance() << endl;

					cout << "\nTasteaza titlul cartii pe care doresti sa o cumperi:\n";

					getline(cin, titlu);

					Book b = cnt_b.return_bytitlu(titlu);

					int i = cnt_b.cautareid_bytitlu(titlu);
					int book_id = b.GetId(), user_id = u.GetId();

					if (b.GetPret() < u.GetBalance()) {
						cnt_e.AddBook(book_id, user_id);
						cnt_e.save();
						int new_balance = u.GetBalance() - b.GetPret();
						int user_id = cnt_u.cautare_byemail(u.GetEmail());
						user_id = cnt_u.cautare_byid(user_id);
						
						cnt_u.SetBalance_byid(user_id, new_balance);

						cnt_u.save();
						cout << "\nCarte adaugata!";
					}
					else
					{
						cout << "\nNu aveti credite suficiente.\n";
					}
					
				}



				temp = false;
				break;
			}
				 //Schimba datele personale
			case 8: {
				clearconsole();
				string email;
				cout << "\nIntroduceti-va email-ul:";

				getline(cin, email);
				email = cnt_u.existing_email(email);
				if (login_user(email)) {
					cnt_u.Schimbare_Date(email);
					cnt_u.save();
				}
				else
					cout << "Credentiale incorecte!";

				temp = false;
				break;
			}
				  //Delete user 
			case 9: {
				string email;
				if (login_admin()) {
					cnt_u.return_emailuri();
					cout << "Introdu email-ul pe care doresti sa l stergi: \n";
					getline(cin, email);
					email = cnt_u.existing_email(email);
					//i= id ul user-ului
					int i = cnt_u.cautare_byemail(email);
					cnt_u.afisare_user(i);
					cout << "\n Esti sigur ca vrei sa stergi acest user?\n";
					string raspuns;
					cin >> raspuns;
					if (raspuns == "da" || raspuns == "DA")
					{
						cnt_u.StergereUser(i);
						cout << "User ul a fost sters cu succes!";
					}
					else
					{
						cout << "\nStergere anulata.\n";
					}

				}

				temp = false;
				break;
			}
				  //New user
			case 10: {
				cnt_u.AdaugareUser();
				cnt_u.save();
				temp = false;
				break;
			}
				  //Review
			case 11: {
				ofstream g("reviews.txt");
				string review;
				cout << "Va rugam lasati un review: in casuta de mai jos:\n";
				cout << "----------------------------------------------\n";
				cout << "Review:"; 
				getline(cin, review);

				g << review;
				printf("----------------------------------------------------\n");
				printf("|                                                  |\n");
				printf("|                                                  |\n");
				printf("|          Va multumim pentru feedback!!           |\n");
				printf("|                                                  |\n");
				printf("|                                                  |\n");
				printf("----------------------------------------------------\n");
				g.close();
				temp = false;
				break;

			}
			case 0: {

				temp1 = true;
				temp = false;
				break;
			}
			default: {
				cout << "Introduceti o valoare care este inclusa in meniu";
				temp = true;
				break;
			}
			
			}
		}
	}


	void choices() {
		string t = "";
		t += "	Alegeti una dintre urmatoarele optiuni:				\n";
		cout << t;
		cout << "1. Afiseaza toate cartile.\n";
		cout << "2. Afiseaza cartile in detaliu.\n";
		cout << "3. Sterge o carte.\n";
		cout << "4. Schimba datele unei carti.\n";
		cout << "5. Adauga o carte noua.\n";
		cout << "6. Afiseaza datele personale.\n";
		cout << "7. Cumpara o carte. \n";
		cout << "8. Schimba datele personale.\n";
		cout << "9. Sterge un utilizator.\n";		
		cout << "10. Adauga un cont nou.\n";				
		cout << "11. Lasa un review.\n\n"; 

		cout << "0. Exit.\n";

	}

	bool login_admin() {
		string par = "goga", s;
		int n = 0;
		cout << "\nPentru astfel de operatiuni necesita parola de administrator:\n";
		
		while (n < 3) {
			getline(cin, s);
			n++;
			if (s == par)
				return true;
			else
				cout << "Parola gresita,mai aveti " << 3 - n<<" incercari\n";
			
		}
		cout << "Ne pare rau ,mai reincercati!\n";
		Sleep(300);
		return false;

	}
	
	void login(bool &temp,string& email) {
		
		cout << "Introduceti emailul:";

		getline(cin, email);
		email = cnt_u.existing_email(email);


		if (login_user(email))
			temp = true;
		else
			temp = false;
	}

	bool login_user(string email) {
		int n = 0;
		string s = cnt_u.returnpassword_byemail(email),parola;
		parola.erase();
		cout << "\nIntroduceti-va parola:";
		while (n < 3) {
			getline(cin,parola);
			n++;
			if (s == parola)
				return true;
			else {
				cout << "Parola gresita,mai aveti " << 3 - n << " incercari\nParola:";

			}

		}
		cout << "Ne pare rau,reincercati!";
		Sleep(700);
		return false;


	}

	
};
