#include <iostream>
#include <string>

class Macierz
{

private:
    int W=0;      //wiersze
    int K=0;      //kolumny
public:    
    double** M;


    Macierz(){};
    Macierz(int x);
    Macierz(int n, int m);
    Macierz(const char* filename); 
    ~Macierz();
    
    void set(int , int , double );
    double get(int , int );
    void print();
    void info();

    
    int cols(){return K;}
    int rows(){return W;}

    Macierz* add(Macierz *m);
    Macierz* subtract(Macierz *m);
    Macierz* multiply(Macierz *m);

    int store(std::string filename);








};