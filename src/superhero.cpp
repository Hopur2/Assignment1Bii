#include "superhero.h"
Superhero::Superhero()
{
     name[0] = '\0';
        age = 0;
        power = '\0';


        verbose = true;
}
void Superhero::setVerbose(bool v)
    {
        verbose = v;
    }

istream& operator >>(istream& in, Superhero& data)
{
     if(data.verbose)
        {
            cout << "enter name: ";
        }

        in >> data.name;

        if(data.verbose)
        {
            cout << "enter age: ";
        }
        in >> data.age;

        if(data.verbose)
        {
            cout << "enter power: ";
        }
        in >> data.power;



        return in;
}

ostream& operator <<(ostream& out, Superhero& data)
{
        if(data.verbose)
        {
            out << "name :";

        }
        out << data.name << endl;

        if(data.verbose)
        {
            out << "age :";

        }
        out << data.age << endl;

        if(data.verbose)
        {
            out << "power :";

        }
        switch(data.power)
   {
        case 'f': out << "Flying";
        break;
        case 'g': out << "Giant" ;
        break;
         case 'h': out << "Hacker";
        break;
         case 'n': out << "None";
        break;
        default: out << "Weakling";
        break;
   }




        return out;
}

