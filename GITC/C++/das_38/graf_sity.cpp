#include <iostream>
#include <climits>
#include <vector>
//#define classDebug
//#define mainDebug

using namespace std;

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
    int incidentsTable[9][9]{
        {0, 5, 0, 0, 0, 0, 45, 0, 15},
        {5, 0, 0, 0, 0, 0, 0, 12, 0},
        {0, 0, 0, 20, 0, 60, 0, 0, 0},
        {0, 0, 20, 0, 60, 0, 40, 0, 0},
        {0, 0, 0, 60, 0, 0, 0, 30, 0},
        {0, 0, 60, 0, 0, 0, 25, 0, 30},
        {45, 0, 0, 40, 0, 25, 0, 70, 0},
        {0, 12, 0, 0, 30, 0, 70, 0, 0},
        {15, 0, 0, 0, 0, 30, 0, 0, 0}
    };

    bool checkTable[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    string name[9]
    {
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
    
    int qasher[9];
    int lastChaig[9];
    for (int i = 0; i <= 8; i++)
    {
        qasher[i] = INT_MAX;
        lastChaig[i] = INT_MAX;
    }
    
    string source;
    string destination;
    int dstIndex;
    int srcIndex;

    cout << "Enter the source point ";
    cin >> source;
    cout << "Enter the destination point ";
    cin >> destination;

    for (int i = 0; i <= 8; ++i)
    {
        if (source == name[i])
        {
            srcIndex = i;
            cout << "Source point found at index: " << srcIndex << endl;
        }
    }
    for (int i = 0; i <= 8; ++i)
    {
        if (destination == name[i])
        {
            dstIndex = i;
            cout << "Destination point found at index: " << dstIndex << endl;
        }
    }
    qasher[srcIndex] = 0; //elman keti qash@ khavasarcnenq 0-i
    PriorityQueue pq;
    pq.push(srcIndex, qasher[srcIndex]); //pq-i mej lcnenq elman ket@ or procesin start tanq
    int currentKey;
    int currentVal;
    #ifdef mainDebug
        int whileCicle = 1;
    #endif
    while (pq.head != nullptr)           //qni der pq datark che
    {
        Node temp = pq.pop();    //vercnenq amenapoqr nod@
        currentKey = temp.key;   //
        currentVal = temp.value;
        for (int i = 0; i <= 8; ++i)
        {
            if(currentKey != dstIndex) //qani der chenq hase nshanakaket
            {
                if(incidentsTable[currentKey][i] && !checkTable[i]) //stugenq te es anunov qaxaq@ um het e harevan
                {                                             //u ete ed harevan@ stugvac che
                    #ifdef mainDebug
                        cout << "-------------------------------------" << endl;
                        cout << name[currentKey] << " ic depi " << name[i] << " heravorutyun@ = " << incidentsTable[currentKey][i] << endl;
                        //cout << "irar mijev heravorutyun@ = " << incidentsTable[currentKey][i] << endl;
                        cout << name[currentKey] << " qash@ = " << currentVal << endl;
                        //cout << "currentKay = " << currentKey << endl;
                        //cout << "qasher[i] = " << qasher[i] << endl;
                        cout << "-------------------------------------" << endl;
                    #endif
                    if((incidentsTable[currentKey][i] + currentVal) < qasher[i]) //ete gtel enq aveli karch champa
                    {
                        #ifdef mainDebug
                            if (qasher[i] != INT_MAX)
                            {
                                cout << "aveli karc champa gtanq" << endl;
                            }
                        #endif
                        qasher[i] = incidentsTable[currentKey][i] + currentVal; //elman qaxaqi qashin gumarenq harevani heravorutyun@
                                                                                //u @dig kexni ed qaxaqi qash@
                        pq.push(i, qasher[i]); //iran grenq pq-i mej or ira harevannerin el stugenq
                        lastChaig[i] = currentKey;
                    }
                    #ifdef mainDebug
                        else
                        {
                            cout << "es champen aveli erkar e" << endl;
                        }
                    #endif
                }
            } 
        }
        checkTable[currentKey] = true; //nshenq or ed qaxaq@ stugvac e
        #ifdef mainDebug
            cout << whileCicle << " pop " << name[currentKey] << " qash@: " << qasher[currentKey] << endl;
            for (int i = 0; i <= 8; ++i)
            {
                cout << lastChaig[i] << "\t";
            }
            cout << endl;
            ++whileCicle;
            cout << "=========================" << endl;
            cout << "anun\tqash\tstugvac" << endl;
            for (int i = 0; i <= 8; ++i)
            {
                cout << name[i] << "\t";
                qasher[i] == INT_MAX ? cout << "∞" : cout << qasher[i];
                cout << "\t" << checkTable[i] << endl;
            }
            cout << "=========================" << endl;
        #endif
    }

    cout << "The distance between " << name[srcIndex] << " and " << name[dstIndex] << " is " << qasher[dstIndex] << endl;
    int iterator = dstIndex;
    vector<string> trace;
    while (iterator != INT_MAX)
    {
        trace.push_back(name[iterator]);
        iterator = lastChaig[iterator];
        if (iterator != INT_MAX)
        {
            //cout << " <- ";
            trace.push_back(" -> ");
        } 
    }
    trace.push_back("The optimal trace is ");

    for (int i = trace.size(); i > 0; --i)
    {
        cout << trace[i - 1];
    }
    cout << endl;
    return 0;
}