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
    
    void set(int, int, double);
    double get(int, int);
    void print();
    void info();

    
    int cols() noexcept {return K;}
    int rows() noexcept {return W;}

    Macierz add(Macierz m);
    Macierz subtract(Macierz m);
    Macierz multiply(Macierz m);

    int store(std::string filename);

  

    Macierz operator+(Macierz &other);
    Macierz operator-(Macierz &other);
    Macierz operator*(Macierz &other);
    bool operator==(Macierz &other);
    double* operator[](int wiersz);

    Macierz operator=(Macierz &other);
    Macierz operator+=(int x);
    Macierz operator++(int x);

};