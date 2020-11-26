#pragma once
#ifndef ARTWORKH
#define ARTWORKH

#include "Artist.h"
#include <string>
#include <iostream>
using namespace std;

class Artwork {
public:
    Artwork();

    Artwork(string title, int yearCreated, Artist artist);

    string GetTitle();
    int GetYearCreated();
    void PrintInfo();
    Artist GetArtist();
    friend ostream& operator<<(ostream& out, Artist rhs);
    bool operator <(Artwork rhs);

private:
    // TODO: Declare private data members - title, yearCreated
    string title;
    int yearCreated;
    // TODO: Declare private data member artist of type Artist
    Artist artist;
};

#endif