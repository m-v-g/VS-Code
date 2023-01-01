//check user name
//creat password
//export to file


#include <iostream>
#include <string>   //dlya roboti s klasom string
#include <fstream>  //dlya failovogo vvoda-vivoda
using namespace std;

class Node //class-i mej class sarqenq, LinkedLIst-i private sektorum mek e Node -in mainic chbdi sarkenq 
{
    public: //Node -i memberner@ tox public exnin mek e mainic menq iranc chenq tesni
        string login;  //logini member
        string passwd;  //passwd member
        int index = 0;
        Node* prev; //ukazatel tipa Node
        Node* next; //ukazatel tipa Node

        Node(string k) //Node-i konstruktor arjeq@ menq kudalq prev u next inq@ kveragre NULL
        {
            login = k;
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
                    cout << "User Name\t" << temp->login << endl;
                    cout << "Password\t" << temp->passwd << endl;
                    temp = temp -> next;  //temp-in veragrenq hajord uzel@
                    cout << endl;
                }
                    cout << endl << endl;
            } //tpelu funkciai verj

            void printFile(void)
            {
                ofstream fout; //sozdanie obekta dlya vivoda
                fout.open("user_info.txt"); //asocaciya obekta outFile s failom
                fout << "--- ЧИСЛО ПОЛЗОВАТЕЛЬЕЙ\t" << userQuantity << "\t---" << endl << endl;
                Node* temp = head; 
                while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
                {
                    fout << "Номер ползователья:\t" << temp->index << endl;
                    fout << "Имя ползователья:\t" << temp->login << endl;
                    fout << "Пароль:\t" << temp->passwd << endl;
                    temp = temp -> next;  //temp-in veragrenq hajord uzel@
                    cout << endl << " " << endl;
                }
                fout.close(); //zavershit robotu s failom
            }

            void push (string userName) //find-i u pushi gibrid funkcia
            {
                Node* temp = new Node(userName); //stexcenq nor temp anunov Node* tesaki uzel
                string passTemp;

                if(head == nullptr) //ete cucak@ datark e
                {
                    head = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
                    tail = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
                }

                else if(find(userName)) //ete login@ arden goyutyun uni
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
                //cin >> passTemp;
                getline(cin, passTemp); //cin-@ kpoxancenq getline funkciain vorpes argument
                temp->passwd = passTemp;
                ++ userQuantity;
                temp->index = userQuantity;
                return;
            }

            bool find (string kayCopy)
            {
                Node* temp = head;
                    for(int i = 1; i <= userQuantity; ++ i)
                    {
                        if(temp->login == kayCopy) //sravnenie strok v stile C++
                        {
                            return 1;
                        }
                        temp = temp->next;         //hajord user@ stugenq
                    }
                    return 0;
            }
    };


    int main()
    {
        Stack vkontakte;
        string userTemp;
        for(int i = 1; i <=  5; ++i) //sarqenq 5 hat user
        {
            cout << "Enter the user name ";
            getline(cin, userTemp); //cin-@ kpoxancenq getline funkciain vorpes argument
            vkontakte.push(userTemp);
        }
        vkontakte.print();
        vkontakte.printFile();
        return 0;
    }