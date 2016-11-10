/*
Theater Ticket Program, Version 1.0
Created by Team C:
Nicholas Kuhl, Luke Nelson, Matthew Cain, & Matthew Schroeder
PRG/410
November 10, 2016
Professor Gholam Ali Shaykhian

This program allows the employees of a theater to process ticket sales, view available seating, and change ticket prices.
The program gives the user seven main menu options, three of which have sub-menus.
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void displaySeatingChart(bool seating[10][9]);

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
		bool seatsAvailable[10][9];                        // Ten rows, nine columns, true = taken (default), false = available
		double seatPrices[10][9];

		switch (menuSelection) {
			case 1: displaySeatingChart(seatsAvailable); break;
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

void displaySeatingChart(bool seating[10][9]) {
	cout << "\n\nCurrent Seating:\n\n";
	cout << "____________________________________________________\n";
	cout << "|     | C1 | C2 | C3 | C4 | C5 | C6 | C7 | C8 | C9 |\n";
	cout << "|_____|____|____|____|____|____|____|____|____|____|\n";
	for (int i = 0; i <= 8; i++) {
		cout << "|  R" << i + 1 << " | ";
		for (int j = 0; j <= 8; j++) {
			if (seating[i][j] == true) {
				cout << " O | ";
			}
			else {
				cout << " X | ";
			}
		}
		cout << "\n";
		cout << "|_____|____|____|____|____|____|____|____|____|____|\n";
	}
	cout << "| R10 | ";
	for (int j = 0; j <= 8; j++) {
		if (seating[9][j] == true) {
			cout << " O | ";
		}
		else {
			cout << " X | ";
		}
	}
	cout << "\n";
	cout << "|_____|____|____|____|____|____|____|____|____|____|\n";
	cout << "\n";
	cout << "(Type 'c' + Enter to continue.)\n";
	string response;
	cin >> response;
}

