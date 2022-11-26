//Stack Queue Deque



#include <iostream>
using namespace std;

class Node //class-i mej class sarqenq, LinkedLIst-i private sektorum mek e Node -in mainic chbdi sarkenq 
    {
        public: //Node -i memberner@ tox public exnin mek e mainic menq iranc chenq tesni
            int value;  //arjeqi member
            Node* prev; //ukazatel tipa Node
            Node* next; //ukazatel tipa Node
                
            Node(int x) //Node-i konstruktor arjeq@ menq kudalq prev u next inq@ kveragre NULL
            {
                value = x;      //lyuboy Node ira mej kpahe ira arjeq@ 
                prev = nullptr; //hajordi hascen defoltov NULL
                next = nullptr; //naxordi hascen defoltov NULL
            }
    }; 

class Stack
{
    private:  
        Node* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
        Node* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
        int listsQuantity = 0; //lister qanak@ hasvelu hamar
        
    public:  
        ~ Stack()
        {
            if(head == nullptr)
            {
                delete head;
            }
            
        }  
        void print(bool av_re) //tpelu funkcia
        { 
            if(av_re) //avers
            {
                cout << "\tNULL" << endl;
                cout << "\tV" << endl;
                cout << "\t|" << endl;
                Node* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
                while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
                {
                    cout << "VALUE:\t" << temp -> value << endl;
                    cout << "PREV:\t" << temp -> prev << endl;
                    cout << "NEXT:\t" << temp -> next << endl;
                    temp = temp -> next;  //temp-in veragrenq hajord uzel@
                    cout << "\t|" << endl;
                    cout << "\tV" << endl;
                }
                cout << "\tNULL" << endl;
            }
            else //revers
            {
                cout << "\tNULL" << endl;
                cout << "\t^" << endl;
                cout << "\t|" << endl;
                Node* temp = tail;        //sarqeq nor popoxakan vorpeszi tail@ chpchacnenq
                while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase skizb
                {
                    cout << "VALUE:\t" << temp -> value << endl;
                    cout << "NEXT:\t" << temp -> next << endl;
                    cout << "PREV:\t" << temp -> prev << endl;
                    temp = temp -> prev;  //temp-in veragrenq naxord uzel@
                    cout << "\t^" << endl;
                    cout << "\t|" << endl;
                }
                cout << "\tNULL" << endl;
            }
            
        } //tpelu funkciai verj

        void push (int value) //demic grelu funkcia
        {
            Node* temp = new Node(value); //stexcenq nor temp anunov Node* tesaki uzel
            if(head == nullptr)       //ete inq@ araji uzeln e
            {
                head = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
                tail = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
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

        int pop (void) //demic jnjox funkcia
        {
            if(head == nullptr)
            {
                cout << "List is empty ";
                return 0;
            }
            else
            {
                Node* temp = head; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
                head = head -> next;  //glxi mej@ pahenq ira arajva nexti hascen
                head -> prev = nullptr; //hmigva glxi prev = NULL
                -- listsQuantity;
                return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
        } //demic jnjox funkciai verj
};      

class Queue
{
    private:
        Node* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
        Node* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
        int listsQuantity = 0; //lister qanak@ hasvelu hamar
        
    public:    
        void print(bool av_re) //tpelu funkcia
        { 
            if(av_re) //avers
            {
                cout << "\tNULL" << endl;
                cout << "\tV" << endl;
                cout << "\t|" << endl;
                Node* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
                while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
                {
                    cout << "VALUE:\t" << temp -> value << endl;
                    cout << "PREV:\t" << temp -> prev << endl;
                    cout << "NEXT:\t" << temp -> next << endl;
                    temp = temp -> next;  //temp-in veragrenq hajord uzel@
                    cout << "\t|" << endl;
                    cout << "\tV" << endl;
                }
                cout << "\tNULL" << endl;
            }
            else //revers
            {
                cout << "\tNULL" << endl;
                cout << "\t^" << endl;
                cout << "\t|" << endl;
                Node* temp = tail;        //sarqeq nor popoxakan vorpeszi tail@ chpchacnenq
                while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase skizb
                {
                    cout << "VALUE:\t" << temp -> value << endl;
                    cout << "NEXT:\t" << temp -> next << endl;
                    cout << "PREV:\t" << temp -> prev << endl;
                    temp = temp -> prev;  //temp-in veragrenq naxord uzel@
                    cout << "\t^" << endl;
                    cout << "\t|" << endl;
                }
                cout << "\tNULL" << endl;
            }
            
        } //tpelu funkciai verj

        void push (int value) //demic grelu funkcia
        {
            Node* temp = new Node(value); //stexcenq nor temp anunov Node* tesaki uzel
            if(head == nullptr)       //ete inq@ araji uzeln e
            {
                head = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
                tail = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
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

        int pop (void) //hetevic jnjox funkcia
        {
            if(head == nullptr)
            {
                cout << "List is empty ";
                return 0;
            }
            else
            {
                Node* temp = tail; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
                tail = tail -> prev; //pochi mej@ pahenq ira arajva previ hascen
                tail -> next = nullptr; //hmigva pochi next = NULL
                -- listsQuantity;
                return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
            
        } //hetevic jnjox funkciai verj
};

class Deque
{
    private:   
        Node* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
        Node* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
        int listsQuantity = 0; //lister qanak@ hasvelu hamar
        
    public:    
        void print(bool av_re) //tpelu funkcia
        { 
            if(av_re) //avers
            {
                cout << "\tNULL" << endl;
                cout << "\tV" << endl;
                cout << "\t|" << endl;
                Node* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
                while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
                {
                    cout << "VALUE:\t" << temp -> value << endl;
                    cout << "PREV:\t" << temp -> prev << endl;
                    cout << "NEXT:\t" << temp -> next << endl;
                    temp = temp -> next;  //temp-in veragrenq hajord uzel@
                    cout << "\t|" << endl;
                    cout << "\tV" << endl;
                }
                cout << "\tNULL" << endl;
            }
            else //revers
            {
                cout << "\tNULL" << endl;
                cout << "\t^" << endl;
                cout << "\t|" << endl;
                Node* temp = tail;        //sarqeq nor popoxakan vorpeszi tail@ chpchacnenq
                while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase skizb
                {
                    cout << "VALUE:\t" << temp -> value << endl;
                    cout << "NEXT:\t" << temp -> next << endl;
                    cout << "PREV:\t" << temp -> prev << endl;
                    temp = temp -> prev;  //temp-in veragrenq naxord uzel@
                    cout << "\t^" << endl;
                    cout << "\t|" << endl;
                }
                cout << "\tNULL" << endl;
            }
            
        } //tpelu funkciai verj

        void push_back(int value) //hetevic grelu funkcia
        {
            Node* temp = new Node(value); //stexcenq nor temp anunov Node* tesaki uzel
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
        
        void push_front(int value) //demic grelu funkcia
        {
            Node* temp = new Node(value); //stexcenq nor temp anunov Node* tesaki uzel
            if(head == nullptr)       //ete inq@ araji uzeln e
            {
                head = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
                tail = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
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

        int pop_back(void) //hetevic jnjox funkcia
        {
            if(head == nullptr)
            {
                cout << "List is empty ";
                return 0;
            }
            else
            {
                Node* temp = tail; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
                tail = tail -> prev; //pochi mej@ pahenq ira arajva previ hascen
                tail -> next = nullptr; //hmigva pochi next = NULL
                -- listsQuantity;
                return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
            
        } //hetevic jnjox funkciai verj
        
        int pop_front(void) //demic jnjox funkcia
        {
            if(head == nullptr)
            {
                cout << "List is empty ";
                return 0;
            }
            else
            {
                Node* temp = head; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
                head = head -> next;  //glxi mej@ pahenq ira arajva nexti hascen
                head -> prev = nullptr; //hmigva glxi prev = NULL
                -- listsQuantity;
                return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
        } //demic jnjox funkciai verj
};


int main()
{

    Stack daran;
    daran.push(10);
    daran.push(20);
    cout << "daranic stacanq " << daran.pop() << endl;

    Queue hert;
    hert.push(11);
    hert.push(22);
    cout << "hertic stacanq " << hert.pop() << endl;

    Deque erkkhert;
    erkkhert.push_front(111);
    erkkhert.push_back(222);
    erkkhert.push_back(333);
    cout << "erkkoxmani herti demic stacanq " << erkkhert.pop_front() << endl;
    cout << "erkkoxmani herti hetevic stacanq " << erkkhert.pop_back() << endl;

    return 0;
}
