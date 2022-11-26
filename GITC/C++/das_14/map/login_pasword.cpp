//login password intaiger


#include <iostream>
using namespace std;

class Node //class-i mej class sarqenq, LinkedLIst-i private sektorum mek e Node -in mainic chbdi sarkenq 
{
    public: //Node -i memberner@ tox public exnin mek e mainic menq iranc chenq tesni
        int kay;  //logini member
        int val;  //passwd member
        int index = 0;
        Node* prev; //ukazatel tipa Node
        Node* next; //ukazatel tipa Node

        Node(int k) //Node-i konstruktor arjeq@ menq kudalq prev u next inq@ kveragre NULL
        {
            kay = k;
            prev = nullptr; //hajordi hascen defoltov NULL
            next = nullptr; //naxordi hascen defoltov NULL
        }
    };

    class Stack
    {
        private:  
            Node* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
            Node* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
            int userQuantity = 0; //lister qanak@ hasvelu hamar

        public:
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
                    cout << "User Index\t" << temp->index << endl;
                    cout << "User Name\t" << temp->kay << endl;
                    cout << "Password\t" << temp->val << endl;
                    temp = temp -> next;  //temp-in veragrenq hajord uzel@
                    cout << endl;
                }
                    cout << endl << endl;
            } //tpelu funkciai verj

            void push (int kay) //find-i u pushi gibrid funkcia
            {
                Node* temp = new Node(kay); //stexcenq nor temp anunov Node* tesaki uzel
                int passTemp;

                if(head == nullptr) //ete cucak@ datark e
                {
                    head = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
                    tail = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
                }

                else if(find(kay)) //ete login@ arden goyutyun uni
                {
                    cout << "User is exist" << endl;
                    delete temp; //metodom tika
                    return;
                }

                else //ete sax normal e grenq pochic
                {
                    tail->next = temp; //pochi next cuyc ta temp (araj NULL er chnayac hmi el e NULL)
                    temp->prev = tail; //tempi prev cuyc ta arajva pochin(araj NULL er bayc hmi uni hasce)
                    tail = temp;         //temp@ darav mer taza poch@
                }
                cout << "Enter the password ";
                cin >> passTemp;
                temp->val = passTemp;
                ++ userQuantity;
                temp->index = userQuantity;
                return;
            }

            bool find (int kayCopy)
            {
                Node* temp = head;
                    for(int i = 1; i <= userQuantity; ++ i)
                    {
                        if(temp->kay == kayCopy)
                        {
                            return 1;
                        }
                        temp = temp->next;
                    }
                    return 0;
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
        Stack vkontakte;
        vkontakte.push(55);
        vkontakte.push(66);
        vkontakte.push(77);
        vkontakte.push(77);
        vkontakte.print();
        return 0;
    }