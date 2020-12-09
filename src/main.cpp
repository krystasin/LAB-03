#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <Macierz.h>

using namespace std;

int main(int argc, char *argv[])
{

    Macierz m1(7);
    Macierz m2(7, 4);
    Macierz m3(7, 4);

    for (int i = 0; i < m1.rows(); i++)
        for (int j = 0; j < m1.cols(); j++)
            try
            {
                m1.set(i, j, i + j);
            }
            catch (const std::runtime_error &ex)
            {
                std::cout << "-wyjatek- :" << ex.what() << std::endl;
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

    try
    {
        Macierz mnoz = m1.multiply(m2);
        cout << "\nmnozenie: m1 x m2\n";
        mnoz.print();

        try
        {
            mnoz.store("zapis/mnoz.txt");
        }
        catch (const std::runtime_error &ex)
        {
            std::cerr << ex.what() << '\n';
        }
    }
    catch (const std::runtime_error &ex)
    {
        std::cout << "-wyjatek- :" << ex.what() << std::endl;
    }

    Macierz suma = m2.add(m3);
    cout << "\nsuma: m2 + m3\n";
    suma.print();

    try    {
        m1.store("zapis/kszton1.txt");
    }
    catch (const std::runtime_error &ex)    {
        m2.store("zapis/kszton2.txt");
    }


    try    {    
        m3.store("zapis/kszton3.txt");
    }
    catch(const std::runtime_error& e)    {
        std::cerr << e.what() << '\n';
    }

    try    {
       suma.store("zapis/suma.txt");
    }
    catch(const std::runtime_error& e)    
    {
       std::cerr << e.what() << '\n';
    }
        


    //odczyt macierzy z pliku   
    try
    {
        Macierz m4("zapis/suma.txt");
        cout << "\nm4: z suma.txt\n";
        m4.print(); 
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    cout << "\n_____________________________________________\n";



    try     // przykład wystąpienia wyjątku
    {
        Macierz mm = m1.add(m2);
    }
    catch (const std::runtime_error &ex)
    {
        cout << "wystapil wyjatek o bledzie: " << ex.what();
    }
   
cin.get();
    system("PAUSE");
    return 0;
}