#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <Macierz.h>

using namespace std;


std::ostream &operator<<(std::ostream &stream, Macierz &M){
    
    std::cout << M.rows() << " " << M.cols() <<  std::endl;
    for (int i = 0; i < M.rows(); i++) {
        for (int j = 0; j < M.cols(); j++)      cout << setfill(' ') << setw(4) << M.get(i,j);
        std::cout << std::endl;
    }
    return stream;
}



int main(int argc, char *argv[])
{

    Macierz m1(7);
    Macierz m2(7, 4);
    Macierz m3(7, 4);

    for (int i = 0; i < m1.rows(); i++)
        for (int j = 0; j < m1.cols(); j++)
        {
            try
            {
                m1.set(i, j, i + j);
            }
            catch (const std::runtime_error &ex)
            {
                std::cout << "-wyjatek- :" << ex.what() << std::endl;
            }
        }    

    for (int i = 0; i < m2.rows(); i++)
        for (int j = 0; j < m2.cols(); j++)
        {
            try
            {
                m2.set(i, j, i + 2 * j);
            }
            catch (const std::runtime_error &ex)
            {
                std::cout << "-wyjatek- :" << ex.what() << std::endl;
            }

            try
            {
                m3.set(i, j, 2 * i + j);
            }
            catch (const std::runtime_error &ex)
            {
                std::cout << "-wyjatek- :" << ex.what() << std::endl;
            }
        }

    cout << "m1:\n";
    m1.print();
    cout << "\nm2:\n";
    m2.print();
    cout << "\nm3:\n";
    m3.print();


    std::cout << "iloczyn: m1*m2 \n";
    try
    { 
        Macierz o1 = m1*m2;
        std::cout << o1 ;

    }
    catch(const std::exception& e)   {
       std::cerr << "runtime_error what() : "<< e.what() << '\n';
     }


    std::cout << "różnica: m1-m2 \n";
    try
    { 
        Macierz o1 = m3-m2;
        std::cout << o1 ;
     
    }
    catch(const std::exception& e)   {
       std::cerr << "runtime_error what() : "<< e.what() << '\n';
    }


    std::cout << "Suma: m3+m2   --zapis do pliku\n" ;
    try
    { 
        Macierz o1 = m3+m2;
        std::cout << o1 ;
        try
        {
            o1.store("zapis/suma.txt");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    catch(const std::exception& e)   {
       std::cerr << "runtime_error what() : "<< e.what() << '\n';
    }

    Macierz S = m2;
    cout << "\n\n m2: \n" << m2;
    cout << "\n\n S: \n" << S;

    int x =( S == m2);
    cout << "operator == działa " << x <<endl;
    
    double *ptr = S[2];
    for (int i = 0;  i < S.cols(); i++)
        cout << *ptr << "  ";
    cout << endl;
    





    //odczyt macierzy z pliku   
    try
    {
        Macierz m4("zapis/suma.txt");
        cout << "\nm4: z suma.txt\n" << m4 << endl;
       
    }
    catch(const std::runtime_error& ex)   {
       std::cerr << "terminate called after throwing an instance of 'std::runtime_error':\n" 
                 << "what(): "<< ex.what() << std::endl;
    }
    

    


    return 0;
}