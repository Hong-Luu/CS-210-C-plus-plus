// Hong Luu
// CS 210
// Project Three

// Standard libraries required for the program
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>
#include <algorithm>
using namespace std;

// Function to display the menu
void displayMenu() {
	cout << "Menu options: " << endl;
	cout << "1. Find the frequency of an item" << endl;
	cout << "2. Print the frequency of all items purchased" << endl;
	cout << "3. Print the frequency of all items purchased in a histogram form" << endl;
	cout << "4. Exit" << endl;
	cout << endl;
}

// Define the WordFrequency class
class WordFrequency {
public:
	// Constructor for the class
	WordFrequency();
	// function to get the frequency of a word
	int getFrequency(string word);

	// function to add a word to the frequency map
	void addWord(string word);

	// function to get the frequency map
	map<string, int> getFrequencyMap() const {
		return frequencyMap;
	}

private:
	// Map to store the frequency of each word
	map<string, int> frequencyMap;
};

// Default constructor for the WordFrequency class. Initializes an empty frequency map.
WordFrequency::WordFrequency() {}

// Implement the getFrequency function
int WordFrequency::getFrequency(string word) {
	// convert the word to lowercase
	transform(word.begin(), word.end(), word.begin(), ::tolower);

	// if the word is not in the frequency map, then return 0
	if (frequencyMap.count(word) == 0) {
		return 0;
	}
	// otherwise, return the frequency of the word
	return frequencyMap[word];
}

// Function addWord
void WordFrequency::addWord(string word) {
	// convert the word to lowercase
	transform(word.begin(), word.end(), word.begin(), ::tolower);

	// Increase the frequency of the word by 1
	frequencyMap[word]++;
}

// Function fileAccess
WordFrequency fileAccess() {
	// create an object of class type WordFrequency
	WordFrequency wordFrequency;

	// open the input file
	ifstream file("CS210_Project_Three_Input_File.txt");

	// print error message if the file can't open
	if (!file.is_open()) {
		cout << "Could not open file." << endl;
		return wordFrequency;
	}

	// Read each word from the file and add it to the frequency map
	string word;
	while (file >> word) {
		wordFrequency.addWord(word);
	}

	// close the input file
	file.close();

	return wordFrequency;
}

// Function optionOne to print the frequency of the item inputed from user
void optionOne() {
	// create an object of class type WordFrequency, initialized with data from the input file
	WordFrequency wordFrequency = fileAccess();

	// prompt the user to enter a word
	cout << "Enter the word that you wish to look for: " << endl;
	string word;
	cin >> word;

	// get the frequency of the word
	int frequency = wordFrequency.getFrequency(word);

	// print the frequency of the word
	cout << "Frequency of the word '" << word << "': " << frequency << endl;
}

// Function optionTwo to print all items purchased with numbers
void optionTwo() {
	// create an object of class type WordFrequency, initialized with data from the input file
	WordFrequency wordFrequency = fileAccess();

	// print the frequency of all words
	for (const auto& item : wordFrequency.getFrequencyMap()) {
		cout << item.first << " " << item.second << endl;
	}
}

// Function optionThree to print all items purchased in a histogram form
void optionThree() {
	// create an object of class type WordFrequency, initialized with data from the input file
	WordFrequency wordFrequency = fileAccess();

	// iterate through all the items in the frequency map
	for (const auto& item : wordFrequency.getFrequencyMap()) {
		cout << item.first << " ";
		for (int i = 0; i < item.second; i++) {
			cout << "*";
		}
		cout << endl;
	}
}

// Function optionFour to exit the program
void optionFour() {
	// print a message to indicate that the program is being exited
	cout << "Exiting the program. Goodbye!" << endl;

	// exit the program with a status of 0 to indicate success
	exit(0);
}

// Function to process the menu options 
void processingMenu() {
	int option;

	// loop for processing menu options until user chooses to exit (option 4)
	while (true) {

		// Message to prompt user to pick an option
		cout << "Enter option: ";

		// read in user's option choice
		cin >> option;

		// switch statement to call corresponding function for each option
		switch (option) {
		case 1:
			optionOne(); // calling function optionOne
			cout << endl;
			break;
		case 2:
			optionTwo(); // calling function optionTwo
			cout << endl;
			break;
		case 3:
			optionThree(); // calling function optionThree
			cout << endl;
			break;
		case 4:
			optionFour(); // calling function optionFour
			return;
		default:
			cout << "Invalid option" << endl; // default message output for invalid input
		}
	}
}

// Main function that initializes displayMenu and processingMenu
int main() {
	// display the menu options to the user
	displayMenu();

	// process user's selected menu option and perform respective function
	processingMenu();

	// indicate successful execution of the program
	return 0;
}