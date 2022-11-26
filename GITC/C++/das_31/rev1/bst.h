#include "other_class.h"
#include "node.h"
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
                std::cout << temp->value;
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
                    if(temp->value < temp->parent->value) //uremn inq@ dzax terevn e
                    {
                        temp->parent->left = nullptr;
                        destroy(temp);
                        return true;
                    }
                    if(temp->value > temp->parent->value) //uremn inq@ aj terevn e
                    {
                        temp->parent->right = nullptr;
                        destroy(temp);
                        return true;
                    }
                }
                else if(temp->left != nullptr && temp->right == nullptr) //ete uni menak dzax terev
                {
                    temp->left->parent = temp->parent;
                    temp->parent->left = temp->left;
                    temp->left = temp ->right = nullptr; //sranov xzum enq tempi bolor kaper@
                    destroy(temp);
                    return true;
                }
                else if(temp->left == nullptr && temp->right != nullptr) //ete uni menak aj terev
                {
                    temp->right->parent = temp->parent;
                    temp->parent->right = temp->right;
                    temp->left = temp ->right = nullptr; //sranov xzum enq tempi bolor kaper@
                    destroy(temp);
                    return true;
                }
                else if(temp->left != nullptr && temp->right != nullptr) //ete uni ham aj ham dzax terevner
                { //uremn gtnenq @ntacikic meceric amenapoqr@
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
                    //cout << "the tree is empty" << endl;
                    return temp; //zaglushka or hamarvi false
                }
                if(val == temp->value) //ete gtel enq
                {
                    Node<TypeA>* tmp; //stexcenq or krnananq erdanq araj
                    if(!temp->right) //ete chuni aj terev
                    {
                        //cout << "obrivaem svyazi" << endl;
                        tmp = temp->left; //zaglushka
                    }
                    else //ete uni aj terev
                    {
                        Node<TypeA>* ptr = temp->right; //jamanakavor popoxaan sarqenq u ira mej pahenq aj terevin
                        if(!ptr->left) //ete ed aj@ dzax chuni
                        {
                            //cout << "perekidivaem svyazi s leva" << endl;
                            ptr->left = temp->left; //or hankarc dzax chyux@ chkorcnenq
				            tmp = ptr;//zaglushka
                        }
                        else //ete vseotaki uni
                        {
                            
                            Node<TypeA>* minimal = ptr->left;
                            
                            while(minimal->left) //ijnenq dzaxov minchev verj
                            { //ptr misht me qaylm het kexni minimalic (parent)
                                //cout << "444444444444444444" << endl;
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
                    //cout << "uje mojno udalit" << endl;
                    temp->left = temp ->right = nullptr; //sranov xzum enq tempi bolor kaper@
                    destroy(temp);
                    //delete temp;
                    //-- leavesAmount;
		            return tmp; //banm het veradardznenq or hamarvi true
                }
                
		        else if(val < temp->value) //ete poqr e
                {
                    //cout << "rekursivny shag vlevo" << endl;
                    temp->left = delNode(temp->left, val); //erdanq dzax
                }

                else //ete mec e
                {
                    //cout << "rekursivny shag vpravo" << endl;
                    temp->right = delNode(temp->right, val); //erdanq aj
                }

                return temp;
            }        

        public:

            BST() //konstruktor po umolchaniyu
            {
                comparator = nullptr;
            }

            BST(Comparator<TypeA>* ptr)
            {
                this->comparator = ptr;
            }

            BST(BST<TypeA>& other) //konstruktor kopirovaniya
            {
                Node<TypeA>* temp = other.root;
                this->comparator = other.comparator; //! aranc sra chi ashxadi
                copyRec(temp);
            }

            ~BST() //destruktor
            {
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
                std::cout << "the trees Leaves Amount " << leavesAmount << std::endl;
                print(root); //stexic nor krnanq peregruzkov mer iskakan funkciain kanchenq
                std::cout << std::endl;
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