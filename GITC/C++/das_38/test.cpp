#include <iostream>
#include <climits>

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
                throw 404;
            }
            else
            {
                Node tmp(head->key, head->value);
                Node* temp = head;
                if (head == tail) //mek element e
                {
                    head = tail = nullptr;
                    delete temp;
                    return tmp;
                }
                else
                {
                    head = head -> next;
                    head -> prev = nullptr;
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
    PriorityQueue pq;
    pq.push(2, 0);
    pq.pop();
    pq.push(3, 20);
    pq.push(5, 60);
    pq.pop();
    pq.push(4, 80);
    pq.push(6, 60);
    pq.print();
    //pq.pop();
    return 0;
}