//Insertion sort queue



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

class Queue
{
    private:
        Node* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
        Node* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
        int listsQuantity = 0; //lister qanak@ hasvelu hamar
        
    public:  
        ~ Queue()
        {
            if(tail != nullptr) //ete inq@ datark e hech ban chenenq 
            {
                while(tail != head)      //hertov ertanq het minchev glux
                {
                    tail = tail -> prev; //me qaylm het ganq
                    delete tail -> next; //jnjenq ira hajordin
                }
                delete tail;             //verjum mnac es me uzel@
            }
        } 

        void print(void) //tpelu funkcia
        { 

            Node* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
            while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
            {
                cout << temp -> value << "\t";
                temp = temp -> next;  //temp-in veragrenq hajord uzel@
            } 
            cout << endl;          
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
                int tempValue = temp -> value; //te che valuen kkori
                delete temp;
                return tempValue; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
            
        } //hetevic jnjox funkciai verj

        void sort(void)
        {
            Node* temp = head->next;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
            while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
            {
                if(temp->value < temp->prev->value) //ete naxordic mec e
                {
                    if(temp->value < head->value) //ete headic poqr e
                    {
                        temp->prev->next = temp->next; //
                        temp->next->prev = temp->prev; //pokecinq obshu cucakic

                        temp->next = head;    //
                        temp->prev = nullptr; //
                        head->prev = temp;    //texadrenq dem@
                        
                        head = temp;  //inqn e arden head@
                    }
                    else
                    {
                        Node* iterator = head;
                        while(iterator->value < temp->value && iterator->next != tail)
                        {
                            iterator = iterator->next;
                        }
                        if(temp == tail)
                        {
                            temp->prev->next = nullptr; //
                            temp->prev = tail;          //pokecinq obshii pochic cucakic
                        }
                        else
                        {
                            temp->prev->next = temp->next; //
                            temp->next->prev = temp->prev; //pokecinq obshi cucakic
                        }

                        temp->next = iterator;       //
                        temp->prev = iterator->prev; //
                        iterator->prev->next = temp; //
                        iterator->prev = temp;       // xckenq iteratoric heto
                    }
                }
                temp = temp->next;
            } 
        }
};

int main()
{
    Queue hert;
    int array[] = {5, 3, 9, 7, 8, 1, 2, 6, 4};
    //int array[] = {5, 9, 7};
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
    {
        hert.push(array[i]);
    }
    hert.print();
    hert.sort();
    hert.print();


    return 0;
}