#include <iostream>
using namespace std;

class Node //class-i mej class sarqenq, LinkedLIst-i private sektorum mek e Node -in mainic chbdi sarkenq 
        {
            public: //Node -i memberner@ tox public exnin mek e mainic menq iranc chenq tesni
                int login;  //arjeqi member
                int password;
                Node* prev; //ukazatel tipa Node
                Node* next; //ukazatel tipa Node
                
                Node(int l, int p) //Node-i konstruktor arjeq@ menq kudalq prev u next inq@ kveragre NULL
                {
                    login = l;      //lyuboy Node ira mej kpahe ira arjeq@ 
                    password = p;
                    prev = nullptr; //hajordi hascen defoltov NULL
                    next = nullptr; //naxordi hascen defoltov NULL
                }
        };

class PriorityQueue
{
    private:    
        void push_back(int l, int p) //hetevic grelu funkcia
        {
            Node* temp = new Node(l, p); //stexcenq nor temp anunov Node* tesaki uzel
            if(head == nullptr)       //ete inq@ araji uzeln e
            {
                head = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
                tail = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
            }
            else                     //ete inq@ miak@ che
            {
                tail -> next = temp; //pochi next cuyc ta temp (araj NULL er chnayac hmi el e NULL)
                temp -> prev = tail; //tempi prev cuyc ta arajva pochin(araj NULL er bayc hmi uni hasce)
                tail = temp;         //temp@ darav mer taza poch@
            }
            ++ listsQuantity;
            return;
        } //hetevic grelu funkciai verj
        
        void push_front(int l, int p) //demic grelu funkcia
        {
            Node* temp = new Node(l, p); //stexcenq nor temp anunov Node* tesaki uzel
            if(head == nullptr)       //ete inq@ araji uzeln e
            {
                head = temp;
                tail = temp;
            }
            else
            {
                temp -> next = head; //tempi next cuyc ta glxin (araj NULL er bayc hmi uni hasce)
                head -> prev = temp; //glxi prev cuyc ta tempin (araj NULL er chnayac hmi el e NULL)
                head = temp;         //temp@ darav mer taza glux@
            }
            ++ listsQuantity;
            return;
        } //demic grelu funkciai verj

    public:
        Node* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
        Node* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
        int listsQuantity = 0; //lister qanak@ hasvelu hamar

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

        void print(void) //tpelu funkcia
        { 
            Node* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
            while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
            {
                cout << temp->login << "\t" << temp->password << endl;
                temp = temp->next;  //temp-in veragrenq hajord uzel@
            }
        } //tpelu funkciai verj

        void add(int l, int p)
        {
            if(head == nullptr)
            {
                push_back(l, p);
            }
            else if(l < head->login)
            {
                push_front(l, p);
            }
            else if(l > tail->login)
            {
                push_back(l, p);
            }
            else
            {
                Node* temp = new Node(l, p); //stexcenq nor temp vori mej pahenq arjeq@
                Node* iterator = tail;        //mi hat el or list@ perebor enenq
                while (iterator->login > l)
                {
                    iterator = iterator -> prev;
                    if(l == iterator->login)
                    {
                        return;
                    }
                }
                
                temp->next = iterator->next;
                temp->prev = iterator;
                iterator->next->prev = temp;
                iterator->next = temp;
                ++ listsQuantity;
            }
        }

        Node pop(int l, int p)
        {
            Node* iterator = head;
            if(l == head->login)
            {
                head = head -> next;
                head -> prev = nullptr;
                -- listsQuantity;
                Node temp(iterator->login, iterator->password);
                delete iterator;
                return temp;
            }
            if(l == tail->login)
            {
                iterator = tail;
                tail = tail -> prev;
                tail -> next = nullptr;
                -- listsQuantity;
                Node temp(iterator->login, iterator->password);
                delete iterator;
                return temp;
            }
            while (iterator->login != l)
            {
                if(iterator == tail)
                {
                    Node temp(-1, -1);
                    return temp;
                }
                iterator = iterator -> next;
            }
            iterator->next->prev = iterator->prev;
            iterator->prev->next = iterator->next;
            iterator->next = iterator->prev = nullptr;
            -- listsQuantity;
            Node temp(iterator->login, iterator->password);
            delete iterator;
            return temp;
        }
        
};

int main()
{
    PriorityQueue pq;

    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int j = 100;
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
    {
        pq.add(array[i], j);
        j += 100;
    }
    
    pq.add(55, 9999);
    pq.print();

    int log = 100;
    int pas = 9999;
    Node temp = pq.pop(log, pas);
    //pq.pop(log, pas);
    cout << "============================" << endl;
    cout << temp.login << "\t" << temp.password << endl << endl;
    pq.print();
}