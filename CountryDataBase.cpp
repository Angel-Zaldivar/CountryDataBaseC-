// S112-Country-Database-App.cpp 
// Author:  A. Zaldivar
// Goal:    Create a database held in parallel vectors
//          with data regarding: country name, capital(s), currencies, languages
// -----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Prototypes --------------------------------------------------------------------
void populateVector(vector<string>& v, string fileName);
void printVector(vector<string>& v, string caption);
void findValueVector(vector<string> v, string key, int& pos, int& counter);
void testSequentialSearch(vector<string> vcountry, vector<string> vcapital, vector<string> vlanguage, vector<string> vcurrency);
void myBinarySearch(vector<string> v, string key, int& pos, int& counter);
void testBinarySearch(vector<string> vcountry, vector<string> vcapital, vector<string> vlanguage, vector<string> vcurrency);


int main()
{
    //Data ddeclaration;
    vector<string> vcountry;
    vector<string> vcapital;
    vector<string> vcurrency;
    vector<string> vlanguage;

    // Populate the World Countries Database
    populateVector(vcountry, "c:/Users/2004a/temp/vcountry.txt");
    //printVector(vcountry, "This is the COUNTRY list");

    populateVector(vcapital, "c:/Users/2004a/temp/vcapital.txt");
    //printVector(vcapital, "This is the CAPITAL list");

    populateVector(vlanguage, "c:/Users/2004a/temp/vlanguage.txt");
    //printVector(vlanguage, "This is the LANGUAGE list");

    populateVector(vcurrency, "c:/Users/2004a/temp/vcurrency.txt");
    //printVector(vcurrency, "This is the CURRENCY list");

    if (vcountry.size() == vcapital.size()
        && vcountry.size() == vcurrency.size()
        && vcountry.size() == vlanguage.size())
    {
        cout << "World Country Database successfully created\n";
    }
    else
    {
        cout << "ERROR - Database is corrupted - diferent sizes\n";
        exit(2);
    }

    testSequentialSearch(vcountry, vcapital, vlanguage, vcurrency);

   testBinarySearch(vcountry, vcapital, vlanguage, vcurrency);

    // Expose a menu to retrive by country
    /*int pos = 0, counter = 0;
    findValueVector(vcountry, "Wakanda", pos, counter);
    if (pos >= 0)
    {
        cout << "\tCountry: " << vcountry[pos] << endl;
        cout << "\tCapital: " << vcapital[pos] << endl;
    }
    cout << "Pos: " << pos << " Counter: " << counter << endl;*/


}
// ------------------------------------------------------------------------------
//User-defined methods
void populateVector(vector<string>& v, string fileName)
{
    ifstream infile(fileName);
    if (!infile)
    {
        cout << "Error - file nt found";
        exit(1);
    }
    string line;
    while (getline(infile, line))
    {
        v.push_back(line);
    }
    infile.close();
}

void printVector(vector<string>& v, string caption)
{
    cout << "\n" << caption << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << i << "\t" << v[i] << endl;
    }
}
//--------------------------------------------------------------------
void findValueVector(vector<string> v, string key, int& pos, int& counter)
{
    counter = 0;
    for (pos = 0; pos < v.size(); pos++)
    {
        counter++;
        if (v[pos] == key)
        {
            return;
        }
    }
    pos = -1;
}

void testSequentialSearch(vector<string> vcountry, vector<string> vcapital, vector<string> vlanguage, vector<string> vcurrency)
{
    do
    {
        string countryName;

        cout << "Enter a country Name [xxx to end]: ";

        getline(cin, countryName);
        if (countryName == "xxx") break;

        int pos = 0, counter = 0;
        findValueVector(vcountry, countryName , pos, counter);

        if (pos >= 0)
        {
            cout << "\t  SEQ SEARCH:" << endl;
            cout << "\tcountry: " << vcountry[pos] << endl;
            cout << "\tcaptial: " << vcapital[pos] << endl;
            cout << "\tLanguage: " << vlanguage[pos] << endl;
            cout << "\tCurrency: " << vcurrency[pos] << endl;

        }
        cout << "pos: " << pos << " counter: " << counter << endl;

    } while (true);
}

//==========================================================
void testBinarySearch(vector<string> vcountry, vector<string> vcapital, vector<string> vlanguage, vector<string> vcurrency)
{

    do
    {
        string countryName;

        cout << "Enter a country Name [xxx to end]: ";

        getline(cin, countryName);
        if (countryName == "xxx") break;

        int pos = 0, counter = 0;
        myBinarySearch(vcountry, countryName, pos, counter);

        if (pos >= 0)

        {
            cout << "\t  BIN SEARCH:" << endl;
            cout << "\tcountry: " << vcountry[pos] << endl;
            cout << "\tcaptial: " << vcapital[pos] << endl;
            cout << "\tLanguage: " << vlanguage[pos] << endl;
            cout << "\tCurrency: " << vcurrency[pos] << endl;

        }
        cout << "pos: " << pos << " counter: " << counter << endl;

    } while (true);
}

void myBinarySearch(vector<string> v, string key, int& pos, int& counter)
{
    counter = 0;
    int first = 0;

    int last = v.size() - 1;

    while (first <= last)
    {
        counter++;
        pos = (first + last) / 2;
        if (v[pos] == key) 
            return;
        if (v[pos] > key)
        {
            last = pos - 1;
        }
        else
        {
            first = pos + 1;
        }
    }

    pos = -1;
}
