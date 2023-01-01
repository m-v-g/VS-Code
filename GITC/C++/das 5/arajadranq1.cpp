/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int arr1[] = {10,20,30,10,20,10,20,30,40,50,60,70,10,20,30,40,10,20,30,40,50,60};
    int arr_size = sizeof (arr1)/sizeof(arr1[0]);
    int maximum = 1;
    int qanak = 1;
    int max_val_index = 0; // hishum enq te maximal arjeq vor indexum enq unecel
    
    
    
    for(int i = 0; i < arr_size - 1; i++)
    {
        if(arr1[i] < arr1[i+1])
        {
           qanak++; 
        }
        else 
        {
            
            if(qanak > maximum)
            {
                max_val_index = i + 1;
                maximum = qanak;
            }
            qanak = 1;
        }
        
        if(qanak > maximum)
            {
                max_val_index = i + 1;
                maximum = qanak;
            }
            
        
    }
    
    cout << maximum << endl << endl;
    cout << max_val_index << endl << endl;
    
    int arr2[maximum];
    int m = maximum;
    
    //arajinic erkrord kopya enel sksac max_val_index-ic nvazelov
    
    for(int i = max_val_index; i > 0; --i)
    {
        arr2[maximum - 1] = arr1[max_val_index];
        -- maximum;
        -- max_val_index;
        
    }
    
    //erkrord masivi tpel
    
    for(int i = 0; i < m; ++i)
    {
        
        cout << arr2[i] << endl;
    }
    
    
    return 0;
}