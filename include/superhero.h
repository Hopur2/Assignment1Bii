#include <iostream>
#include <fstream>
#include <string>

#ifndef SUPERHERO_H
#define SUPERHERO_H


using namespace std;

class Superhero {

private:
    char name[16];
    int age;
    char power;


    bool verbose;

public:


    Superhero();

    void setVerbose(bool v);

    friend istream& operator >>(istream& in, Superhero& data);
    friend ostream& operator <<(ostream& out, Superhero& data);

};

#endif // SUPERHERO_H
