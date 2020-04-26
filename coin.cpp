#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void coinChange(int, int, int, ofstream&);
void outputString(string, ofstream&);

int main() {
	// open data, output file
  ifstream inputFile;
  inputFile.open("data.txt");

  ofstream outFile;
  outFile.open("change.txt");

	// read input file, and assign each number to proper variable, and calculate coinChange
	while (inputFile.peek() != EOF) {
		int c, n, k, temp = 0;
		inputFile >> temp;
		if (temp == '\n') {
			// flush new line string
			inputFile >> temp;
		} else {
			c = temp;
			inputFile >> k;
			inputFile >> n;
			string outputHeader = "Data input: c = " + to_string(c) + ", k = " + to_string(k) + ", n = " + to_string(n) + "\n";
			outputString(outputHeader, outFile);
			coinChange(c, k, n, outFile);
		}
	}
	inputFile.close();
	return 0;
}

void coinChange(int c, int k, int n, ofstream& outFile) {
	// array to store denominations
	int deno[20];
	// vector to store coin counts
	vector<int> coinCounts;

	for (int i = 0; i <= k; i++) {
		deno[i] = pow(double(c), double(i));
	}

	for (int i = k; i >= 0; i--) {
		string outputLine = "Denomination: " + to_string(deno[i]) + " Quantity: ";

		// increase count for the number of current denomination can be used for remaining n
		int count = 0;
		while (n >= deno[i]) {
			count++;
			n -= deno[i];
			coinCounts.push_back(deno[i]);
		}

		// concat proper output with counts
		if (count == 0) {
			outputLine += "none";
		} else {
			outputLine += to_string(count);
		}
		outputLine += "\n";
		outputString(outputLine, outFile);
	}

	outputString("\n", outFile);
}

// handle output to console and output file
void outputString(string outputString, ofstream& outFile) {
  cout << outputString;
  outFile << outputString;
}