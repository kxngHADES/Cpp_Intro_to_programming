//Inlcude section
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

//Namespaces
using namespace std;


//Declare functions
bool isValidName(string name) {//Ensure that the user enters a name and not numbers
	for (int i = 0; i < name.length(); i++) {
		char ch = name[i];
		if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch < 0))) {
			return false;
		}
	}
	return true;
}


bool isValidNumber(int iItemCount) { //Ensures user selection is withing range
	if (iItemCount > 8 || iItemCount < 1) {
		return false;
	}
	else {
		return true;
	}
}

//============================================================================================================

//Main function
int main() {

	//Variables
		//Strings
	string sName, sSurname;

		//Bool
	bool isName = false;
	bool isSurname = false;
	bool inRange = false;

		//Int
	int iItemCount;
	int SelectedItem;
	
		//Floats
	float fTotal = 0.0f;
	float fDiscount, fDiscountedAmount;

	// ======================================================================================================


	//Provided Constants
	//Constants
	const double DISCOUNT_RATE = 0.10; // 10% discount
	const double DISCOUNT_THRESHOLD = 100.00; // Discount applies if bill is over R100

	//Menu Prices Constants
	const double COFFEE_PRICE = 15.00;
	const double SANDWICH_PRICE = 30.00;
	const double SALAD_PRICE = 25.00;
	const double JUICE_PRICE = 10.00;
	const double MUFFIN_PRICE = 20.00;
	const double PIZZA_PRICE = 35.00;
	const double SOUP_PRICE = 18.00;
	const double BURGER_PRICE = 40.00;



	// ===============================================================================================================

	//Open the text file
	ofstream outputFile;
	outputFile.open("CafeteriaBill.txt", ios::app); //Opens in Append mode so it adds to the textfile instead of removing everything

	//Personal Information
	//Validate its a name
	do {
		cout << "Enter your name:";
		cin >> sName;
		if (isValidName(sName)) {
			isName = true;
		}
		else {
			cout << "Invalid Name. Please enter letters only, no numbers or symbols.\n";
		}

	} while (!isName);

	//Validate its a surname
	do {
		cout << "Enter your surname: ";
		cin >> sSurname;
		if (isValidName(sSurname)) {
			isSurname = true;
		}
		else {
			cout << "Invalid Name. Please enter letters only, no numbers or symbols.\n";
		}

	} while (!isSurname);


	//Items
	do {
		cout << "How many items would you like to order (up to 8)? ";
		cin >> iItemCount;
		if (iItemCount > 0 && iItemCount < 9) {
			inRange = true;
		}
		else if (iItemCount > 9) {
			cout << "Too many items please select between 1 and 8.\n";
		}
		else if (iItemCount < 1) {
			cout << "Please enter a positive number.\n";
		}
	} while (!inRange);

	//Menu Display
	cout << fixed << setprecision(2); //Makes sure it only shows up to 2 decimal places
	cout << "Menu:\n";
	cout << "1. Coffee - R" << COFFEE_PRICE << "\n";
	cout << "2. Sandwich - R" << SANDWICH_PRICE << "\n";
	cout << "3. Salad - R" << SALAD_PRICE << "\n";
	cout << "4. Juice - R" << JUICE_PRICE << "\n";
	cout << "5. Muffin - R" << MUFFIN_PRICE << "\n";
	cout << "6. Pizza Slice - R" << PIZZA_PRICE << "\n";
	cout << "7. Soup - R" << SOUP_PRICE << "\n";
	cout << "8. Burger - R" << BURGER_PRICE << "\n";

	//Calculating Total
	for (int i = 0; i < iItemCount;) {
		cout << "	Select item " << i + 1 << " (1-8): "; //Plus one is to ensure that users see it in the form of 1-8 instead of 0 to 7
		cin >> SelectedItem;

		if (isValidNumber(SelectedItem)) {
			switch (SelectedItem) {
			case 1:
				fTotal += COFFEE_PRICE; // Increment total by Const basically adding
				i++;
				break;
			case 2:
				fTotal += SANDWICH_PRICE;
				i++;
				break;
			case 3:
				fTotal += SALAD_PRICE;
				i++;
				break;
			case 4:
				fTotal += JUICE_PRICE;
				i++;
				break;
			case 5:
				fTotal += MUFFIN_PRICE;
				i++;
				break;
			case 6:
				fTotal += PIZZA_PRICE;
				i++;
				break;
			case 7:
				fTotal += SOUP_PRICE;
				i++;
				break;
			case 8:
				fTotal += BURGER_PRICE;
				i++;
				break;
			}
		}
		else {
			cout << "Enter a valid item number (1-8)!\n";
		}
	}

	cout << "Total Bill: R" << fTotal << endl;

	//Get discount if valid
	if (fTotal > DISCOUNT_THRESHOLD) {
		fDiscount = fTotal * DISCOUNT_RATE; //Get value of the discount
		fDiscountedAmount = fTotal - fDiscount; //Subtract discount from full price
		cout << "Discount amount: R" << fDiscount << endl;
		cout << "Final Bill: R" << fDiscountedAmount << endl;

		//Append to textfile
		outputFile << sName << " " << sSurname << " Total: " << fDiscountedAmount << endl;
	}
	else {
		cout << "No discount applied.\n";
		cout << "Final Bill: R" << fTotal << endl;

		//Append to file
		outputFile << sName << " " << sSurname << " Total: " << fTotal << endl;
	}


	
	outputFile.close();
	cout << "The bill has been written to CafeteriaBill.txt.\n";

}



//IDEA PLANNING

//Error Handling
/*
 Create a Bool function to ensure that people do not enter numbers in they name (Done)
 Ensure that people pick between 1-8 else error and reset (Done)
*/

//Processing
/*
	For loop ( int iItems = 0; i < iItems + 1; i++)
		ask for loop item number
		if item number > 0 && number < 9
			switch (selected Item)
			case 1-8: Total += + itemPrice
		else:
			Error and repick

	if total > 100 then give discount
	else no discount is displayed

	Display everything

*/