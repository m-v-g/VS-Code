

#include <iostream>
#include <Windows.h> //guyneri hamar
#include <conio.h>

using namespace std;
HANDLE hConsole; //eli guyneri hamar

//rekursivnaya funkciya vibora ugla otscheta
int menuCorner(void)
{
    int corner = -1;
    SetConsoleTextAttribute(hConsole, 4);
    cout << "7----9" << endl;
    cout << "|    |" << endl;
    cout << "|    |" << endl;
    cout << "1----3" << endl;
    cout << "chois the corner = _\b";
    cin >> corner;
    if(corner != 1 && corner != 3 && corner != 7 && corner != 9) //ete uglovoy che
    {
        cout << "\a";
        corner = menuCorner(); //rekursiya
    }
    return corner;
}

//rekursivnaya funkciya vibora granic masiva
void lenght(int& a, int& b)
{
    cout << "rows = ";
    cin >> a;
    cout << "cols = ";
    cin >> b;
    if(a < 1 || a > 18 || b < 1 || b > 18) //avel@ chi texavorvi
    {
        cout << "\a";
        lenght(a, b); //rekursiya
    }
}



// Есть такой универсальный подход.
// Это интерпретировать любой двумерный массив, как одномерный, и передавать значения размеров каждой размерности массива.
void print( int array[], int m, int n )
{   //hotizonakan gic
    for(int g = 1; g < 9 * (n - 1); ++g) //amen syuni hamar 9 hat gits tpel
        {
            SetConsoleTextAttribute(hConsole, 7);
            cout << "-";
        }
    cout << endl;

    for ( int i = 0; i < m; ++i )
    {
        cout << "| ";
        for ( int j = 0; j < n; ++j )
        {
            SetConsoleTextAttribute(hConsole, 1);
            cout << array[i * n + j ] << "\t| "; //
        }
        cout << endl;
        
        //hotizonakan gic
        SetConsoleTextAttribute(hConsole, 7);
        for(int g = 1; g < 9 * (n - 1); ++g) //amen syuni hamar 9 hat gits tpel
        {
            cout << "-";
        }
        cout << endl;
    }
    
}    


int main()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//eli guyneri hamar
    int ket = menuCorner();//ugol otscheta
    int n;
    int m;
    lenght(n, m);
    

    int rs = 0;
    int cs = 0;
    int re = n - 1; //skzbic es erkusi texer@ xarnel ei, hmi hastat chi xarnvi
    int ce = m - 1; //skzbic es erkusi texer@ xarnel ei, hmi hastat chi xarnvi
    int x = 1;
    int array[n][m];
    
    while(x <= n * m)
    {
        if(ket == 7 || ket < 0) //vervi dzax ugl
        {
            for(int i = cs; i <= ce && x <= n * m; ++i) //horizonakan dzaxic aj
            {
                array[rs][i] = x++; //grenq masivi mej tox@ hastatun 
            }
            ++ rs; //ajic 1-ov krchatenq
            ket = -1; //vorpeszi mnacac if tru exnin
        }
        
        if(ket == 9 || ket < 0) //verevi aj ugl
        {
            for(int i = rs; i <= re && x <= n * m; ++i) //uxxahayac verevic nerqev
            {
                array[i][ce] = x++; //grenq masivi mej syun@ hastatun 
            }
            -- ce; //nerqevic 1-ov krchatenq
            ket = -1; //vorpeszi mnacac if tru exnin
        }
        
        if(ket == 3 || ket < 0) //nerqevi aj ugl
        {
            for(int i = ce; i >= cs && x <= n * m; --i) //horizonakan ajic dzax
            {
                array[re][i] = x++; //grenq masivi mej tox@ hastatun 
            }
            -- re; //dzaxic 1-ov krchatenq
            ket = -1; //vorpeszi mnacac if tru exnin
        }
        
        if(ket == 1 || ket < 0) //nerqevi dzax ugl
        {
            for(int i = re; i >= rs && x <= n * m; --i) //uxxahayac nerqevic verev
            {
                array[i][cs] = x++; //grenq masivi mej syun@ hastatun
            }
            ++ cs; //vervic 1-ov krchatenq
            ket = -1; //vorpeszi mnacac if tru exnin
        }
    }
    
    print( reinterpret_cast<int *>( array ), n, m ); //chaskcanq te inch erinq, bayc erinq

    _getch();
    return 0;
}



