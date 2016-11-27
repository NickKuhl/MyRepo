/*
Theater Ticket Program, Version 1.0
Created by Team C:
Nicholas Kuhl, Luke Nelson, Matthew Cain, & Matthew Schroeder
PRG/410
November 10, 2016
Professor Gholam Ali Shaykhian

This program allows the employees of a theater to process ticket sales, view available seating, and change ticket prices.
The program gives the user eight main menu options, three of which have sub-menus.
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void displaySeatingChart(bool seating[10][9]);                            // Shows table of which seats available/taken.
void displayTicketPrices(double ticketPrices[10][9]);                     // Shows current price of each individual seat.
void displaySeatingByRow(bool seating[10][9]);                            // Shows seats available/taken for a specific row.
void displaySeatingTotals(bool seating[10][9]);                           // Displays total seats available/taken.
void changeTicketPrices(double prices[10][9]);                            // Lets user set ticket prices, using a base price.
void displayTotalSales(bool seating[10][9], double ticketPrices[10][9]);  // Displays revenue for all tickets sold.
void purchaseTickets(bool seating[10][9], double ticketPrices[10][9]);    // Lets user purchase tickets for selected seats.

int main()
{
	cout << "\nWelcome to the Theater Ticket Program, Version 1.0\n\n";
	cout << "Instructions:\n";
	cout << "Please enter one of the following menu options, then press Enter.\n";

	bool exitProgramFlag = false;

	bool seatsTaken[10][9]{};                  // Ten rows, nine columns, true = taken, false = available (default)
	double seatPrices[10][9]{};

	// These for loops iterate through the seatPrices array to set each seat's initial value to $5.00.
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			seatPrices[i][j] = 5.0;
		}
	}

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
			case 3: purchaseTickets(seatsTaken, seatPrices); break;
			case 4: changeTicketPrices(seatPrices); break;
			case 5: displayTotalSales(seatsTaken,seatPrices); break;
			case 6: displaySeatingTotals(seatsTaken); break;
			case 7: displaySeatingByRow(seatsTaken); break;
			case 8: exitProgramFlag = true; break;
			default: cout << "\n\nSorry, that wasn't a valid menu selection. Please choose 1-8, then press Enter.\n\n";
		}
	}

    return 0;
}

// This function shows a table of which seats are currently available/taken.
void displaySeatingChart(bool seating[10][9]) {

	cout << "\n\nCurrent Seating:\n\n";
	cout << "____________________________________________________\n";
	cout << "|     | C1 | C2 | C3 | C4 | C5 | C6 | C7 | C8 | C9 |\n";
	cout << "|_____|____|____|____|____|____|____|____|____|____|\n";
	
	//  Outter loop prints row numbers, inner loop prints column values (# or *).
	for (int i = 0; i <= 8; i++) {

		cout << "|  R" << i + 1 << " | ";

		// If a seat is taken, a * is displayed in a column, otherwise a # is displayed.
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

	// This loop prints out the tenth row of the seating chart, so that it lines up with the other rows.
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

// This function shows the current price of each individual seat.
void displayTicketPrices(double ticketPrices[10][9]) {
	cout << "\n\nCurrent Ticket Prices:\n\n";
	cout << "______________________________________________________________________\n";
	cout << "|     |  C1  |  C2  |  C3  |  C4  |  C5  |  C6  |  C7  |  C8  |  C9  |\n";
	cout << "|_____|______|______|______|______|______|______|______|______|______|\n";
	
	// Outer loop prints row numbers for pricing chart.
	for (int i = 0; i <= 8; i++) {

		cout << "|  R" << i + 1 << " |";

		// Inner loop prints out a seat price in each column, formatted to the column width.
		for (int j = 0; j <= 8; j++) {
			cout << setw(6) << ticketPrices[i][j] << "|";
		}
		cout << "\n|_____|______|______|______|______|______|______|______|______|______|\n";
	}
	cout << "| R10 |";

	// This loop prints out the tenth row of the pricing chart, so that it lines up with the previous rows.
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

// This function shows how many seats are available/taken for a specific row.
void displaySeatingByRow(bool seating[10][9]) {
	cout << "\n\nWhich row do you want to check the seating for?\n\n";
	int rowNumber = 0;
	cin >> rowNumber;
	int sumAvailableByRow = 0;

	// This loop increments the number of seats available in a selected row, in order to calculate the total available.
	for (int i = 0; i < 9; i++) {
		if (seating[rowNumber - 1][i] == false) {
			sumAvailableByRow++;
		}
	}
	cout << "\n\nThere are " << sumAvailableByRow << " seats available in row " << rowNumber << ":\n\n";
	cout << "____________________________________________________\n";
	cout << "|     | C1 | C2 | C3 | C4 | C5 | C6 | C7 | C8 | C9 |\n";
	cout << "|_____|____|____|____|____|____|____|____|____|____|\n";
	
	// This loop displays whether seats are available in each of the columns of the selected row.
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

// This function lets the user set ticket prices, using a base price.
void changeTicketPrices(double tickets[10][9]) {
	cout << "\nTicket prices are based on the value of the center-front seat (the base price).\n";
	cout << "What do you want to change the base price to?\n\n";
	cout << "(Current base price: " << tickets[1][5] << ")\n\n";
	double newBasePrice;
	cin >> newBasePrice;

	// These loops calculate the price for each seat in the theater, using the new base price provided by the user.
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

// This function displays total seats available/taken.
void displaySeatingTotals(bool seating[10][9]) {
	int seatsAvailable = 0;
	int seatsTaken = 0;

	// These loops add up the total number of available seats and taken seats in the theater.
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

// This function displays revenue for all tickets sold.
void displayTotalSales(bool seating[10][9], double ticketPrices[10][9]) {

	double totalSales = 0;

	// These loops check which seats have been sold, then add up the prices for those seats to get a sales total.
	for (int n = 0; n < 10; n++) {
		for (int j = 0; j < 9; j++) {
			if (seating[n][j] == true)
				totalSales = totalSales + ticketPrices[n][j];
		}
	}
	cout << "\nThe total sales so far are: $" << totalSales << endl << endl;
}

// This function lets user purchase tickets for selected seats.
void purchaseTickets(bool seating[10][9], double ticketPrices[10][9]) {

	bool processOrderFlag = true;                   // Flag or deciding whether to continue adding tickets to current order.
	char yesOrNo = 'y';                             // Holds user input used to set exit flag value.
	double orderTotal = 0.0;                        // Total cost of all tickets added to current order.
	int ticketRow = 0;                              // Holds row number selected by user for choosing a seat.
	int ticketColumn = 0;                           // Holds column number selected by user for choosing a seat.
	cout << "\n\nNew order.\n\n";

	// Loop keeps repeating until user decides not to purchase any more tickets, and finishes order.
	while (processOrderFlag) {

		// Function is called to display current seating available, so that user can choose which seat to buy ticket for.
		displaySeatingChart(seating);
		cout << "\n\nCurrent Order Total: " << orderTotal << endl << endl;
		cout << "Enter row number of ticket to purchase [1-10]:\n\n";
		cin >> ticketRow;
		cout << "\nEnter column number of ticket to purchase [1-9]:\n\n";
		cin >> ticketColumn;

		// Condition checks if requested seat is available. It is is, the seat is changed to unavailable. Ticket price
		// is also added to the current order total.
		if (seating[ticketRow - 1][ticketColumn - 1] == false) {
			seating[ticketRow - 1][ticketColumn - 1] = true;
			orderTotal += ticketPrices[ticketRow - 1][ticketColumn - 1];
			cout << "\n\nTicket for row " << ticketRow << ", column " << ticketColumn << " added to order.\n\n";
			cout << "Would you like to purchase another ticket? [y/n]\n\n";
			cin >> yesOrNo;

			// Condition checks if the user wants to buy any more tickets. If not, the final total cost is displayed.
			if (yesOrNo == 'n') {
				processOrderFlag = false;
				cout << "\n\nThe total for your order will be $" << orderTotal << ".\n\n";
				cout << "Press 'c' + Enter to continue.\n\n";
				cin >> yesOrNo;
			}
		}
	}
}