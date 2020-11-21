#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "Macierz.h"

using namespace std;

int main(int argc, char* argv[])
{

    Macierz* m1 = new Macierz(3);
    Macierz* m2 = new Macierz(3,4);

  
    m1->set(0,0,2);
    m1->set(0,1,3);
    m1->set(0,2,4);
    m1->set(1,1,2);
    m1->set(1,0,9);
    m1->set(2,0,8);
    m1->set(2,1,3);


    m2->set(0,0,4);
    m2->set(0,2,5);
    m2->set(1,2,3);
    m2->set(1,1,2);
    m2->set(2,1,4);
    m2->set(2,2,4);
    m2->set(2,3,4);


    cout<<"m1:\n";
    m1->print();
    cout<<"\nm2:\n";
    m2->print();
  
    Macierz* m3 = m1->multiply(m2);

    cout<<"\nm3:\n";
    m3->print();

    m1->store("kszton1.txt");
    m2->store("kszton2.txt");
    m3->store("kszton3.txt");

    Macierz* m4 = new Macierz("kszton3.txt");
    cout<<"\nm4:\n";
    m4->print();
 
    
   
    return 0;
}