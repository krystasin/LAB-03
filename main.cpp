#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip> 
#include <time.h> 
#include "Macierz.h"

using namespace std;

int main(int argc, char* argv[])
{
  srand( time(NULL));

    Macierz* m1 = new Macierz(4);
    Macierz* m2 = new Macierz(4,2);
    Macierz* m3 = new Macierz(4,2);

  

    for (int i = 0; i < m1->rows(); i++)
        for (int j=0; j < m1->cols(); j++)
          m1->set(i,j, rand()%10 - 3);
          
      
    for (int i = 0; i < m2->rows(); i++)
        for (int j = 0; j < m2->cols(); j++)
        {
          m2->set(i,j, rand()%10 );
          m3->set(i,j, rand()%10 );
        }
          

    cout<<"m1:\n";      m1->print();
    
    cout<<"\nm2:\n";    m2->print();
    
    cout<<"\nm3:\n";    m3->print();
  
    Macierz* mnoz = m1->multiply(m2);
    cout<<"\nmnozenie: m1 x m2\n";
    mnoz->print();
  
    Macierz* suma = m2->add(m3); 
    cout<<"\nsuma: m2 + m3\n";
    suma->print();






    m1->store("kszton1.txt");
    m2->store("kszton2.txt");
    m3->store("kszton3.txt");
    suma->store("suma.txt");
    mnoz->store("mnoz.txt");


    Macierz* m4 = new Macierz("suma.txt");
    cout<<"\nm4: z suma.txt\n";
    m4->print();
 
    
   
    return 0;
}