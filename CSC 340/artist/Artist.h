#pragma once
#ifndef ARTISTH
#define ARTISTH

#include <string>
using namespace std;

class Artist {
public:
    Artist();

    Artist(string aName, int bYear, int dYear);

    string GetName() const;

    int GetBirthYear() const;

    int GetDeathYear() const;

    void PrintInfo() const;

    //// TODO: declare the function prototype to overload the operator<< as a friend function 
    //        do what PrintInfo() does.
    friend ostream& operator<<(ostream& out, Artwork rhs);
    // TODO: declare the function prototype to overload the < (less than) operator as a member function to compare two artists' birthyear.
    //       this function returns true if the LHS artist is younger than the RHS artist; false otherwise.
    bool operator <(Artist rhs);


private:
    string artistName;
    int birthYear;
    int deathYear;
};

#endif