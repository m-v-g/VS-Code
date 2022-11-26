/******************************************************************************

arajadranq 5/2

*******************************************************************************/
#include <iostream>
//#define VERSION 1 //ete VERSION = 1 - Hayki grac, VERSION = 2 - sax unikal, VERSION = 3 - sax havasar, VERSION = 4 - sax 0 verjum 9
using namespace std;

int main()
{

    int arr_a[] = {10,7,10,7,22,7,10,15,14,15,9}; //Hayki grac
    //int arr_a[] = {10,20,30,40,50,60,70,80,90,100,110}; //sax unikal
    //int arr_a[] = {10,10,10,10,10,10,10,10,10,10,10}; //sax havasar
    //int arr_a[] = {0,0,0,0,0,0,0,0,0,0,9}; //sax 0 vercnum 9
    int arr_a_size = sizeof(arr_a) / sizeof(arr_a[0]); //arr_a -i chap@ voroshel
    
    cout << "____ ARRAY A ____" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < arr_a_size; ++i)
    {
        cout << "| " << arr_a[i] << "\t"; //parzvig@ tabulyacian nayev viravnivat kene
    }
    cout << "|" << endl << "-----------------------------------------------------------------------------------------"  << endl << endl;
    
    cout << "arr \" A \" size equal to " << arr_a_size << endl << endl;
    int arr_b_c_size = arr_a_size; //arr_b_c_size popoxakan haytararenq arr_a_size -i chapov heto knayemq ete petq exav kpoqrcnenq
    
    //raschet razmera buduschix vasivov
    
    for(int i = 0; i < arr_a_size - 1; ++i) //mec ciklov vercnum enq arajinic minchev naxaverjin element@
    {
        for(int j = i + 1; j < arr_a_size; ++j) //poqr ciklov vercnum enq erkrordic minchev verjin element@
        {
            if(arr_a[i] == arr_a[j]) //ete gtel enq gone mek ham@nkum uremn arr_b_c_size -@ kpoqrcnenq 1-ov mnacac ham@nkumner@ karevor chen
            {
                -- arr_b_c_size; //poqrcrinq
                break;           //durs ekanq poqr ciklic mnacacner@ karevor chen
            }
        }
    }
    cout << "arr \" B \" & \" C \" size eqal to " << arr_b_c_size << endl << endl << endl;
    
    //obyavlenie masivov

    int arr_b[arr_b_c_size] = {0}; //arden mer masivneri chaper@ gitenq sarqenq iranc 0 -nerov nafsyaki, sig unikal elementner@ pahelu hamar e
    int arr_c[arr_b_c_size] = {0}; //arden mer masivneri chaper@ gitenq sarqenq iranc 0 -nerov nafsyaki, sig unikal elementneri qanak@ pahelu hamar e
    
    
    
    
    //**************       arr_b -i elementner@ lracnenq       ***************// dzerac het el arr_c -n
    
    arr_b[0] = arr_a[0]; // arr_a -i araji element@ palyubomu unikal e vorovhetev arr_b -n hl@ lcvac che, kopya enenq or procesi star@ tanq u hamematelu ban unenanq
    int index = 1;       // es popoxakan@ kuda mer poqr cikli chap@ 1 sarqel@ mer gor@ qichm kheshtcne (erevi, heto kereva)
    arr_c[0] = 1; //arr_b[0] -um arden banm ka uremn arr_c[0] -i mej@ grenq ed masin
    
    
    for(int i = 1; i < arr_a_size; ++i) //mec cikln e arr_a -i elementner@ hertov hamematelu hamar, bayc arajin element@ petq ce @dur hamar el ksksvi 1-ic
    {
        bool eqal = true;               //es el erevi mer gorc@ kheshtcne, nayenq
        for(int j = 0; j < index; ++j)  //poqr cikln e arr_b -i elementneri het hamematelu hamar index -n el dinamik e hetagayum bdi kamacic loji mecna
        {
            if(arr_a[i] == arr_b[j])    //sksenq arr_a[1] -ic (erkrordic) u arr_b[0] -ic (arajinic)
            {
                arr_c[j] += 1;// !!!!!!!!!!!!! parzvav es me toxov dzerac het arr_c -n el lcecin prcanq !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                break; //ete henc skzbic el gtanq durs ganq poqr ciklic or stugenq arr_a -i hajord element@
            }
            else //isk ete chenq gte
            {
                if(j < index - 1) //me hatm el stugenq te arr_b[j] elementic heto eli elemen ka te che 
                {
                    continue;     //ete ka ancninq arr_b -i hajord elementi het hamematelun
                }
                else              //ete chka ksenq or arr_a[i] -n unikal e u ira het me banm bdi exncvi
                {
                   eqal = false;  //stex parzecinq or qicm heshtcrec
                }
                
            }
            
            if(eqal == false) //ete poqr cikli es krugi @ntacqum gtel enq unikal element
            {                 //qani vor mer index kursor@ arden mer uzac pazicyayi vra e
               arr_b[index] = arr_a[i]; //arr_b -i henc ed pazicyayum grenq mer unikal elementi arjeq@
               ++ index;                //kursor@ taninq araj or hetagayum mer poqr cikl@ loji
            }
        }
    }
    
    

    //CHSORTAVORVAC MASIVNERI TPUM (dzerac het el oblogorodit enenq vneshny vid@) !!!!!!!!!!!!
    
    cout << "___ UNSORTED ____" << endl;
    cout << "-----------------" << endl;
    cout << "| arr B" << "\t" << "| arr C" <<  "\t" << "| " << endl;
    cout << "-----------------" << endl;
    for(int i = 0; i < arr_b_c_size; ++i)
    {
        cout << "| " << arr_b[i] << "\t" << "| " << arr_c[i] <<  "\t" << "| " << endl; //parzvig@ tabulyacian nayev viravnivat kene
        cout << "-----------------" << endl;
    }
    cout << endl << endl;
    
    
    //masivneri sortirovka
    

    int arr_sort_size = arr_b_c_size; //lracucich popoxakan or heto chmolrinq
    int temp;                         //buferny popoxakan swop-i jamanak arjeqner@ pahelu hamar
    bool b = true;                    //vorpisi mnanq cikli mej qani der sortirovka chi exel
    
    
    while(b) //ete b -n true e
    {
        b = false; //mtneluc heto anmijapes false kenenq
    for(int i = 0; i < arr_sort_size - 1; ++ i) //ksksenq arajinic minchev axaverji element@ or masivi granicneric durs chganq
    {
        
        if(arr_c[i] > arr_c[i+1])    //ete element@ mec e hajord elementic
        
        { //arr_c -i swap enel
            temp = arr_c[i];         //buferi mej pahenq elementi arjeq@
            arr_c[i] = arr_c[i+1];   //elementi mej pahenq hajord elementi arjeq@
            arr_c[i+1] = temp;       //hajord elementi mej dnenq buferi arjeq@
            
            // qani vor arr_c -i inch vor elementner swap enq erel uremn tramabanakan e or arr_b -i nuyn elementnern el bdi swap enenq
            temp = arr_b[i];         //buferi mej pahenq elementi arjeq@
            arr_b[i] = arr_b[i+1];   //elementi mej pahenq hajord elementi arjeq@
            arr_b[i+1] = temp;       //hajord elementi mej dnenq buferi arjeq@
            
            //ete menq if -i mej mtel enq uremn texi e unecel swap -i gorcoxutyun
            b = true; //ayd isk patcharov b -n true sarqenq or noric mtninq while hech or ban che me hadm vrov ancninq 
        }   //ete sax sortavorac e menq stex chenq el haytnvi b -n kmna false
        
    }
    -- arr_sort_size; //mer diapazon@ m hatovm poqrcnenq or antexi verj@ chstugenq @ndex arden amenamecn e
    }
    
    //   SORTAVORVAC MASIVNERI TPUM (dzerac het el gistogramma sarqenq) !!!!!!!!!!!!
    
    cout << "__________ SORTED ___________" << endl;
    cout << "-----------------------------" << endl;
    cout << "| arr B" << "\t" << "| arr C" <<  "\t" << "| HISTOGRAM |" << endl;
    cout << "-----------------------------" << endl;
    for(int i = 0; i < arr_b_c_size; ++i)
    {
        cout << "| " << arr_b[i] << "\t" << "| " << arr_c[i] <<  "\t" << "| "; //parzvig@ tabulyacian nayev viravnivat kene
        
        
        //GISTOGRAMMA gcelu hamar cikl
        for(int j = 1; j <= arr_c[i]; ++j) //cikl minimum 1 hat maximum arr_c[konkret elementi]
        {
            cout << "*";                   //cikli mej tpenq arr_c[i] ha astxanish
        }
        
        cout << endl;                      //hajord tox@
        cout << "-----------------------------" << endl;
    }
    cout << endl << endl;
    

    return 0;
}




