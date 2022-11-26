#include <iostream>
#include <ctime>

using namespace std;

class IndexOutOfBounds
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
};

class WrongValue
{
    public:
        string prichina;
        string reshenie;
        int value;
        time_t kogda; //time_t tipi popoxakan vori mej kphenq 01.01.1970-ic mincev hmi varkyanneri qanak@

        WrongValue(string prichina, string reshenie, int index, time_t kogda)
        {
            this->prichina = prichina; //"this->patchar" global membern e isk "patchar" stex stexcvac popoxakann e
            this->reshenie = reshenie; //knshanake es obekti member@ = es obektum stexcvac popoxakanin
            this->value = value;
            this->kogda = kogda;
        }

        void display()
        {
            cout << "-------------------------------------------" << endl;
            cout << "cause: " << prichina << " " << value << endl;
            cout << "solution: " << reshenie << endl;
            cout << "when happened: " << ctime(&kogda) << endl;// ctime funkcia vor@ k@ndune erbi hascen u het
                                                               // kveradardzne normal formati berac amis amsativ@
            cout << "-------------------------------------------" << endl;
        } 
};

class ListIsEmpty
{
    public:
        string prichina;
        string reshenie;
        int quantity;
        time_t kogda; //time_t tipi popoxakan vori mej kphenq 01.01.1970-ic mincev hmi varkyanneri qanak@

        ListIsEmpty(string prichina, string reshenie, int index, time_t kogda)
        {
            this->prichina = prichina; //"this->patchar" global membern e isk "patchar" stex stexcvac popoxakann e
            this->reshenie = reshenie; //knshanake es obekti member@ = es obektum stexcvac popoxakanin
            this->quantity = quantity;
            this->kogda = kogda;
        }

        void display()
        {
            cout << "-------------------------------------------" << endl;
            cout << "cause: " << prichina << endl;
            cout << "solution: " << reshenie << quantity << endl;
            cout << "when happened: " << ctime(&kogda) << endl;// ctime funkcia vor@ k@ndune erbi hascen u het
                                                               // kveradardzne normal formati berac amis amsativ@
            cout << "-------------------------------------------" << endl;
        } 
};


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
        void print() //tpelu funkcia
        { 
            Node* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
            while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
            {
                cout << "VALUE:\t" << temp -> value << endl;
                temp = temp -> next;  //temp-in veragrenq hajord uzel@
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
            if(!listsQuantity) //stugenq ete datark e
            {
                IndexOutOfBounds ex("list is empty", "lists quantity is: ", listsQuantity, time(0));
                throw ex;
            }
            Node* temp = tail; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
            if(head != tail) //stugenq ete verjinn e
            {
                tail = tail -> prev; //pochi mej@ pahenq ira arajva previ hascen
                tail -> next = nullptr; //hmigva pochi next = NULL   
            }
            -- listsQuantity;
            return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
        } //hetevic jnjox funkciai verj
        
        int pop_front(void) //demic jnjox funkcia
        {
            if(!listsQuantity) //stugenq ete datark e
            {
                IndexOutOfBounds ex("list is empty", "lists quantity is: ", listsQuantity, time(0));
                throw ex;
            }
            Node* temp = head; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
            if(head != tail) //stugenq ete verjinn e
            {
                head = head -> next;  //glxi mej@ pahenq ira arajva nexti hascen
                head -> prev = nullptr; //hmigva glxi prev = NULL
            }
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
                //cout << "Index not found ";
                //return 0;
                IndexOutOfBounds ex("inserted wrong index", "insert the index between 1 - ", listsQuantity, time(0));
                throw ex;
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
            //cout << endl << "The value " << value << " not found" << endl;
            //return;
            WrongValue ex("The value not found", "insert the another value", value, time(0));
            throw ex;
        } //arjeqov funkciai verj
        
};



int main()
{
    try
    {

        LinkedLIst asd; //sarqenq asd anunov LinkedLIst
        asd.push_back(30);
        asd.push_back(40);
        cout << asd.pop_front() << endl;
        cout << asd.pop_front() << endl;
        cout << asd.pop_front() << endl;
        asd.push_front(20);
        asd.push_back(50);
        asd.push_back(60);
        asd.push_back(70);
        asd.push_front(10);
        asd.push_back(80);
        

        //cout << asd.get_index(0) << endl;
        //asd.find_value(90);
    }
        
    catch(IndexOutOfBounds k)
    {
           k.display(); 
    }
    catch(WrongValue k)
    {
           k.display(); 
    }
    catch(ListIsEmpty k)
    {
           k.display(); 
    }
    
    return 0;
}