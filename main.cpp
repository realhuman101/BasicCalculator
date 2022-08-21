#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <locale>

using namespace std;

string strVector2string(vector<string> str, string join = "") {
	// Converts a vector of strings into one solid string

	string result;

	for (int i = 0; i < str.size(); i++) result += str[i] + join;
	
	return result;
}

vector<string> split(string str, char delim = ' ') {
	// Returns a vector of strings based on the splitted string provided (splits by the delim variable, by default a space)

	vector<string> splitted;
	int current = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == delim) {
			splitted.push_back(str.substr(current, i-current));
			current = i+1;
		}
	}

	return splitted;
}

int calculate(string symbol, int value1, int value2) {
    // Does math with numbers
    
    int result;
    if (symbol == "+") {
		result = value1 + value2;
	}
	else if (symbol == "-") {
		result = value1 - value2;
	}
	else if (symbol == "*") {
		result = value1 * value2;
	}
	else if (symbol == "/") {
		result = value1 / value2;
	}

    return result;
}

int strDigits (string str) {
	// Returns number of digits in string

	int count = 0;
	locale loc;

    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str.at(i), loc)) count++;
    }

	return count;
}

int operate(vector<string> equation) {
	// Calculate the math

	int current = stoi(equation[0]);

    for (int i = 2; i <= equation.size(); i += 2) {
		current = calculate(equation[i-1], current, stoi(equation[i]));
	}

	return current;
}


int main() {
	string input;
	cout << "Enter equation: ";
    getline(cin, input);

	cout << input << " = " << operate(split(input + " ")) << endl;
}