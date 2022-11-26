#include <iostream>
using namespace std;


template <class TypeC>
class Comparator
{
    public:
        virtual int hamematel(TypeC a, TypeC b) //or es hamematel@ chkanchvi
        {
            return 111;
        }
};

class Rectangle
{
    public:
        int a;
        int b;
        int area;
        int perimetr;

        Rectangle(){}

        Rectangle(int a, int b)
        {
            this->a = a;
            this->b = b;
            area = a * b;
            perimetr = 2 * a + 2 * b;
        }

        void print()
        {
            cout << "---------------" << endl;
            cout << a << endl;
            cout << b << endl;
            cout << area << endl;
            cout << perimetr << endl;
        }

        friend ostream& operator<<(ostream& tpel, const Rectangle rec)
        {
            cout << "==============" << endl;
            tpel << "Rect a:\t" << rec.a << endl;
            tpel << "Rect b:\t" << rec.b << endl;
            tpel << "Rect area:\t" << rec.area << endl;
            tpel << "Rect perimetr:\t" << rec.perimetr << endl;
            return tpel;
        }
};

class SortByA : public Comparator<Rectangle> //
{
    public:
        int hamematel(Rectangle patkerA, Rectangle patkerB)
        {
            if(patkerA.a > patkerB.a)
            {
                return 1;
            }
            else if(patkerA.a < patkerB.a)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
};

class SortByB : public Comparator<Rectangle> //
{
    public:
        int hamematel(Rectangle patkerA, Rectangle patkerB)
        {
            if(patkerA.b > patkerB.b)
            {
                return 1;
            }
            else if(patkerA.b < patkerB.b)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
};

class SortByArea : public Comparator<Rectangle> //
{
    public:
        int hamematel(Rectangle patkerA, Rectangle patkerB)
        {
            if(patkerA.area > patkerB.area)
            {
                return 1;
            }
            else if(patkerA.area < patkerB.area)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
};

class SortByPerimetr : public Comparator<Rectangle> //
{
    public:
        int hamematel(Rectangle patkerA, Rectangle patkerB)
        {
            if(patkerA.perimetr > patkerB.perimetr)
            {
                return 1;
            }
            else if(patkerA.perimetr < patkerB.perimetr)
            {
                return -1;
            }
            else
            {
                return 0;
            }
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




class SortByName : public Comparator<Specialist> //
{
    public:
        int hamematel(Specialist a, Specialist b)
        {
            if(a.name > b.name)
            {
                return 1;
            }
            else if(a.name < b.name)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

};

class SortBySurname : public Comparator<Specialist> //
{
    public:
        int hamematel(Specialist a, Specialist b)
        {
            if(a.surname > b.surname)
            {
                return 1;
            }
            else if(a.surname < b.surname)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

};

class SortByAge : public Comparator<Specialist> //
{
    public:
        int hamematel(Specialist a, Specialist b)
        {
            if(a.age > b.age)
            {
                return 1;
            }
            else if(a.age < b.age)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

};

class SortByIq : public Comparator<Specialist> //
{
    public:
        int hamematel(Specialist a, Specialist b)
        {
            if(a.iq > b.iq)
            {
                return 1;
            }
            else if(a.iq < b.iq)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

};

template <class TypeB>
class Node
    {
        public:
            TypeB value;
            Node<TypeB>* left;
            Node<TypeB>* right;
            Node<TypeB>* parent;
                
            Node(TypeB x) //nor terev stexcelu konstruktor
            {
                value = x;
                left = nullptr;
                right = nullptr;
                parent =nullptr;
            }
    }; 

    template <class TypeA>
    class BST //binarnoe derevo poiska
    {
        private:
            Comparator<TypeA>* comparator; //cmparator anunov member vor@ Cmparator -i ukazatel tesaki e
            Node<TypeA>* root = nullptr;
            int leavesAmount = 0;

            void print(Node<TypeA>* temp) //rekursivnaya funkciya pechati
            {
                if(!temp) //ete @ntaciki dzax koxm@ banm ka
                {
                    return;
                }
                print(temp->left);
                cout << temp->value;
                print(temp->right);
            }

            void destroy(Node<TypeA>* &temp) //rekursivnaya funkciya unichtojeniya
            {
                if(!temp)
                {
                    return;
                }
                destroy(temp->left);
                temp->left = nullptr;
                destroy(temp->right);
                temp->right = nullptr;
                -- leavesAmount;
                delete temp;
                temp = nullptr;
            }

            bool add(TypeA x, Node<TypeA>* &temp) //!peredayom ne ukazatel a ssilku na etot ukazatel
            {
                if(!temp) //!ete khandipenq zroyakan ukazatel
                {
                    ++ leavesAmount;
                    temp = new Node<TypeA>(x);
                    return true;
                }
                else if(comparator->hamematel(x, temp->value) == 0)
                //else if(x == temp->value)
                {
                    bool ret = add(x, temp->right); //rekursiv kanchenq es funkcian bayc arden @ntacikic aj
                    temp->right->parent = temp; //kanchic het galuc heto 
                    return false;
                }
                else if(comparator->hamematel(x, temp->value) == -1)
                //else if(x < temp->value) //ete x poqr e @ntaciqi valuic uremn kerdanq dzax
                {
                    bool ret = add(x, temp->left); //rekursiv kanchenq es funkcian bayc arden @ntacikic dzax
                    temp->left->parent = temp; //kanchic het galuc heto 
                    return ret;
                }
                else //ete x mec e @ntaciqi valuic uremn kerdanq aj
                {
                    bool ret = add(x, temp->right); //rekursiv kanchenq es funkcian bayc arden @ntacikic aj
                    temp->right->parent = temp; //kanchic het galuc heto 
                    return ret;
                }
            }

            Node<TypeA>* find(Node<TypeA>* temp, TypeA copyX) //rekursivnaya funkciya poiska
            {
                if(!temp)
                {
                    return nullptr;
                }
                if(temp->value == copyX)
                {
                    return temp;
                }
                
                if(copyX < temp->value)
                {
                    return find(temp->left, copyX);    //rekursiv erdanq dzax
                }
                if(copyX > temp->value)
                {
                    return find(temp->right, copyX);    //rekursiv erdanq aj
                }
                return nullptr;
            }

            bool compare(Node<TypeA>* temp1, Node<TypeA>* temp2) //rekursivnaya funkciya sravneniya
            {
                if((temp1 && !temp2) || (!temp1 && temp2))
                {
                    return false;
                }
                if(!temp1 && !temp2)
                {
                    return true;
                }
                if(temp1->value != temp2->value)
                {
                    return false;
                }
                //return  compare(temp1->left, temp2->left) && compare(temp1->right, temp2->right);
                bool l = compare(temp1->left, temp2->left);
                bool r = compare(temp1->right, temp2->right);
                return l && r;
            }

             void copyRec(const Node<TypeA>* temp) //rekursivnaya funkciya kopirovaniya
            {
                if(temp)
                {
                    add(temp->value);
                    copyRec(temp->left);
                    copyRec(temp->right);
                }
            }

            bool delNodeParent(Node<TypeA>* temp, TypeA val) //funkciya udaleniya
            //                      7
            //                     / \
            //                    3   9
            //                   / \  /
            //                  2   5 8
            //                 /   / \
            //                1   4   6
            //                         \
            //                          6.5
            {
                if(temp->left  == nullptr && temp->right == nullptr) //ete inq@ terev e
                { //stugenq te inq@ ira armati vor koxmn e
                    cout << "terev e " << endl;
                    if(temp->value < temp->parent->value) //uremn inq@ dzax terevn e
                    {
                        cout << "dzax terev e" << endl;
                        temp->parent->left = nullptr;
                        destroy(temp);
                        return true;
                    }
                    if(temp->value > temp->parent->value) //uremn inq@ aj terevn e
                    {
                        cout << "aj terev e" << endl;
                        temp->parent->right = nullptr;
                        destroy(temp);
                        return true;
                    }
                }
                else if(temp->left != nullptr && temp->right == nullptr) //ete uni menak dzax terev
                {
                    cout << "armat e dzax cyuxov" << endl;
                    temp->left->parent = temp->parent;
                    temp->parent->left = temp->left;
                    temp->left = temp ->right = nullptr; //sranov xzum enq tempi bolor kaper@
                    destroy(temp);
                    return true;
                }
                else if(temp->left == nullptr && temp->right != nullptr) //ete uni menak aj terev
                {
                    cout << "armat e aj cyuxov" << endl;
                    temp->right->parent = temp->parent;
                    temp->parent->right = temp->right;
                    temp->left = temp ->right = nullptr; //sranov xzum enq tempi bolor kaper@
                    destroy(temp);
                    return true;
                }
                else if(temp->left != nullptr && temp->right != nullptr) //ete uni ham aj ham dzax terevner
                { //uremn gtnenq @ntacikic meceric amenapoqr@
                    cout << "armat e 2 cyuxov" << endl;
                    Node<TypeA>* minimal = temp->right; //erdanq aj gtnenq edtexac amena dzax@
                    while(minimal->left) //dzax koxmov ijninq minchev verj
                    {
                        minimal = minimal->left;
                    }
                    temp->value = minimal->value; //gtac minimal arjeq@ grenq tempi mej
                    if(temp->right->left == nullptr && temp->right->right == nullptr) //ete temp aj@ terev e
                    {
                        minimal->parent->right = nullptr;
                    }
                    else if(temp->right->left == nullptr && temp->right->right != nullptr) //ete temp ej@ uni aj cyux
                    {
                        minimal->right->parent = minimal->parent;
                        minimal->parent->right = minimal->right;
                        minimal->left = minimal ->right = nullptr; //sranov xzum enq minimali bolor kaper@
                    }
                    else //ete temp->right left uni
                    {
                        minimal->parent->left = nullptr;
                    }
                    destroy(minimal);
                    return true;
                }
                return true;
            }        


        Node<TypeA>* delNode(Node<TypeA>* temp, TypeA val) //TODO rekursivnaya funkciya udaleniya
            //                      7
            //                     / \
            //                    3   9
            //                   / \  /
            //                  2   5 8
            //                 /   / \
            //                1   4   6
            //                         \
            //                          6.5
            {
                if(!temp) //ete datark e
                {
                    cout << "the tree is empty" << endl;
                    return temp; //zaglushka or hamarvi false
                }
                if(val == temp->value) //ete gtel enq
                {
                    Node<TypeA>* tmp; //stexcenq or krnananq erdanq araj
                    if(!temp->right) //ete chuni aj terev
                    {
                        cout << "obrivaem svyazi" << endl;
                        tmp = temp->left; //zaglushka
                    }
                    else //ete uni aj terev
                    {
                        Node<TypeA>* ptr = temp->right; //jamanakavor popoxaan sarqenq u ira mej pahenq aj terevin
                        if(!ptr->left) //ete ed aj@ dzax chuni
                        {
                            cout << "perekidivaem svyazi s leva" << endl;
                            ptr->left = temp->left; //or hankarc dzax chyux@ chkorcnenq
				            tmp = ptr;//zaglushka
                        }
                        else //ete vseotaki uni
                        {
                            
                            Node<TypeA>* minimal = ptr->left;
                            
                            while(minimal->left) //ijnenq dzaxov minchev verj
                            { //ptr misht me qaylm het kexni minimalic (parent)
                                cout << "444444444444444444" << endl;
                                ptr  = minimal;
                                minimal = minimal->left;
                            }
                            /*
                            ptr->left   = minimal->right;
                            minimal->left  = temp->left;
                            minimal->right = temp->right;
                            tmp = minimal;
                            return nullptr;
                            */
                            temp->value = minimal->value; //gtac minimal arjeq@ grenq tempi mej
                            if(temp->right->left == nullptr && temp->right->right == nullptr) //ete temp aj@ terev e
                            {
                                ptr->right = nullptr;
                            }
                            else //ete temp->right left uni
                            {
                                ptr->left = nullptr;
                            }
                            destroy(minimal);
                            return temp;
                        }
                    }
                    cout << "uje mojno udalit" << endl;
                    temp->left = temp ->right = nullptr; //sranov xzum enq tempi bolor kaper@
                    destroy(temp);
                    //delete temp;
                    //-- leavesAmount;
		            return tmp; //banm het veradardznenq or hamarvi true
                }
                
		        else if(val < temp->value) //ete poqr e
                {
                    cout << "rekursivny shag vlevo" << endl;
                    temp->left = delNode(temp->left, val); //erdanq dzax
                }

                else //ete mec e
                {
                    cout << "rekursivny shag vpravo" << endl;
                    temp->right = delNode(temp->right, val); //erdanq aj
                }

                return temp;
            }        

        public:

            BST() //konstruktor po umolchaniyu
            {
                cout << "Vizvolsya konstruktor dlya obekta " << this << endl;
                comparator = nullptr;
            }

            BST(Comparator<TypeA>* ptr)
            {
                this->comparator = ptr;
            }

            BST(BST<TypeA>& other) //konstruktor kopirovaniya
            {
                cout << "Vizvolsya konstruktor kopirovaniya dlya obekta " << this << endl;
                Node<TypeA>* temp = other.root;
                this->comparator = other.comparator; //! aranc sra chi ashxadi
                copyRec(temp);
            }

            ~BST() //destruktor
            {
                cout << "Vizvolsya destruktor dlya obekta " << this << endl;
                destroy(root);
                
            }

            bool is_empty(void) //publichnaya ne rekursivnaya funkciya pusto li
            {
                if(!root)
                {
                    return true;
                }
                else
                {
                    return false;
                } 
            }

            bool add(TypeA x) //publichnaya abeortka dlya funkcii dobavleniya
            {
                return add(x, root);
            }

            void print() //publichnaya abeortka dlya funkcii pechati
            {
                cout << "the trees Leaves Amount " << leavesAmount << endl;
                print(root); //stexic nor krnanq peregruzkov mer iskakan funkciain kanchenq
                cout << endl;
            }

            bool find(TypeA temp) //publichnaya abeortka dlya funkcii poiska
            {
                return find(root, temp);
            }

            void delValue(TypeA x)//publichnaya abeortka dlya funkcii udaleniya
            {
                //Node* temp = find(root, x);
                //delNode(temp, x);
                delNode(root, x);
            }

            bool operator== (BST<TypeA>& other) //operator sravneniya
            {      
                //cout << "Vizvolsya operator sravneniya dlya obekta " << this->root << endl;
                //cout << "Vizvolsya operator sravneniya dlya obekta " << other.root << endl;
                //if(this->root == other.root) //ete hamematum enq 2 nuyn obyektner@
                if(this == &other) //ete hamematum enq 2 nuyn obyektner@
                {
                    return true;
                }      
                if(leavesAmount != other.leavesAmount)
                {
                    return false;
                }
                return compare(root, other.root);
            }

            bool operator!= (BST<TypeA>& other) //operator sravneniya
            {      
                return !compare(root, other.root);
            }
            
            BST<TypeA>& operator= (const BST<TypeA>& other) //operator prisvoivoniya
            {
                //cout << "this root value: " << this->root->value << endl;
                if(root)
                {
                    destroy(root);
                }
                Node<TypeA>* temp = other.root;
                //cout << "other root value: " << temp->value << endl;
                this->comparator = other.comparator; //! aranc sra chi ashxadi
                copyRec(temp);
                return *this;   
            }
            
    
    };

    int main()
    {
        SortByName sbname;
        SortBySurname sbsurname;
        SortByAge sbage;
        SortByIq sbiq;

        BST<Specialist> tree(&sbage);

        string arrayN[] = {"G", "C", "B", "A", "I", "E", "D", "F", "H", "?"};
        char arrayS[] = {'g', 'c', 'b', 'a', 'i', 'e', 'd', 'f', 'h', '!'};
        int arrayA[] = {70, 30, 20, 10, 90, 50, 40, 60, 80, 65};
        float arrayI[] = {0.7, 0.3, 0.2, 0.1, 0.9, 0.5, 0.4, 0.6, 0.8, 0.65};
        
        for (int i = 0; i < sizeof(arrayA) / sizeof(arrayA[0]); ++i)
        {
            tree.add(Specialist(arrayN[i], arrayS[i], arrayA[i], arrayI[i]));
        }

        //tree.print();

        SortByA sba;
        SortByB sbb;
        SortByArea sbarea;
        SortByPerimetr sbperimetr;

        BST<Rectangle> derevo(&sbperimetr);

        int j = sizeof(arrayA) / sizeof(arrayA[0]) - 1;
        for (int i = 0; i < sizeof(arrayA) / sizeof(arrayA[0]); ++i)
        {
            derevo.add(Rectangle(arrayA[i], arrayA[j]));
            --j;
        }

        //derevo.print();

        //BST<Rectangle> tsar = derevo;
        BST<Rectangle> tsar;
        tsar = derevo;

        tsar.print();


        return 0;
    }