
#include <iostream>

using namespace std;



class LinkedLIst
{
    private:
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
        Node* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
        Node* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
        int listsQuantity = 0; //lister qanak@ hasvelu hamar
        
    public:    
        void print(bool ar) //tpelu funkcia
        { 
            if(ar) //avers
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
            Node* temp = tail; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
            tail = tail -> prev; //pochi mej@ pahenq ira arajva previ hascen
            tail -> next = nullptr; //hmigva pochi next = NULL
            -- listsQuantity;
            return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
        } //hetevic jnjox funkciai verj
        
         int pop_front(void) //demic jnjox funkcia
        {
            Node* temp = head; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
            head = head -> next;  //glxi mej@ pahenq ira arajva nexti hascen
            head -> prev = nullptr; //hmigva glxi prev = NULL
            -- listsQuantity;
            return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
        } //demic jnjox funkciai verj
        
        bool is_empty(void) //kstuge datark e te che
        {
            if(head == nullptr && tail == nullptr) //(head == 0 && tail == 0)-asxadav, (head == false && tail == false)-chasxadav, (listsQuantity == 0)
            {
                return true;
            }
            else return false;
        }// datarkutyan funkciai verj
        
        int get_index (int index) //tvac indexi value tpelu funkcia
        {
            int qanakKes = listsQuantity / 2;
            Node* temp;
            int qayl;
            if(index <= 0 || index > listsQuantity)
            {
                cout << "Index not found ";
                return 0;
            }
            if(index <= qanakKes) //ete mer index@ mejtexn e kam mot e skzbin
            {
                cout << "(skzbic) ";
                temp = head; //sksenq glxic
                qayl = 1; //sksenq 1-ic mincev index-erord@
                while(qayl != index)
                {
                    temp = temp -> next;
                    ++ qayl;
                }
            }
            else if(index > qanakKes) //ete mer index@ mot e verjin
            {
                cout << "(verjic) ";
                temp = tail; //sksenq pochic
                
                qayl = listsQuantity; //sksenq verjic mincev index-erord@
                while(qayl != index)
                {
                    temp = temp -> prev;
                    -- qayl;
                }
            }
            return temp -> value;
        } //gtnelu funkciayi verj

        void find_value(int value) //arjeq@ gtnox funkcia
        {
            Node* tempFront = head;
            Node* tempBack = tail;
            for(int i = 1; i <= listsQuantity; ++i)
            {
                if(value == tempFront -> value || value == tempBack -> value)
                {
                    cout << endl << "The value " << value << " found in " << i << " steps" << endl;
                    return;
                }
              
                tempFront = tempFront -> next;
                tempBack = tempBack -> prev;
            }
            cout << endl << "The value " << value << " not found" << endl;
            return;
        } //arjeqov funkciai verj
        
};

int main()
{
    cout.setf(ios::boolalpha); //fstonovlivaet flag chtoby cout otobrojal true ili false vmesto 0 ili 1
    int choisIndex;
    LinkedLIst asd; //sarqenq asd anunov LinkedLIst
    cout << endl << "list is empty? " << asd.is_empty() << endl << endl;
    asd.push_back(30);
    asd.push_back(40);
    asd.push_front(20);
    asd.push_back(50);
    asd.push_back(60);
    asd.push_back(70);
    asd.push_front(10);
    asd.push_back(80);
    /*
    cout << "Chois the index ";
    cin >> choisIndex;
    cout << endl << "The value at index " << choisIndex << " equal to " << asd.get_index(choisIndex) << endl << endl;
    */
    asd.find_value(40);
    asd.print(1); //1->avers, 0->revers
    /*
    cout << endl << "pulled at back: " << asd.pop_back() << " value" << endl << endl;
    asd.print(1); //1->avers, 0->revers
    cout << endl << "pulled at front: " << asd.pop_front() << " value" << endl << endl;
    asd.print(0); //1->avers, 0->revers
    cout << endl << "list is empty? " << asd.is_empty() << endl << endl;
    */

    return 0;
}

