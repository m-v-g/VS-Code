//konstruktor kopirovaniya
//operator prisvoivoniya
//operator rovenstva


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
        Stack() //konstruktor po umolchaniyu
        {
            cout << "Vizvolsya konstruktor poumolchaniyu dlya obekta " << this << endl;
        }

        Stack(Stack& x) //konstruktor kopirovaniya
        {   //x-i mej pahvum e goyutyun unecox obyekti tvyalner@
            cout << "Vizvolsya konstruktor kopirovaniya dlya obekta " << this << endl;
            Node* temp = x.head;                      //stexcenq nor obekt iran veragrenq poxancvac obekti glux@
            for(int i = 0; i < x.listsQuantity; ++i)  //qayleri qanak@ = e x-i mej exac uzelneri qanakin
            {
                push(temp -> value);                  //ete kgrenq prost@ push inkati uninq mer @ntaciq sarqvox obektin
                temp = temp -> next;                  //me qaylm araj mer hin obekti mej
            }
        }

        ~ Stack() //destruktor
        {
            cout << "Vizvolsya destruktor dlya obekta " << this << endl;
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
                tail -> next = temp; //pochi next cuyc ta temp (araj NULL er chnayac hmi el e NULL)
                temp -> prev = tail; //tempi prev cuyc ta arajva pochin(araj NULL er bayc hmi uni hasce)
                tail = temp;         //temp@ darav mer taza poch@
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
                int tempValue = temp -> value; //te che valuen kkori
                delete temp;
                return tempValue; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
        } //demic jnjox funkciai verj

        Stack& operator= (const Stack& other) //operator prisvoivoniya
        {
            cout << "Vizvolsya operator prisvoivaniya" << endl;
            if(head != tail)
            {
                destroy();
                head = tail = nullptr;
            }
            Node* temp = other.head;                      //stexcenq nor obekt iran veragrenq poxancvac obekti glux@
            for(int i = 0; i < other.listsQuantity; ++i)  //qayleri qanak@ = e x-i mej exac uzelneri qanakin
            {
                push(temp -> value);                  //ete kgrenq prost@ push inkati uninq mer @ntaciq sarqvox obektin
                temp = temp -> next;                  //me qaylm araj mer hin obekti mej
            }
            return *this;
        }

        bool operator== (Stack& x) //hamematelu operator (arjeq@ kpoxancvi ssilkov)
        {
            if(listsQuantity != x.listsQuantity) //ete uzelneri qanak@ irar havasar che miangamic ksenq or iranq havasar chen
            {
                return false;
            }
            else //ete gone qanak@ havasar e hertov stugenq te iranc arjeqner@ havasar en te che
            {
                Node* temp1 = head;   //stex kpahvi LL1-i glxi hascen
                Node* temp2 = x.head; //stex el kpahvi funkciayin poxancvac LL2-i glxi hascen
                for(int i = 0; i < listsQuantity; ++i)
                {
                    if(temp1->value != temp2->value) //hertov kstugenq meji arjeqneri havasarutyan payman@
                    {
                        return false;
                    }
                }
            }
            return true; //ete mer sax paymanner@ minchev es bavararvel en uremn iranq havasar en
        }

        bool is_empty(void) //kstuge datark e te che
        {
            if(head == nullptr && tail == nullptr) //(head == 0 && tail == 0)-asxadav, (head == false && tail == false)-chasxadav, (listsQuantity == 0)
            {
                return true;
            }
            else return false;
        }// datarkutyan funkciai verj

        void destroy ()
        {
            cout << "Vizvolas funkciya unichtojeniya dly obekta " << this << endl;
            if(head != nullptr) //ete inq@ datark e hech ban chenenq 
            {
                while(is_empty())      //hertov ertanq araj minchev poch
                {
                    head = head -> next; //me qaylm araj ganq
                    delete head -> prev; //jnjenq ira naxordin
                }
                delete head;             //verjum mnac es me uzel@
            }
        }


};      


int main()
{
    Stack LL1;
    Stack LL2;

    LL1.push(10);
    LL1.push(20);
    LL1.push(30);

    LL2.push(10);
    LL2.push(20);
    LL2.push(30);

    if(LL1 == LL2) //stugenq havasar en te ch
    {
        cout << "list is equal" << endl;
    }
    else
    {
        cout << "list is not equal" << endl;
    }
    //cout << "lists is eqal " << LL1.is_equal(LL2);

    Stack LL3 = LL1; //stexcenq nor obekt LL3 vori parametrer@ havasar en LL1 -in
    //LL3.print();

    Stack LL4;
    
    LL4 = LL3;
    
    //LL4.print();
    LL1 = LL2;
    LL1.print();

    return 0;
}