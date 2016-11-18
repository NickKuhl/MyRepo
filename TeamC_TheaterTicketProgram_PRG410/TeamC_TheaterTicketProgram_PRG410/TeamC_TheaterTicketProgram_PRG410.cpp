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
#include <iomanip>

using namespace std;

void displaySeatingChart(bool seating[10][9]);
void displayTicketPrices(double ticketPrices[10][9]);
void displaySeatingByRow(bool seating[10][9]);
void displaySeatingTotals(bool seating[10][9]);
void changeTicketPrices(double prices[10][9]);

int main()
{
	cout << "\nWelcome to the Theater Ticket Program, Version 1.0\n\n";
	cout << "Instructions:\n";
	cout << "Please enter one of the following menu options, then press Enter.\n";

	bool exitProgramFlag = false;

	bool seatsTaken[10][9]{};                  // Ten rows, nine columns, true = taken, false = available (default)
	double seatPrices[10][9]{};

	while (!exitProgramFlag) {

		cout << "\n1) Display current seating chart\n";
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
			case 3: ; break;
			case 4: changeTicketPrices(seatPrices); break;
			case 5:; break;
			case 6: displaySeatingTotals(seatsTaken); break;
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
	cout << "______________________________________________________________________\n";
	cout << "|     |  C1  |  C2  |  C3  |  C4  |  C5  |  C6  |  C7  |  C8  |  C9  |\n";
	cout << "|_____|______|______|______|______|______|______|______|______|______|\n";
	for (int i = 0; i <= 8; i++) {
		cout << "|  R" << i << " |";
		for (int j = 0; j <= 8; j++) {
			cout << setw(6) << ticketPrices[i][j] << "|";
		}
		cout << "\n|_____|______|______|______|______|______|______|______|______|______|\n";
		cout << "\n";
	}
	cout << "| R10 |";
	for (int j = 0; j <= 8; j++) {
		cout << setw(6) << ticketPrices[9][j] << "|";
	}
	cout << "\n|_____|______|______|______|______|______|______|______|______|______|\n";
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

void changeTicketPrices(double tickets[10][9]) {
	cout << "\nTicket prices are based on the value of the center-front seat (the base price).\n";
	cout << "What do you want to change the base price to?\n\n";
	cout << "(Current base price: " << tickets[1][5] << ")\n\n";
	double newBasePrice;
	cin >> newBasePrice;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			tickets[i][j] = newBasePrice - 0.03 * (i - 1) - 0.005 * -(j - 5);
		}
	}
	cout << "\n\nNew base ticket price is set to " << newBasePrice << "\n\n";
	cout << "View new price chart? [y/n]\n\n";
	char response;
	cin >> response;
	if (response == 'y') {
		displayTicketPrices(tickets);
	}
}

void displaySeatingTotals(bool seating[10][9]) {
	int seatsAvailable = 0;
	int seatsTaken = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (seating[i][j] == false) {
				seatsAvailable++;
			}
			else if (seating[i][j] == true) {
				seatsTaken++;
			}
		}
	}
	cout << "Total Seats Available: " << seatsAvailable << endl;
	cout << "Total Seats Taken: " << seatsTaken << endl << endl;
}
