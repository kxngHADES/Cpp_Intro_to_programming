//Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <array>

//Namespaces
using namespace std;

//Functions
bool isMark(int iMark) {
	if (iMark < 0 && iMark > 100) {
		return false;
	}
	else {
		return true;
	}
}




//Main function
int main() {

	//Variables
		//Arrasy
	float fMarks[5] = {};

		//Floats
	float fAverage = 0.00f;

		//int
	int iHighest = 0, iLowest = 99999, iTotal = 0, iMark = 0; //lowest set to 9999 to ensure that we find lowest for real


	cout << "Enter the scores for 5 students:\n";
	//Get scores
	for (int i = 0; i < 5; i++) {
		cout << "Enter score for student " << i + 1 << ":"; // i + 1 so we start counting learnes as 1-5 not 0-4
		cin >> iMark;
		if (isMark(iMark)) {
			fMarks[i] = iMark;
		}
		else {
			do {
				cout << "Not a valid percentage please enter score fr student " << i + 1 << ":";
				cin >> iMark;
			} while (!isMark(iMark));
		}
	}


	//Display scores in order
	cout << "\n\nScores entered: \n";
	for (int j = 0; j < 5; j++) {
		cout << "Student " << j + 1 << ": " << fMarks[j] << endl; // j + 1 so we start counting learnes as 1-5 not 0-4
	}


	//Get information from loop
	for (int k = 0; k < 5; k++) {
		//Lowest
		if (fMarks[k] < iLowest) {
			iLowest = fMarks[k];
		}
		//Highest
		if (fMarks[k] > iHighest) {
			iHighest = fMarks[k];
		}

		//Total
		iTotal += fMarks[k];
	}

	//Average
	fAverage = iTotal / 5;


	//Display
	cout << "\n\n";
	cout << fixed << setprecision(2);
	cout << "Average score: " << fAverage << endl;
	cout << "Highest score: " << iHighest << endl;
	cout << "Lowest score: " << iLowest << endl;

}