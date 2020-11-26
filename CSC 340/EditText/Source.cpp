#include <iostream>
#include <string>
using namespace std;

void ShortenSpace(string&);
void ReplaceExclamation(string&);
double FindText(string, const string);
double GetNumOfWords(const string);
int GetNumOfNonWSCharacters(const string);
char PrintMenu(string);

int main() {
    string text = "", input="";
  

    cout << "Enter a sample text:" << endl;
    getline(cin, text);
    cout << endl;

    cout << "You entered: " << text << endl;
    cout << endl;

    while (input != "q")
    {
        input = PrintMenu(text);
    }

    return 0;
}

char PrintMenu(string text)
{
    char choice = ' ';

    cout << "Menu" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl;

    cout << "Choose an option:" << endl;
    cin >> choice;
    cout << endl;

    switch (choice)
    {
        case 'c':
        {
            cout << "Number of non - whitespace characters : " << GetNumOfNonWSCharacters(text) << endl;
            cout << endl;
            break;
        }

        case 'w':
        {
            cout << "Number of words: " << GetNumOfWords(text) << endl;
            cout << endl;
            break;
        }

        case 'f':
        {
            string search;
            cin.ignore();
            cout << "Enter a word or phrase to be found: " << endl;
            cin >> search;
            cout << '"' << search << '"' << " instances: " << FindText(search, text) << endl;
            cout << endl;
            break;
        }

        case 'r':
        {
            ReplaceExclamation(text);
            cout << "Edited text: " << text << endl;
            cout << endl;
            break;
        }

        case 's':
        {
            ShortenSpace(text);
            cout << "Edited text: " << text << endl;
            cout << endl;
            break;
        }

    }
    return choice;
}

int GetNumOfNonWSCharacters(const string text)
{
    int Space = 0;
    for (unsigned int i = 0; i <= text.size(); i++)
    {
        if (isspace(text[i]))
        {
            Space++;
        }
    }
    return text.size() - Space;
}

double GetNumOfWords(string text)
{
    double words = 0;
    for (unsigned int i = 0; i <= text.size(); i++)
    {
        if (isspace(text[i]))
        {
            while (isspace(text[i]))
            {
                i++;
            }
            words++;
        }
    }
    return words + 1;
}

double FindText(string word, const string text)
{
    int found = 0;
    for (unsigned int i = 0; i < text.size(); i++)
    {
        unsigned int j = 0;
        if (text[i] == word[j])
        {
            while (text[i] == word[j] && j < word.size())
            {
                j++;
                i++;
            }

            if (j == word.size())
            {
                found++;
            }
        }
    }

    return found;
}

void ReplaceExclamation(string& text)
{
    for (unsigned int i = 0; i <= text.size(); i++)
    {
        if (text[i] == '!')
        {
            text[i] = '.';
        }
    }
}

void ShortenSpace(string& text)
{
    for (unsigned int i = 0; i <= text.size(); i++)
    {
        if(isspace(text[i]))
        {
            i++;
            while (isspace(text[i]))
            {
                text.erase(i, 1);
            }     
        }
    }
}