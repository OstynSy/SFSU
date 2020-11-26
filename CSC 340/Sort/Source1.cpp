#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <algorithm>
using namespace std;

struct TokenFreq {
	string token;
	int freq = 1;
};

TokenFreq operator+(const TokenFreq& w1, const TokenFreq& w2) {
	TokenFreq word;
	word.freq = w1.freq + w2.freq;
	word.token = w1.token + " or " + w2.token;
	return word;
}

bool operator<=(const TokenFreq& w1, const TokenFreq& w2) {
	bool isTrue = false;
	if (w1.freq <= w2.freq)
	{
		isTrue = true;
	}
	return isTrue;
}

ostream& operator<<(ostream& output, const TokenFreq& w) {
	output << "(token, freq)=(" << '"' << w.token << '"' << ", " << w.freq << ")" << endl;
	return output;
}

void matrixInit(vector<vector<int>>& matrix, int numRows, int numCols)
{
	matrix.resize(numRows, vector<int>(numCols));
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			matrix[i][j] = i * j;
		}
	}
	cout << "size of matrix is : " << numRows << "x" << numCols << endl;
}

void getTokenFreqVec(const string& istr, vector<TokenFreq>& tfVec) {

	string token;
	bool isdone = true;
	TokenFreq t;

	istringstream ss(istr);
	isdone = true;
	while (ss>>token)
	{
		transform(token.begin(), token.end(), token.begin(), ::tolower);
		isdone = true;

		for (long unsigned int i = 0; i < tfVec.size(); i++)
		{
			if (tfVec[i].token == token)
			{
				tfVec[i].freq += 1;
				isdone = false;
			}
		}
		if (isdone)
		{
			t.token = token;
			tfVec.push_back(t);
		}
	}
}

void selectionSort(vector<TokenFreq>& tokFreqVector) {

	unsigned int i, j, minIndex;
	TokenFreq tmp;

	for (i = 0; i < tokFreqVector.size() - 1; i++)
	{
		minIndex = i;

		for (j = i + 1; j < tokFreqVector.size(); j++)
		{
			if (tokFreqVector[j].freq <= tokFreqVector[minIndex].freq)
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			tmp = tokFreqVector[i];
			tokFreqVector[i] = tokFreqVector[minIndex];
			tokFreqVector[minIndex] = tmp;
		}
	}
}

void insertionSort(vector<TokenFreq>& tokFreqVector) {

	unsigned int i, j;
	TokenFreq temp;

	for (i = 1; i < tokFreqVector.size(); i++) 
	{
		j = i;

		while (j > 0 && tokFreqVector[j - 1] <= tokFreqVector[j])
		{
			temp = tokFreqVector[j];
			tokFreqVector[j] = tokFreqVector[j - 1];
			tokFreqVector[j - 1] = temp;
			j--;
		}
	}
}

int main() {
	string istr;
	vector <TokenFreq> tfVec;
	vector <vector <int> > matrix;

	cout << "String:";
	getline(cin, istr);

	matrixInit(matrix, 3, 4);

	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			cout << "matrix" <<"["<< i << "]" <<" [" << j << "]" << "=" << matrix[i][j] << endl;
		}
	}
	
	getTokenFreqVec(istr, tfVec);
	cout << "\nToken Frequency\n" << endl;
	cout<<"Size = " << tfVec.size() << " {" << endl;

	for (long unsigned int i = 0; i < tfVec.size(); i++)
	{
		cout << " [" << i << "] = " << tfVec[i];
	}

	selectionSort(tfVec);
	cout << "\nSelection Sort\n" << endl;

	for (long unsigned int i = 0; i < tfVec.size(); i++)
	{
		cout << " [" << i << "] = " << tfVec[i];
	}

	insertionSort(tfVec);
	cout << "\nInsertion Sort\n" << endl;

	for (long unsigned int i = 0; i < tfVec.size(); i++)
	{
		cout << " [" << i << "] = " << tfVec[i];
	}

	return 0;
}