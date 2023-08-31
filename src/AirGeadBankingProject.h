/*
 * Main.h
 *
 *  Created on: Aug 10, 2020
 *      Author: anyth
 */

#ifndef AIRGEADBANKINGPROJECT_H_
#define AIRGEADBANKINGPROJECT_H_

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>		// include statements for libraries to be used in this program
#include <conio.h>
#include <stdlib.h>
#include <string>
using namespace std;



class BankingApp {
public:

	void SetInvestAmount(double initInvestAmt);
	void SetMonthlyDeposit(double userMonDeposit);  // declarations for setter functions
	void SetAnnualInterest(double annInterest);
	void SetNumberYears(int numYears);

	double GetInvestAmount();
	double GetMonthlyDeposit(); // declarations for getter functions
	double GetAnnInterest();
	int GetNumberYears();


	void DisplayMenuPrint();
	void DisplayInputMenuPrint();  //  declarations for print menu and the first list display
	void CompInterestPrint();

	// declaration of functions to be used by yearlyAmountPrint.
	double MonthlyInterest(double initInvestAmt, double userMonDeposit, double annInterest);
	double YearlyIntAccrued(double initInvestAmt, double userMonDeposit, double annInterest);

	// final function to display the second menu.
	void YearlyAmountPrint(int numYears, double initInvestAmt, double UserMonDeposit, double annInterest);

private:

	double initInvestAmt;
	double userMonDeposit;
	double annInterest;  // private variables to be used by class functions.
	int numYears;




};




#endif
