#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct list
{
	char letter;
	int freq;
};

void toLowerCase(string& str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] <= 90 && str[i] >= 65) {
			str[i] = str[i] + 32;
		}
	}
}


vector<int> getLetterFrequency(const string& str, vector<int> counter) {
	
	//counter.at(0);   
	for (int i = 0; str[i] != '\0'; i++) {
		counter[str[i] - 'a'] += 1;
	}
	return counter;
}

int main() {
	string sampleText;
	vector<int> counter(26);

	cout << "Provide a sample text:" << endl;
	getline(cin, sampleText);
	toLowerCase(sampleText);
	cout << "You entered : " << sampleText << endl;
	getLetterFrequency(sampleText, counter);
	for (unsigned int i = 0; i < counter.size(); i++) {
		cout << char(i + 'a') << ': ' << counter[i];
		cout << endl;
	}
		

	return 0;
}
