#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;
/*string s = "geeksforgeeks";
 
    int n = s.length();

    char char_array[n + 1];

    strcpy(char_array, s.c_str());
 
    for (int i = 0; i < n; i++)
        cout << char_array[i];
void test1() {
	char buffer[20];
	string str("Test string...");
	size_t length = str.copy(buffer, 6, 5);
	buffer[length] = '\0';
	cout << "buffer contains: " << buffer << '\n';

}*/
string toUnderline(string s) {
	int n = s.length();

	char c[250] = "";

	strcpy(c, s.c_str());


	s.erase();
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == ' ')
			c[i] = '_';

	}
	s += c;
	return s;
}
string toSpace(string s) {
	int n = s.length();

	char c[250] = "";

	strcpy(c, s.c_str());


	s.erase();
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == '_')
			c[i] = ' ';

	}
	s += c;
	return s;
}
string toString(char s[250]) {
	string t="";
	
	t += s;

	return t;

}
string toChar(string t) {
	char s[250] = "";

	strcpy(s, t.c_str());
	return s;

}

void refresh(int k) {

	for (int i = 0; i < 49 - k; i++)
		cout << "\n";
}
void refresh_half(int k) {
	for (int i = 0; i < 49 / 2 - k; i++)
		cout << "\n";
}
void text_Align(int k) {
	for (int i = 0; i < 72 / 2 - k; i++)
		cout << ' ';
}
void text_Align(char s[]) {
	for (int i = 0; i < 72 / 2 - strlen(s); i++)
		cout << ' ';
	cout << s << endl;
}
void text_Align(string s) {
	for (int i = 0; i < 72 / 2 - s.length(); i++)
		cout << ' ';
	cout << s << endl;

}
void clearconsole() {
	system("CLS");
}
void loading() {
	system("CLS");
	refresh_half(0);
	text_Align(7);
	cout << "Loading";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(2000);
	system("CLS");
	refresh_half(0);
	text_Align(7);
	cout << "Loading";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(2000);
	system("CLS");
}


void test2() {

	string s = "Ultima_noapte_de_dragoste,intaia_noapte_de_razboi";
			//		  Ultima noapte de dragoste,intaia noapte de razboi

	s=toSpace(s);
	cout << s << endl;
	
	s=toUnderline(s);
	
	cout << s << endl;


}


