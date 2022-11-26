//class Node
//class Binary Serch Tree
//add funkcia peregruzkov
//print funkcia peregruzkov
//destroy funkcia 
//destructor

//konstruktor kopirovaniya 152
//operator prisvoivoniya 199
//operator sravneniya 214
//rekursivnaya funkciya kopirovaniya 130
//rekursivnaya funkciya sravneniya 110

//rekursivnaya funkciya kopirovaniya
//operator ne ravenstva


#include <iostream>
using namespace std;

class Node
    {
        public:
            int value;
            Node* left;
            Node* right;
            Node* parent;
                
            Node(int x) //nor terev stexcelu konstruktor
            {
                value = x;
                left = nullptr;
                right = nullptr;
                parent =nullptr;
            }
    }; 

    class BST //binarnoe derevo poiska
    {
        private:
            Node* root = nullptr;
            int leavesAmount = 0;

            void print(Node* temp) //rekursivnaya funkciya pechati
            {
                if(!temp) //ete @ntaciki dzax koxm@ banm ka
                {
                    return;
                }
                print(temp->left);
                cout << temp->value << "\t";
                print(temp->right);
            }

            void destroy(Node* &temp) //rekursivnaya funkciya unichtojeniya
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

            bool add(int x, Node* &temp) //!peredayom ne ukazatel a ssilku na etot ukazatel
            {
                if(!temp) //!ete khandipenq zroyakan ukazatel
                {
                    ++ leavesAmount;
                    temp = new Node(x);
                    return true;
                }
                else if(x == temp->value)
                {
                    return false;
                }
                else if(x < temp->value) //ete x poqr e @ntaciqi valuic uremn kerdanq dzax
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

            Node* find(Node* temp, int copyX) //rekursivnaya funkciya poiska
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

            bool compare(Node* temp1, Node* temp2) //rekursivnaya funkciya sravneniya
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

             void copyRec(const Node* temp) //rekursivnaya funkciya kopirovaniya
            {
                if(temp)
                {
                    add(temp->value);
                    copyRec(temp->left);
                    copyRec(temp->right);
                }
            }

            bool delNodeParent(Node* temp, int val) //funkciya udaleniya
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
                    Node* minimal = temp->right; //erdanq aj gtnenq edtexac amena dzax@
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


        Node* delNode(Node* temp, int val) //TODO rekursivnaya funkciya udaleniya
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
                    Node* tmp; //stexcenq or krnananq erdanq araj
                    if(!temp->right) //ete chuni aj terev
                    {
                        cout << "obrivaem svyazi" << endl;
                        tmp = temp->left; //zaglushka
                    }
                    else //ete uni aj terev
                    {
                        Node* ptr = temp->right; //jamanakavor popoxaan sarqenq u ira mej pahenq aj terevin
                        if(!ptr->left) //ete ed aj@ dzax chuni
                        {
                            cout << "perekidivaem svyazi s leva" << endl;
                            ptr->left = temp->left; //or hankarc dzax chyux@ chkorcnenq
				            tmp = ptr;//zaglushka
                        }
                        else //ete vseotaki uni
                        {
                            
                            Node* minimal = ptr->left;
                            
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
            }

            BST(BST& other) //konstruktor kopirovaniya
            {
                cout << "Vizvolsya konstruktor kopirovaniya dlya obekta " << this << endl;
                Node* temp = other.root;
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

            bool add(int x) //publichnaya abeortka dlya funkcii dobavleniya
            {
                return add(x, root);
            }

            void print() //publichnaya abeortka dlya funkcii pechati
            {
                cout << "the trees Leaves Amount " << leavesAmount << endl;
                print(root); //stexic nor krnanq peregruzkov mer iskakan funkciain kanchenq
                cout << endl;
            }

            bool find(int temp) //publichnaya abeortka dlya funkcii poiska
            {
                return find(root, temp);
            }

            void delValue(int x)//publichnaya abeortka dlya funkcii udaleniya
            {
                //Node* temp = find(root, x);
                //delNode(temp, x);
                delNode(root, x);
            }

            bool operator== (BST& other) //operator sravneniya
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

            bool operator!= (BST& other) //operator sravneniya
            {      
                return !compare(root, other.root);
            }
            
            BST& operator= (const BST& other) //operator prisvoivoniya
            {
                //cout << "this root value: " << this->root->value << endl;
                if(root)
                {
                    destroy(root);
                }
                Node* temp = other.root;
                //cout << "other root value: " << temp->value << endl;
                copyRec(temp);
                return *this;   
            }
            
    
    };

    int main()
    {
        BST tree;
        int d;
        int array1[] = {70, 30, 20, 10, 90, 50, 40, 60, 80, 65};
        //new int array1[d];
        for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); ++i)
        {
            tree.add(array1[i]);
        }
        /*
        BST tsar;
        int array2[] = {70, 30, 20, 10, 90, 50, 40, 60, 80};
        for (int i = 0; i < sizeof(array2) / sizeof(array2[0]); ++i)
        {
            tsar.add(array2[i]);
        }
        */

        //tsar = tree;
        //cout << "TREE" << endl;
        //tree.print();
        
        //cout << "TSAR" << endl;
        //tsar.print();

        //BST derevo = tree;
        //derevo.print();
        //bool b = tree != tsar;
        //cout << endl << b ? "YES\n" : "NO\n"; //ternarny operator
        //cout << endl;
        tree.delValue(65);
        tree.print();
        //tree.find(9);
        
        //cout << "find " << tree.find(9) << endl;
/*
        string command;
        cout << "ENTER THE COMMAND\t";
        cin >> command;
        if(command == "search")
        {
            int kay;
            cout << "ENTER THE KAY\t";
            cin >>  kay;
            cout << endl << (tree.find(kay)) ? "YES\n" : "NO\n"; //ternarny operator
            cout << endl;
        }
        else if(command == "add")
        {
            int kay;
            cout << "ENTER THE KAY\t";
            cin >>  kay;
            cout << endl << (tree.add(kay)) ? "DONE\n" : "ALREDY\n"; //ternarny operator
            cout << endl;
        }
*/
        return 0;
    }