#include "Artist.h"
#include <iostream>
#include <string>
using namespace std;

// TODO: Define default constructor
Artist::Artist()
{
	artistName = "None";
	birthYear = 0;
	deathYear = 0;
}

// TODO: Define second constructor to initialize
//       private fields (artistName, birthYear, deathYear)
Artist::Artist(string aName, int bYear, int dYear)
{
	artistName = aName;
	birthYear = bYear;
	deathYear = dYear;
}


// TODO: Define get functions: GetName(), GetBirthYear(), GetDeathYear()
 string Artist::GetName() const
{
	return artistName;
}

int Artist::GetBirthYear() const
{
	return birthYear;
}

int Artist::GetDeathYear() const
{
	return deathYear;
}


// TODO: Define PrintInfo() function
//      If deathYear is entered as -1, only print birthYear
void Artist::PrintInfo() const
{
	if (GetDeathYear() == -1)
	{
		cout << GetName() + ", born " + to_string(GetBirthYear()) << endl;
	}
	else
	{
		cout << GetName() + " (" + to_string(GetBirthYear()) + "-" + to_string(GetDeathYear()) + ")" << endl;
	}
}

// TODO: overload the operator<< to do what PrintInfo() does.
ostream& operator <<(ostream &out, Artist rhs)
{
	rhs.PrintInfo();
	return out;
}

bool Artist::operator <(Artist rhs)
{
	if (birthYear < rhs.birthYear)
	{
		return true;
	}
	else
	{
		return false;
	}
}