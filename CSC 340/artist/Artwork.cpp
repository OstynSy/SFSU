#include "Artwork.h"

// TODO: Define default constructor
Artwork::Artwork()
{
    title = "None";
    yearCreated = 0;
}

// TODO: Define second constructor to initialize
//       private fields (title, yearCreated, artist)
Artwork::Artwork(string titl, int yCreated, Artist artis)
{
    title = titl;
    yearCreated = yCreated;
    artist = artis;
}

// TODO: Define get functions: GetTitle(), GetYearCreated()
string Artwork::GetTitle()
{
    return title;
}

int Artwork::GetYearCreated()
{
    return yearCreated;
}

Artist Artwork::GetArtist()
{
    return artist;
}

// TODO: Define PrintInfo() function
void Artwork::PrintInfo()
{
    cout << "Artist: " << artist;
    cout << "Title: " + GetTitle() + ", " + to_string(GetYearCreated());
}

ostream& operator <<(ostream& out, Artwork rhs)
{
	rhs.PrintInfo();
	return out;
}

bool Artwork::operator <(Artwork rhs)
{
	if (yearCreated < rhs.yearCreated)
	{
		return true;
	}
	else
	{
		return false;
	}
}