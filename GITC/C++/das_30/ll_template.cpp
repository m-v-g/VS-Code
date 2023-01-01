#include <iostream>
#include <ctime>

using namespace std;

class IndexOutOfBounds : public exception
{
    public:
        string prichina;
        string reshenie;
        int index;
        time_t kogda; //time_t tipi popoxakan vori mej kphenq 01.01.1970-ic mincev hmi varkyanneri qanak@

        IndexOutOfBounds(string prichina, string reshenie, int index, time_t kogda)
        {
            this->prichina = prichina; //"this->patchar" global membern e isk "patchar" stex stexcvac popoxakann e
            this->reshenie = reshenie; //knshanake es obekti member@ = es obektum stexcvac popoxakanin
            this->index = index;
            this->kogda = kogda;
        }

        void display()
        {
            cout << "-------------------------------------------" << endl;
            cout << "cause: " << prichina << endl;
            cout << "solution: " << reshenie << index << endl;
            cout << "when happened: " << ctime(&kogda) << endl;// ctime funkcia vor@ k@ndune erbi hascen u het
                                                               // kveradardzne normal formati berac amis amsativ@
            cout << "-------------------------------------------" << endl;
        } 

        const char* what() const throw()
        {
            return "List is empty";
        }
};


class Specialist
{
    public:
        string name;
        char surname;
        int age;
        float iq;

        Specialist(){} //konstruktor po umalchaniyu

        Specialist(string name, char surname, int age, float iq)
        {
            this->name = name;
            this->surname = surname;
            this->age = age;
            this->iq = iq;
        }

        void print()
        {
            cout << "---------------" << endl;
            cout << name << endl;
            cout << surname << endl;
            cout << age << endl;
            cout << iq << endl;
        }

        friend ostream& operator<<(ostream& tpel, const Specialist spec)
        {
            cout << "==============" << endl;
            tpel << "Spec name\t" << spec.name << endl;
            tpel << "Spec surname\t" << spec.surname << endl;
            tpel << "Spec age\t" << spec.age << endl;
            tpel << "Spec iq\t" << spec.iq << endl;
            return tpel;
        }
};


template <class TypeA>
class Node //class-i mej class sarqenq, LinkedLIst-i private sektorum mek e Node -in mainic chbdi sarkenq 
    {
        public: //Node -i memberner@ tox public exnin mek e mainic menq iranc chenq tesni
            TypeA value;  //arjeqi member
            Node<TypeA>* prev; //ukazatel tipa Node
            Node<TypeA>* next; //ukazatel tipa Node
                
            Node(TypeA x) //Node-i konstruktor arjeq@ menq kudalq prev u next inq@ kveragre NULL
            {
                value = x;      //lyuboy Node ira mej kpahe ira arjeq@ 
                prev = nullptr; //hajordi hascen defoltov NULL
                next = nullptr; //naxordi hascen defoltov NULL
            }
    }; 

template <class TypeB>
class Stack
{
    private:  
        Node<TypeB>* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
        Node<TypeB>* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
        int listsQuantity = 0; //lister qanak@ hasvelu hamar
        
    public:  
        ~ Stack()
        {
            if(head == nullptr)
            {
                delete head;
            }
            else
            {
                while(head)
                {
                    Node<TypeB>* temp = head;
                    head = head->next;
                    delete temp;
                    temp = head;
                }
                delete head;
            }
        }  
        void print() //tpelu funkcia
        { 
            Node<TypeB>* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
            while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
            {
                cout << temp -> value;
                temp = temp -> next;  //temp-in veragrenq hajord uzel@
            }
            cout << endl;
        } //tpelu funkciai verj

        void push (TypeB value) //demic grelu funkcia
        {
            Node<TypeB>* temp = new Node<TypeB>(value); //stexcenq nor temp anunov Node* tesaki uzel
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

        TypeB pop () //demic jnjox funkcia
        {
            if(head == nullptr)
            {
                //IndexOutOfBounds ex("List is empty", "List is empty", listsQuantity, time(0));
                //throw exception();
                throw "List is empty";
            }
            else
            {
                Node<TypeB>* temp = head; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
                head = head -> next;  //glxi mej@ pahenq ira arajva nexti hascen
                head -> prev = nullptr; //hmigva glxi prev = NULL
                -- listsQuantity;
                return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
        } //demic jnjox funkciai verj
};      
template <class TypeB>
class Queue
{
    private:
        Node<TypeB>* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
        Node<TypeB>* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
        int listsQuantity = 0; //lister qanak@ hasvelu hamar
        
    public: 
        ~ Queue()
        {
            if(head == nullptr)
            {
                delete head;
            }
            else
            {
                while(head)
                {
                    Node<TypeB>* temp = head;
                    head = head->next;
                    delete temp;
                    temp = head;
                }
                delete head;
            }
        }  

        void print() //tpelu funkcia
        { 
            Node<TypeB>* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
            while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
            {
                cout << temp -> value;
                temp = temp -> next;  //temp-in veragrenq hajord uzel@
            }
        } //tpelu funkciai verj

        void push (TypeB value) //demic grelu funkcia
        {
            Node<TypeB>* temp = new Node<TypeB>(value); //stexcenq nor temp anunov Node* tesaki uzel
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

        TypeB pop (void) //hetevic jnjox funkcia
        {
            if(head == nullptr)
            {
                throw "List is empty";
            }
            else
            {
                Node<TypeB>* temp = tail; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
                tail = tail -> prev; //pochi mej@ pahenq ira arajva previ hascen
                tail -> next = nullptr; //hmigva pochi next = NULL
                -- listsQuantity;
                return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
            
        } //hetevic jnjox funkciai verj
};
template <class TypeB>
class Deque
{
    private:   
        Node<TypeB>* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
        Node<TypeB>* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
        int listsQuantity = 0; //lister qanak@ hasvelu hamar
        
    public:   
        ~ Deque()
        {
            if(head == nullptr)
            {
                delete head;
            }
            else
            {
                while(head)
                {
                    Node<TypeB>* temp = head;
                    head = head->next;
                    delete temp;
                    temp = head;
                }
                delete head;
            }
        }  


        void print() //tpelu funkcia
        { 
            Node<TypeB>* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
            while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
            {
                cout << "VALUE:\t" << temp -> value << endl;
                temp = temp -> next;  //temp-in veragrenq hajord uzel@

            }  
        } //tpelu funkciai verj

        void push_back(TypeB value) //hetevic grelu funkcia
        {
            Node<TypeB>* temp = new Node<TypeB>(value); //stexcenq nor temp anunov Node* tesaki uzel
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
        
        void push_front(TypeB value) //demic grelu funkcia
        {
            Node<TypeB>* temp = new Node<TypeB>(value); //stexcenq nor temp anunov Node* tesaki uzel
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

        TypeB pop_back(void) //hetevic jnjox funkcia
        {
            if(head == nullptr)
            {
                throw "List is empty";
            }
            else
            {
                Node<TypeB>* temp = tail; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
                tail = tail -> prev; //pochi mej@ pahenq ira arajva previ hascen
                tail -> next = nullptr; //hmigva pochi next = NULL
                -- listsQuantity;
                return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
            
        } //hetevic jnjox funkciai verj
        
        TypeB pop_front(void) //demic jnjox funkcia
        {
            if(head == nullptr)
            {
                throw "List is empty";
            }
            else
            {
                Node<TypeB>* temp = head; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
                head = head -> next;  //glxi mej@ pahenq ira arajva nexti hascen
                head -> prev = nullptr; //hmigva glxi prev = NULL
                -- listsQuantity;
                return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
        } //demic jnjox funkciai verj
};


int main()
{
    string arrayN[] = {"G", "C", "B", "A", "I", "E", "D", "F", "H", "?"};
    char arrayS[] = {'g', 'c', 'b', 'a', 'i', 'e', 'd', 'f', 'h', '!'};
    int arrayA[] = {70, 30, 20, 10, 90, 50, 40, 60, 80, 65};
    float arrayI[] = {0.7, 0.3, 0.2, 0.1, 0.9, 0.5, 0.4, 0.6, 0.8, 0.65};
        
    

    Stack<Specialist> daran;
    Queue<Specialist> hert;
    Deque<Specialist> dubHert;

    try
    {
        daran.pop();
        for (int i = 0; i < sizeof(arrayA) / sizeof(arrayA[0]); ++i)
        {
            daran.push(Specialist(arrayN[i], arrayS[i], arrayA[i], arrayI[i]));
            hert.push(Specialist(arrayN[i], arrayS[i], arrayA[i], arrayI[i]));
            dubHert.push_front(Specialist(arrayN[i], arrayS[i], arrayA[i], arrayI[i]));
        }
        daran.print();
        hert.print();

        dubHert.push_back(Specialist("I", 'i', 5, 0.5));

        cout << endl << "~~~STACK STACANQ ~~~" << endl << daran.pop() << endl;
        cout << endl << "~~~QUEUE STACANQ ~~~" << endl << hert.pop() << endl;

        dubHert.print();

        cout << endl << "~~~DEQUE FRONT STACANQ ~~~" << endl << dubHert.pop_front() << endl;
        cout << endl << "~~~DEQUE BACK STACANQ ~~~" << endl << dubHert.pop_back() << endl;
    }
    catch(IndexOutOfBounds exp)
    {
        exp.display();
    }
    catch(exception& exp)
    {
        cout << "Menq brnecinq: " << exp.what() << endl;
    }
    catch(const char *exp)
    {
        cout << "We catch: " << exp << endl;
    }

    return 0;
}
