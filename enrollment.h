#pragma once
#include "functii.h"
#include "book.h"
#include "controller-books.h"
#include "controller_users.h"

struct Enrollment {
private:
	int id{}, idUser{};
	Book book[20];

public:

	Enrollment(){
		Citire();

	}
	
	void Citire() {

		

	}



};
