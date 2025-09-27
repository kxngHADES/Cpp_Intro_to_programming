//Libraries
#include <iostream>
#include <string> //String manipulation like getline
#include <iomanip> //Lets me set my decimal point amounts for cents

//Namespaces
using namespace std;

//Global Variables
	//NONE USED


//Function decleration
void createAccount(string& name, int& accountNumber, double& balance);
double depositMoney(double balance);
double withdrawMoney(double balance);
void checkBalance(const double& balance);
void displayAccountDetails(const string name, const int accountNumber, const double balance);

//Main function
int main() {
	double balance = 0;
	int choice = 0;
	string name;
	int accountNumber = 0;

	do {

		cout << "\n\n--- Bank Account Management System ---\n";
		cout << "1. Create Account\n";
		cout << "2. Deposit Money\n";
		cout << "3. Withdraw Money\n";
		cout << "4. Check Balance\n";
		cout << "5. Display Account Details\n";
		cout << "6. Exit\n";
		cout << "Enter your choice (1-6): ";
		cin >> choice;

		//Buffer clearing in case user selects something like "Pizza" and creates an infinite loop
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


		switch (choice) {
		case 1:
			createAccount(name, accountNumber, balance);
			break;
		case 2:
			balance += depositMoney(balance);
			checkBalance(balance); //Display how much is in the account after deposit
			break;
		case 3:
			balance -= withdrawMoney(balance);
			checkBalance(balance); //Display how much is left after withdrawl
			break;
		case 4:
			checkBalance(balance);
			break;
		case 5:
			displayAccountDetails(name, accountNumber, balance);
			break;
		case 6:
			cout << "\n\nExiting the system. Goodbye!\n\n";
			break;
		default:
			cout << "INVALID option!\n";
			break;
		}

	} while (choice != 6);
}


//User Functions
void createAccount(string& name, int& accountNumber, double& balance) {
	cout << "\nEnter your name: ";
	getline(cin, name); //To take the space in the name too

	cout << "\nEnter your account number: ";
	cin >> accountNumber;

	do {
		cout << "\nEnter the initial deposit (must be greater than 0): ";
		cin >> balance;
		if (balance <= 0) {
			cout << "Initial deposit must be greater than 0.\n";
		}
	} while (balance <= 0);
}


double depositMoney(double balance) {
	double rAmount = 0;
	cout << "\nEnter deposit amount: ";
	cin >> rAmount;

	if (rAmount > 0) {
		return rAmount;
	}
	else {
		cout << "\nThat is not a valid amount\n";
		return 0;
	}
}

double withdrawMoney(double balance) {
	double rAmount;
	char choice;

	cout << "How much would you like to withdraw: ";
	cin >> rAmount;

	if (rAmount > balance) {//if rAmount is greater than the balance do not withdraw
		cout << "\nINVALID transaction!!! you do not have enough money\n";
		return 0;
	}
	else if (rAmount < 0) { //if trying to withdraw a negative number bascally illegal increase in amount
		cout << "\nCannot withdraw a negative amount\n";
		return 0;
	}
	else {//else withdraw the money
		cout << "\nSucceful withdrawl!\n\n";
		return rAmount;
	}
}


void checkBalance(const double& balance) {
	cout << fixed << setprecision(2);
	cout << "Your current balance is: R" << balance << "c. \n";
}




void displayAccountDetails(const string name, const int accountNumber, const double balance) {
	cout << "\n-----Account Details----\n";
	cout << "Account Holder: " << name << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Current Balance: " << balance << endl << endl;
}