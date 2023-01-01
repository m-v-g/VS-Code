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
        void print() //tpelu funkcia
        { 


                Node* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
                while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
                {
                    cout << "VALUE:\t" << temp -> value << endl;
                    temp = temp -> next;  //temp-in veragrenq hajord uzel@
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
                throw 404;
            }
            else
            {                
                Node* temp = head; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
                head = head -> next;  //glxi mej@ pahenq ira arajva nexti hascen
                if(temp == tail)
                {
                    tail->prev = nullptr;
                    return temp->value;
                }
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
    try{
        cout << "daranic stacanq " << daran.pop() << endl;
        cout << "daranic stacanq " << daran.pop() << endl;
        cout << "daranic stacanq " << daran.pop() << endl;
    }
    catch(int ex)
    {
        if(ex == 404)
        {
            cout << "The list is empty" << endl;
        }
    }

    return 0;
}