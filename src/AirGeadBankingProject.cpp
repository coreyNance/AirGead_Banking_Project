//============================================================================
// Name        : AirGeadBankingProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>                  // include statements for libraries to be used in this program
#include <conio.h>
#include <stdlib.h>

#include "AirGeadBankingProject.h"         // statement to include header and airGeadBankingApp2 library.
using namespace std;



double userMonDeposit;
double annInterest;				// variables to be used in the fuctions of this program.
int numYears;

void BankingApp::SetInvestAmount(double initInvestAmt) {

	this->initInvestAmt = initInvestAmt;
}

void BankingApp::SetMonthlyDeposit(double userMonDeposit) {
	                                                              // mutators to set the values for customer one.
	this->userMonDeposit = userMonDeposit;
}

void BankingApp::SetAnnualInterest(double annInterest) {

	this->annInterest = annInterest;
}

void BankingApp::SetNumberYears(int numYears) {

	this->numYears = numYears;
}






double BankingApp::GetInvestAmount() {

	return initInvestAmt;
}

double BankingApp::GetMonthlyDeposit() {

	return userMonDeposit;
}
                                                              // Accessors to get the values for customer one.
double BankingApp::GetAnnInterest() {

	return annInterest;
}

int BankingApp::GetNumberYears() {

	return numYears;
}




void BankingApp::DisplayMenuPrint() {

	cout << "**********************************" << endl;
	cout << "********** Data Input ************" << endl;
	cout << "Initial Investment Amount: " << endl;				//Output statements  to form the first display empty menu
	cout << "Monthly Deposit:  " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
	system("pause");										// To pause the system and wait for user to press a key before continuing

	return;

}



/*The DisplayMenu function definition.  This function takes the userinputs as arguments
and then enter them into a series of output statements to form the Display menu with
displaying the inputs.*/

void BankingApp::DisplayInputMenuPrint() {


	cout << "**********************************" << endl;
	cout << "********** Data Input ************" << endl;
	std::cout << std::fixed << std::setprecision(2);
	cout << "Initial Investment Amount: $" << initInvestAmt << endl;
	cout << "Monthly Deposit:    $" << userMonDeposit << endl;
	cout << "Annual Interest:    %" << annInterest << endl;
	cout << "Number of years:   " << numYears << endl;
	system("pause");										// To pause the system and wait for user to press a key before continuing
	return;

}

/* The CompInterest function to take the user inputs as arguments then use those arguments to input
into a for loop and then output the caluclations in the disired format.*/

void BankingApp::CompInterestPrint() {

	double compInterest = 0;   // variables to be used in this function.
	double yearInterest = 0;
	int i;

	cout << "			     Balanceand Interest Without Additional Monthly Deposits" << endl;
	cout << "======================================================================================================================" << endl;
	cout << "         Year                                    Year End Balance                           Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	/*A for loop to repeat calculations and print format for how many
	years the user inputs*/

	for (i = 0; i < numYears; ++i) {
		compInterest = (initInvestAmt) * ((annInterest / 100));
		yearInterest = compInterest + initInvestAmt;
		std::cout << std::fixed << std::setprecision(2) << setw(11) << right;
		cout << (i + 1);
		cout << setw(45) << right << "$";			// output statements to set the format of the output to align under the header.
		cout << setw(4) << left << yearInterest;
		cout << setw(39) << right << "$";
		cout << setw(4) << right << compInterest << endl;
		cout << endl;
		initInvestAmt = yearInterest;
	}

	return;

}


/*The MonthlyInterest function. This function takes the userinputs as aruguemtns to
calculate the yearly interest divided by months but also accounting for the monthly
deposits then adding it all together to create the total deposit amount. */

double BankingApp::MonthlyInterest(double initInvestAmt, double userMonDeposit, double annInterest) {

	double compInterest;
	double totalDeposAmt;   //variables to be used in this function.
	double acctBalance;
	int i;



	acctBalance = initInvestAmt + userMonDeposit;				// assign acctBalance with adding user investment plus deposit
	compInterest = acctBalance * ((annInterest / 100) / 12);	// assign acctBalance with adding user investment plus deposit
	totalDeposAmt = (compInterest + acctBalance);				// assign totalDepoAmt with the addition of compInterest and acctBalance


	/*A for loop to repeat this step 12 times adding user deposit to
	starting balance. Then calculate the interest on that balance and then save that
	new balace into totalDeposAmt. Then add totalDeposAmt to user deposit again and then
	calculate the interest based on that new deposit until the 12th month and then save it to
	totaldeposAmt.*/
	for (i = 1; i < 12; ++i) {
		compInterest = (totalDeposAmt + userMonDeposit) * ((annInterest / 100) / 12);
		totalDeposAmt = (totalDeposAmt + userMonDeposit) + compInterest;

	}

	return totalDeposAmt;  // final amount is saved under totalDeposAmt to be called.


}

/*The YearlyIntAccured function.  This a function to take user inputs as arguments and then use
then to calculate the total interest accrued over a year period without adding it to the
total balance but taking into account the monthly deposit amount. */

double BankingApp::YearlyIntAccrued(double initInvestAmt, double userMonDeposit, double annInterest) {

	double compInterest;
	double totalDeposAmt;
	double acctBalance;   // variables to be used in this function
	double interestAcru;
	int i;


	acctBalance = initInvestAmt + userMonDeposit;				// assign acctBalance with adding user investment plus deposit
	compInterest = acctBalance * ((annInterest / 100) / 12);	// assign acctBalance with adding user investment plus deposit
	totalDeposAmt = (compInterest + acctBalance);				// assign totalDepoAmt with the addition of compInterest and acctBalance
	interestAcru = compInterest;								// assign interestAcru to start with compInterest value.


	/*A for loop to calculate the the interest accrued over 12 months
	by first calculating the compound interest then assinging it to compInterest
	then calculating the total deposit plus the depsoit amount and adding it to compInterest
	and then adding compound interest amount to the interest accrued value and saving that to interestAcru*/
	for (i = 1; i < 12; ++i) {
		compInterest = (totalDeposAmt + userMonDeposit) * ((annInterest / 100) / 12);
		totalDeposAmt = (totalDeposAmt + userMonDeposit) + compInterest;
		interestAcru = compInterest + interestAcru;
	}

	return interestAcru; // final calculation varible to be returned when called.

}


/*This YearlyAmount function is used to mainly output output the values to the screen under the second header.
This function takes the user inputs as arguments then first starts a for loop to loop the number of times in numYears.
In each loop it takes the arguments and use them as arguments to call newDeposAmt and newInterestAcru. Then with those
calls, inputs the calculations from each into output statments formatted to the desired output to align under
the header.*/

void BankingApp::YearlyAmountPrint(int numYears, double initInvestAmt, double userMonDeposit, double annInterest) {

	double newDeposAmt = 0;
	double newInterestAcru = 0;  // variables to be used in this function.
	int i;


	cout << "			     Balanceand Interest Without Additional Monthly Deposits" << endl;
	cout << "======================================================================================================================" << endl;
	cout << "         Year                                    Year End Balance                           Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

	/*A for loop to repeat the calls and output statments for as
	many times that is stored in numYears*/
	for (i = 0; i < numYears; ++i) {

		newDeposAmt = MonthlyInterest(initInvestAmt, userMonDeposit, annInterest);   // newDepoAmt and newInterestAcru call
		newInterestAcru = YearlyIntAccrued(initInvestAmt, userMonDeposit, annInterest);
		std::cout << std::fixed << std::setprecision(2) << setw(11) << right;
		cout << (i + 1);
		cout << setw(45) << right << "$";
		cout << setw(4) << left << newDeposAmt;				// output statements to achieve desired output.
		cout << setw(40) << right << "$";
		cout << setw(2) << right << newInterestAcru << endl;
		cout << endl;
		initInvestAmt = newDeposAmt;
	}

	return;
}
