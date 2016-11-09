/*
Theater Ticket Program, Version 1.0
Created by Team C:
Nicholas Kuhl, Luke Nelson, Matthew Cain, & Matthew Schroeder
PRG/410
November 8, 2016
Professor Gholam Ali Shaykhian

This program allows the employees of a theater to process ticket sales, view available seating, and change ticket prices.
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	cout << "Welcome to the Theater Ticket Program, Version 1.0\n\n";
	cout << "Instructions:\n";
	cout << "Please enter one of the following menu options, then press Enter.\n\n";

	bool exitProgramFlag = false;

	while (!exitProgramFlag) {

		cout << "1) Display current seating chart\n";
		cout << "2) Purchase ticket/s\n";
		cout << "3) Set ticket prices\n";
		cout << "4) Display total ticket sales\n";
		cout << "5) Display total seats available/taken\n";
		cout << "6) Display seats available by row\n";
		cout << "7) Exit program\n\n";

		int menuSelection;
		cin >> menuSelection;

		switch (menuSelection) {
			case 1:; break;
			case 2:; break;
			case 3:; break;
			case 4:; break;
			case 5:; break;
			case 6:; break;
			case 7: exitProgramFlag = true; break;
			default: cout << "\n\nSorry, that wasn't a valid menu selection. Please choose 1-8, then press Enter.\n\n";
		}
	}

    return 0;
}

