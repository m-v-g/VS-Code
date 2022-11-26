#include <iostream>
#include <conio.h> //vorpeszi getch() ashxadi u terminal@ chpakvi

using namespace std;

int menuCorner(void)
{
    int corner = -1;
    cout << "7----9" << endl;
    cout << "|    |" << endl;
    cout << "|    |" << endl;
    cout << "1----3" << endl;
    cout << "chois the corner = _\b";
    cin >> corner;
    if(corner != 1 && corner != 3 && corner != 7 && corner != 9)
    {
        cout << "\a";
        corner = menuCorner();
    }
    
    return corner;
}

int main()
{
    int ket = menuCorner();
    int n;
    int m;
    
    
    
    
    
    cout << "enter the n = __\b\b";
    cin >> n;
    cout << "enter the m = __\b\b";
    cin >> m;

    
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
        
        //araji horizonakan gits@ gtselu hamar
        //cout << "-";
        for(int g = 1; g < 9 * (m - 1); ++g) //amen syuni hamar 9 hat gits tpel
        {
            cout << "-";
        }
        cout << endl;
        
        
        //masiv@ tpelu hamar
    for(int i = 0; i <= n - 1; ++i)
        {
            
            cout << "| ";
            for(int j = 0; j <= m - 1; ++j)
            {
                cout << array[i][j] << "\t| ";
                
            }
            cout << endl;
            
            //amen toxi taki horizonakan gits@ gtselu hamar
            for(int g = 1; g < 9 * (m - 1); ++g) //amen syuni hamar 9 hat gits tpel
            {
                cout << "-";
            }
            cout << endl;
        }
        
    
    //_getch();
    //_getch(); //vorpeszi terminal@ chpakvi

    return 0;
}