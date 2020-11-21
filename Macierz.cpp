
#include "Macierz.h"

#include <string>
#include <fstream>
#include <windows.h>

using namespace std;



Macierz::Macierz(int x)
{
    this->W = x;
    this->K = x;

    M = new double* [x];
    for (int i = 0; i < x; i++)
        M[i] = new double[x];

    for (int i = 0; i < x; i++)
        for (int j = 0; j < x; j++)
            M[i][j] = 0;

}

Macierz::Macierz(int n, int m)
{

    this->W = n;
    this->K = m;

    M = new double* [n]; //wiersze
    for (int i = 0; i < n; i++)
        M[i] = new double[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            M[i][j] = 0;

}

Macierz::Macierz(const char* filename)
{
    fstream odczyt;
    odczyt.open(filename, std::ios::in);
    odczyt >> W >> K;

    M = new double* [W]; //wiersze
    for (int i = 0; i < W; i++)
        M[i] = new double[K];

    while(odczyt){
        for (int i = 0; i < W; i++)
            for (int j = 0; j < K; j++)
            odczyt >> M[i][j];
    }

    odczyt.close();
}


// Destruktor
Macierz::~Macierz(){
    for (int i = 0; i < W; i++)
        delete M[i];
    delete M;
}


//   USTAWIA WARTOSC KOMURKI
void Macierz::set(int n, int m, double val)
{
    M[n][m] = val;
}

// ZWRACA WARTOSC KOMURKI
double Macierz::get(int n, int m){
    return M[n][m];
}


// WYSWIETLA
void Macierz::print()
{

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++)      std::cout << M[i][j] << "  ";
        std::cout << std::endl;
    }
}

void Macierz::info(){

    std::cout << "\trows: " << W << "\tkols: " << K << std::endl

        << "\n\tadres \t&M: " << &M << "\t\tM: " << M
        << "\n\t&M[0]: " << &M[0] << "\t\tM[0]: " << M[0]
        << "\n\tM[0][0]: " << M[0][0] << "\t\t &M[0][0]: " << &M[0][0]
        << std::endl << std::endl;
}


// ODEJMOWANIE
Macierz* Macierz::subtract(Macierz* m2)
{
    if (!(m2->rows() == W && m2->cols() == K)) {
        std::cout << " !! macierze muszą miec sam rozmiar" << std::endl;
        return NULL;
    }

    Macierz* nowa = new Macierz(W, K);

    for (int i = 0; i < W; i++)
        for (int j = 0; j < K; j++)
            nowa->set(i, j, M[i][j] - m2->get(i, j));

    return nowa;
}

// MNOZENIE
Macierz* Macierz::multiply(Macierz* m2)
{
    if (K != m2->rows()) {
        std::cout << "tych macierzy nie można przez siebie przemnozyć" << std::endl;
        return NULL;
    }

    int C=m2->cols();

    Macierz* nowa = new Macierz(W, C);

    for (int i = 0; i < W; i++)
        for (int j = 0; j < C; j++)
            for (int l = 0; l < K; l++) {
                double temp = M[i][l] * m2->get(l, j);
                nowa->set(i, j, nowa->get(i, j) + temp);
            }   
    return nowa;
}

// ZAPIS DO PLIKU
int Macierz::store(string filename)
{
    fstream zapis;
    zapis.open(filename, std::ios::out);

    if (zapis.good() == false) {
        std::cout << "nie udało sie otworzyc pliku" << endl;
        return 1;
    }

    zapis << W << " " << K << endl;

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++)    zapis << M[i][j] << " ";
        zapis << endl;
    }

    zapis.close();
    return 0;
}

// DODAWANIE
Macierz* Macierz::add(Macierz* m2)
{


    if (!(m2->rows() == W && m2->cols() == K)) {
        std::cout << " !! aby dodać do do siebie macierze, muszą miec one taki sam rozmiar" << std::endl;
        return NULL;
    }

    Macierz* nowa = new Macierz(W, K);

    for (int i = 0; i < W; i++)
        for (int j = 0; j < K; j++)
            nowa->set(i, j, M[i][j] + m2->get(i, j));

    return nowa;
}

