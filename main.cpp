#include <iostream>
#include <fstream>
#include <vector>
#include <superhero.h>
using namespace std;
void getHero(Superhero hero[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cin >> hero[i];
        cout << endl;
    }
}
void writehero(Superhero hero[], int size)
{
    ofstream fout;

    fout.open("bin.dat", ios::binary|ios::app);

    for(int i = 0; i < size; i++)
    {
        fout.write((char*)(&hero[i]),sizeof(Superhero));
    }
    fout.close();
}
void readHero(vector<Superhero>& heroesVector)
{
    ifstream fin;
    fin.open("bin.dat", ios::binary| ios::app);


    if(fin.is_open()) {
            Superhero hero;

            fin.seekg(0, fin.end);
        int counter = fin.tellg() / sizeof(Superhero);
        fin.seekg(0,fin.beg);
        for(int i = 0; i < counter; i++)
        {
            fin.read((char*)(&hero), sizeof(Superhero));
            heroesVector.push_back(hero);
        }

    }
    else {
        cout << "could not open" << endl;
    }
    fin.close();
}
void printHero(vector<Superhero>& herosVector)
{
    for(unsigned int i = 0; i < herosVector.size(); i++)
    {
        cout << herosVector[i] << endl;
    }
}
int main()
{
    int size = 0;

    cout << "how many?";
    cin >> size;

    Superhero* hero = new Superhero[size];
    vector<Superhero> heroVector;

    getHero(hero, size);
    writehero(hero, size);
    readHero(heroVector);
    printHero(heroVector);

    delete[] hero;
    return 0;
}
