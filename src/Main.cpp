
#include <cstdlib>
#include <windows.h>		     // include statements for libraries to be used in this program
#include <conio.h>
#include <stdlib.h>
#include <string>
using namespace std;


#include "AirGeadBankingProject.h"        // statement to include header and airGeadBankingApp2 library.



int main() {



	double initInvestAmt;
	double userMonDeposit;
	double annInterest;            // variables to be used in main program.
	int numYears;
	double totalDeposAmt;
	double interestAcru;

	BankingApp CustomerOne;         // Customer to be created as object for Banking app class.


	cout << endl;							// output statement to create space
	cout << endl;

	CustomerOne.DisplayMenuPrint();         // first fuction call to Display the menu

	cout << endl;
	cout << endl;		                   // output statement to create space for better readability



		/*Statements to be able to recive user inputs and then assigned it to variables.
	Then using a try catch block to throw an error if the user inputs a negative number.
	Next I use a do while loop over each input to keep asking the user to input the
	correct input.*/

	do {
		try {
			cout << "Enter investment amount: " << endl;  // out put asking for investment amount
			cin >> initInvestAmt;
			CustomerOne.SetInvestAmount(initInvestAmt);   // statement to set initInvestAmt to Customer One.
			if (initInvestAmt < 0) {
				throw runtime_error("Must be positive number"); //If/throw statement to check for negative input and output message to user.
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;					// The catch statement to catch error and out put to the user.
			cout << "Cannot compute values." << endl;
		}
	} while (initInvestAmt < 0.00);

	do {
		try {
			cout << "Enter monthly deposit amount: " << endl;  // Output statement asking for monthly deposit amount.
			cin >> userMonDeposit;
			CustomerOne.SetMonthlyDeposit(userMonDeposit);  // statement to set userMonDeposit to Customer One.
			if (userMonDeposit < 0) {
				throw runtime_error("Must be positive number");    // if/throw for userMonDeposit input
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;					// catch statement for this input
			cout << "Cannot compute values." << endl;
		}
	} while (userMonDeposit < 0.00);

	do {
		try {
			cout << "Enter interest rate: " << endl;   // Output to ask to enter interest rate.
			cin >> annInterest;
			CustomerOne.SetAnnualInterest(annInterest);  // statement to set annInterest to CustomerOne.
			if (annInterest < 0) {
				throw runtime_error("Must be positive number");			// if/throw for annInterest input
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;							// catch statement for this input
			cout << "Cannot compute values." << endl;
		}
	} while (annInterest < 0.00);

	do {
		try {
			cout << "Enter number of years: " << endl;			//Output asking user to Enter Investment amount and assign to numYears.
			cin >> numYears;
			CustomerOne.SetNumberYears(numYears);               // statement to set numYears to Customer one.
			if (numYears < 0) {
				throw runtime_error("Must be positive number");		// if/throw for numYears input
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << "Cannot compute values." << endl;			// catch statement for this input
		}
	} while (numYears < 0.0);


	cout << endl;
	cout << endl;

	CustomerOne.DisplayInputMenuPrint();  // A call to BankingApp to display the Menu with customer inputs.


	cout << endl;
	cout << endl;


	CustomerOne.CompInterestPrint();  // A call to display the first list with all the values without monthly deposit..

	cout << endl;
	cout << endl;

	CustomerOne.YearlyAmountPrint(numYears, initInvestAmt, userMonDeposit, annInterest);  // a call to display the second list with montly deposit.



}
