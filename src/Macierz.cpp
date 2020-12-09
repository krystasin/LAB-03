
#include <Macierz.h>
#include <iomanip> 
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;



Macierz::Macierz(int x)
{
    if( x<= 0)  throw std::runtime_error{" rozmiar macierzy musi byc większy od 0 "};
    if( x >= 100)  throw std::runtime_error{" rozmiar macierzy musi byc mniejszy od 100 "};

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
    if( n<= 0 || m<=0)  throw std::runtime_error{" rozmiar macierzy musi byc większy od 0 "};
    if( n >= 100 || m >= 100)  throw std::runtime_error{" rozmiar macierzy musi byc mniejszy od 100 "};

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
    if( !odczyt.good() ) throw std::runtime_error{ "blad odczytu pliku" };

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
Macierz::~Macierz(){}


//   USTAWIA WARTOSC KOMURKI
void Macierz::set(int n, int m, double val)
{
    if( n<0 || n>=W || m<0 ||m>=K ) throw runtime_error{ "podyny wiersz lub kolumna jest z poza zakresu macierzy" };
    M[n][m] = val;
}

// ZWRACA WARTOSC KOMURKI
double Macierz::get(int n, int m){   
    if( n<0 || n>=W || m<0 ||m>=K ) throw runtime_error{ "podyny wiersz lub kolumna jest z poza zakresu macierzy" };

    return M[n][m];
}


// WYSWIETLA
void Macierz::print()
{

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++)      cout << setfill(' ') << setw(4) << M[i][j];
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




// OPERACJE NA MACIERZACH

// DODAWANIE
Macierz Macierz::add(Macierz m2)
{ 
    if (!(m2.rows() == W && m2.cols() == K))    throw std::runtime_error{ "zly rozmiar macierzy" };
   
    Macierz nowa(W,K);
    for (int i = 0; i < W; i++)
        for (int j = 0; j < K; j++)
           nowa.set(i,j, M[i][j] + m2.get(i,j));

    return nowa;
}



// ODEJMOWANIE
Macierz Macierz::subtract(Macierz m2)
{
    if (!(m2.rows() == W && m2.cols() == K))    throw std::runtime_error{ "zly rozmiar macierzy" };

    Macierz nowa(W, K);
    for (int i = 0; i < W; i++)
        for (int j = 0; j < K; j++)
            nowa.set(i, j, M[i][j] - m2.get(i, j));

    return nowa;
}

// MNOZENIE
Macierz Macierz::multiply(Macierz m2)
{
    if (K != m2.rows()) throw std::runtime_error{ "nie mozna wykonac mnozenia na tych macierzach" };

    int C=m2.cols();
    Macierz nowa(W, C);

    int rows = W;
    int cols = K;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < C; j++)
            for (int l = 0; l < cols; l++) {
                double temp = M[i][l] * m2.get(l, j);
                nowa.set(i, j, nowa.get(i, j) + temp);
            }   
    return nowa;
}





// ZAPIS DO PLIKU
int Macierz::store(string filename)
{
    fstream zapis;
    zapis.open(filename, std::ios::out);

    if (zapis.good() == false)  throw std::runtime_error{ "blad otwarcia pliku" };

    zapis << W << " " << K << endl;

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++)    zapis << M[i][j] << " ";
        zapis << endl;
    }

    zapis.close();
    return 0;
}
