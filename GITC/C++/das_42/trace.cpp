#include <iostream>
#include <climits> //INT_MAX
#include <array> //obertka dlya staticheskogo masiva
#include <vector> //obertka dlya dinamicheskogo masiva
//#include <windows.h>
//#define windows
#define SIZE 9 //simvolicheskaya konstanta

using namespace std;

#ifdef windows
    HANDLE hConsole;

    enum
    {
        Black = 0,
        DarkBlue = 1,
        Green = 2,
        SkyBlue = 3,
        Red = 4,
        Purple = 5,
        Yellow = 6,
        White = 7
    };
#endif

typedef array<string, SIZE> ARRAY_STRING;
typedef array<array<int, SIZE>, SIZE> ARRAY_INT_2D;
typedef array<bool, SIZE> ARRAY_BOOL;
typedef array<int, SIZE> ARRAY_INT;
typedef pair<int, int> PAIR_INT;
typedef vector<string> VECTOR_STRING;

PAIR_INT input(const ARRAY_STRING &name); //funkciya vvoda prinimaet ssilku na masiv vozvrashaet parsrovannuyu par ponktov
void traice(const PAIR_INT &src_dst, ARRAY_INT &qasher, const ARRAY_INT_2D &incidentsTable, ARRAY_BOOL &checkTable, ARRAY_INT &lastChaig); //funkciya trasirovki
void output(const PAIR_INT &src_dst, const ARRAY_STRING &name, const ARRAY_INT &qasher, const ARRAY_INT &lastChaig); //funkciya vivoda
#ifdef windows
    void print_colour(const PAIR_INT &src_dst, const ARRAY_STRING &name, const ARRAY_INT_2D &incidentsTable, const ARRAY_INT &lastChaig);
#endif

class Node //class-i mej class sarqenq, LinkedLIst-i private sektorum mek e Node -in mainic chbdi sarkenq 
{
    public: //Node -i memberner@ tox public exnin mek e mainic menq iranc chenq tesni
        int key;  //arjeqi member
        int value;
        Node* prev; //ukazatel tipa Node
        Node* next; //ukazatel tipa Node
                
        Node(int key, int value) //Node-i konstruktor arjeq@ menq kudalq prev u next inq@ kveragre NULL
        {
            this->key = key;      //lyuboy Node ira mej kpahe ira arjeq@ 
            this->value = value;
            prev = nullptr; //hajordi hascen defoltov NULL
            next = nullptr; //naxordi hascen defoltov NULL
        }
};

class PriorityQueue
{
    public:
        Node* head = nullptr;
        Node* tail = nullptr;
        
        ~ PriorityQueue()
        {
            if(head != nullptr) //ete inq@ datark e hech ban chenenq 
            {
                while(head != tail)      //hertov ertanq araj minchev poch
                {
                    head = head -> next; //me qaylm araj ganq
                    delete head -> prev; //jnjenq ira naxordin
                }
                delete head;             //verjum mnac es me uzel@
            }
        }
        
        void push(int key, int value)
        {
            #ifdef classDebug
                cout << "--> key: " << key << " value: " << value << endl;
            #endif
            Node* temp = new Node(key, value);
            if(head == nullptr)       //ete inq@ araji uzeln e
            {
                head = temp;
                tail = temp;
            }
            else if (temp->value < head->value)
            {
                head->prev = temp;
                temp->next = head;
                head = temp;
            }
            else
            {
                Node* iterator = head;
                while ((value >= iterator->value) && (iterator != tail))
                {
                    iterator = iterator->next;
                }
                if (iterator == tail && value >= tail->value)
                {
                    temp->prev = tail;
                    tail->next = temp;
                    tail = temp;
                }
                else
                {
                    iterator->prev->next = temp;
                    temp->next = iterator;
                    temp->prev = iterator->prev;
                    iterator->prev = temp;
                }
            }
        }
        Node pop()
        {
            if (head == nullptr) // datark e
            {
                #ifdef classDebug
                    cout << "Pop enelu ban chka" << endl;
                #endif
                throw 404;
            }
            else
            {
                Node tmp(head->key, head->value);
                Node* temp = head;
                if (head == tail) //mek element e
                {
                    head = tail = nullptr;
                    #ifdef classDebug
                        cout << "<-- key: " << temp->key << " value: " << temp->value << endl;
                    #endif
                    delete temp;
                    return tmp;
                }
                else
                {
                    head = head -> next;
                    head -> prev = nullptr;
                    #ifdef classDebug
                        cout << "<-- key: " << temp->key << " value: " << temp->value << endl;
                    #endif
                    delete temp;
                    return tmp;
                }
            }
            
        }
        void print() //tpelu funkcia
        { 
            Node* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
            while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
            {
                cout << temp->key << " : " << temp->value << endl;
                temp = temp->next;  //temp-in veragrenq hajord uzel@
            } 
            cout << endl;          
        } //tpelu funkciai verj
        
};

int main()
{
    const ARRAY_INT_2D incidentsTable = {{ //tablica smejnosti dlya gorodov
        {0, 5, 0, 0, 0, 0, 45, 0, 15},
        {5, 0, 0, 0, 0, 0, 0, 12, 0},
        {0, 0, 0, 20, 0, 60, 0, 0, 0},
        {0, 0, 20, 0, 60, 0, 40, 0, 0},
        {0, 0, 0, 60, 0, 0, 0, 30, 0},
        {0, 0, 60, 0, 0, 0, 25, 0, 30},
        {45, 0, 0, 40, 0, 25, 0, 70, 0},
        {0, 12, 0, 0, 30, 0, 70, 0, 0},
        {15, 0, 0, 0, 0, 30, 0, 0, 0}
    }};

    ARRAY_BOOL checkTable; //masiv dlya proverki statusa obrabotki
    checkTable.fill(0); //inicalizaciya masia znacheniyami 0

    const ARRAY_STRING name = {//masiv dlya imen
        "Ashtarak",
        "Erevan",
        "Gyumri",
        "Artik",
        "Yeghvard",
        "Talin",
        "Aparan",
        "Abovyan",
        "Oshakan"
    };

    ARRAY_INT qasher; //masiv dlya xraneniya vesa goroda
    ARRAY_INT lastChaig; //masiv dlya xraneniya ot kokogo goroda prishlo polednoe izminenie
    qasher.fill(INT_MAX); //inicalizaciya masia znacheniyami INT_MAX
    lastChaig.fill(INT_MAX); //inicalizaciya masia znacheniyami INT_MAX

    PAIR_INT src_dst = input(name); //razuznaem otkud kuda nado
    
    traice(src_dst, qasher, incidentsTable, checkTable, lastChaig);
    
    output(src_dst, name, qasher, lastChaig);

    #ifdef windows
        print_colour(src_dst, name, incidentsTable, lastChaig);
    #endif
    
    return 0;
}

PAIR_INT input(const ARRAY_STRING &name) //prinimaet ssilku na masiv vozvrashaet parsrovannuyu par ponktov
{
    PAIR_INT src_dst;
    string source; //tochka otpravleniya
    string destination; //tochka naznacheniya
    bool correct = false;
    while (!correct)
    {
        cout << "Enter the source point ";
        cin >> source;
        for(int i = 0; i < name.size(); ++i)
        {
            if(source == name.at(i))
            {
                src_dst.first = i;
                correct = true;
            }
        }
    }
    correct = false;
    while (!correct)
    {
        cout << "Enter the destination point ";
        cin >> destination;
        for(int i = 0; i < name.size(); ++i)
        {
            if(destination == name.at(i) && source != destination)
            {
                src_dst.second = i;
                correct = true;
            }
        }
    }
    
  
    return src_dst;
}

void traice(const PAIR_INT &src_dst, ARRAY_INT &qasher, const ARRAY_INT_2D &incidentsTable, ARRAY_BOOL &checkTable, ARRAY_INT &lastChaig)
{
    qasher[src_dst.first] = 0; //elman keti qash@ khavasarcnenq 0-i
    PriorityQueue pq;
    pq.push(src_dst.first, qasher[src_dst.first]); //pq-i mej lcnenq elman ket@ or procesin start tanq
    int currentKey;
    int currentVal;
    while (pq.head != nullptr)           //qni der pq datark che
    {
        Node temp = pq.pop();    //vercnenq amenapoqr nod@
        currentKey = temp.key;   //
        currentVal = temp.value;
        for (int i = 0; i <= 8; ++i)
        {
            if(currentKey != src_dst.second) //qani der chenq hase nshanakaket
            {
                if(incidentsTable[currentKey][i] && !checkTable[i]) //stugenq te es anunov qaxaq@ um het e harevan
                {                                             //u ete ed harevan@ stugvac che
                    
                    if((incidentsTable[currentKey][i] + currentVal) < qasher[i]) //ete gtel enq aveli karch champa
                    {
                        
                        qasher[i] = incidentsTable[currentKey][i] + currentVal; //elman qaxaqi qashin gumarenq harevani heravorutyun@
                                                                                //u @dig kexni ed qaxaqi qash@
                        pq.push(i, qasher[i]); //iran grenq pq-i mej or ira harevannerin el stugenq
                        lastChaig[i] = currentKey;
                    }
                    
                }
            } 
        }
        checkTable[currentKey] = true; //nshenq or ed qaxaq@ stugvac e
        
    }
}

void output(const PAIR_INT &src_dst, const ARRAY_STRING &name, const ARRAY_INT &qasher, const ARRAY_INT &lastChaig)
{
    cout << "The distance between " << name[src_dst.first] << " and " << name[src_dst.second] << " is " << qasher[src_dst.second] << endl;
    int iterator = src_dst.second;
    VECTOR_STRING trace;
    while (iterator != INT_MAX)
    {
        trace.push_back(name[iterator]);
        iterator = lastChaig[iterator];
        if (iterator != INT_MAX)
        {
            trace.push_back(" -> ");
        } 
    }
    trace.push_back("The optimal trace is ");

    for (int i = trace.size(); i > 0; --i)
    {
        cout << trace[i - 1];
    }
    cout << endl;
}

#ifdef windows
    void print_colour(const PAIR_INT &src_dst, const ARRAY_STRING &name, const ARRAY_INT_2D &incidentsTable, const ARRAY_INT &lastChaig)
    {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //poluchenie deskriptora konsoli
        const ARRAY_STRING abbr = {//masiv dlya abriviatur
            "ASH",
            "EVN",
            "GYM",
            "ART",
            "YGV",
            "TAL",
            "APR",
            "ABV",
            "OSH"
        };
        for (int i = 0; i < SIZE; ++i)
        {
            
        }
        
    }
#endif
