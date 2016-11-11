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
void displayTicketPrices(double ticketPrices[10][9]);
void displaySeatingByRow(bool seating[10][9]);

int main()
{
	cout << "Welcome to the Theater Ticket Program, Version 1.0\n\n";
	cout << "Instructions:\n";
	cout << "Please enter one of the following menu options, then press Enter.\n\n";

	bool exitProgramFlag = false;

	bool seatsTaken[10][9];                  // Ten rows, nine columns, true = taken, false = available (default)
	double seatPrices[10][9]{};

	while (!exitProgramFlag) {

		cout << "1) Display current seating chart\n";
		cout << "2) Display current ticket prices\n";
		cout << "3) Purchase ticket/s\n";
		cout << "4) Set ticket prices\n";
		cout << "5) Display total ticket sales\n";
		cout << "6) Display total seats available/taken\n";
		cout << "7) Display seats available by row\n";
		cout << "8) Exit program\n\n";

		int menuSelection;
		cin >> menuSelection;

		switch (menuSelection) {
			case 1: displaySeatingChart(seatsTaken); break;
			case 2: displayTicketPrices(seatPrices); break;
			case 3:; break;
			case 4:; break;
			case 5:; break;
			case 6:; break;
			case 7: displaySeatingByRow(seatsTaken); break;
			case 8: exitProgramFlag = true; break;
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
				cout << " * | ";
			}
			else {
				cout << " # | ";
			}
		}
		cout << "\n";
		cout << "|_____|____|____|____|____|____|____|____|____|____|\n";
	}
	cout << "| R10 | ";
	for (int j = 0; j <= 8; j++) {
		if (seating[9][j] == true) {
			cout << " * | ";
		}
		else {
			cout << " # | ";
		}
	}
	cout << "\n";
	cout << "|_____|____|____|____|____|____|____|____|____|____|\n";
	cout << "\n";
	cout << "(Type 'c' + Enter to continue.)\n";
	string response;
	cin >> response;
}

void displayTicketPrices(double ticketPrices[10][9]) {
	cout << "\n\nCurrent Ticket Prices:\n\n";
	cout << "_______________________________________________________________________________\n";
	cout << "|     |   C1  |   C2  |   C3  |   C4  |   C5  |   C6  |   C7  |   C8  |   C9  |\n";
	cout << "|_____|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n";
	for (int i = 0; i <= 8; i++) {
		cout << "|  R" << i << " | ";
		for (int j = 0; j <= 8; j++) {
			cout << ticketPrices[i][j] << "|";
		}
		cout << "\n|_____|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n";
		cout << "\n";
	}
	cout << "| R10 |";
	for (int j = 0; j <= 8; j++) {
		cout << ticketPrices[9][j] << "|";
	}
	cout << "\n|_____|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n";
	cout << "\n";
	cout << "\n";
	cout << "(Type 'c' + Enter to continue.)\n";
	string response;
	cin >> response;
}

void displaySeatingByRow(bool seating[10][9]) {
	cout << "\n\nWhich row do you want to check the seating for?\n\n";
	int rowNumber = 0;
	cin >> rowNumber;
	int sumAvailableByRow = 0;
	for (int i = 0; i < 8; i++) {
		if (seating[rowNumber - 1][i] == false) {
			sumAvailableByRow++;
		}
	}
	cout << "\n\nThere are " << sumAvailableByRow << " seats available in row " << rowNumber << ":\n\n";
	cout << "____________________________________________________\n";
	cout << "|     | C1 | C2 | C3 | C4 | C5 | C6 | C7 | C8 | C9 |\n";
	cout << "|_____|____|____|____|____|____|____|____|____|____|\n";
	if (rowNumber < 10) {
		cout << "|  R" << rowNumber << " |";
		for (int i = 0; i <= 8; i++) {
			if (seating[rowNumber - 1][i] == true) {
				cout << "  * |";
			}
			else {
				cout << "  # |";
			}
		}
		cout << "\n";
		cout << "|_____|____|____|____|____|____|____|____|____|____|\n\n";
	}
	else {
		cout << "| R" << rowNumber << " |";
		for (int i = 0; i <= 8; i++) {
			if (seating[9][i] == true) {
				cout << "  * |";
			}
			else {
				cout << "  # |";
			}
		}
		cout << "\n";
		cout << "|_____|____|____|____|____|____|____|____|____|____|\n\n";
	}
	cout << "(Type 'c' + Enter to continue.)\n";
	string response;
	cin >> response;
}

