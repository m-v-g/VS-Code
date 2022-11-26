//class Node
//class Binary Serch Tree
//add funkcia peregruzkov
//print funkcia peregruzkov
//destroy funkcia 
//destructor




#include <iostream>
using namespace std;

class Node
    {
        public:
            int value;
            Node* left;
            Node* right;
                
            Node(int x) //nor terev stexcelu konstruktor
            {
                value = x;
                left = nullptr;
                right = nullptr;
            }
    }; 

    class BST
    {
        private:
            Node* root = nullptr;
            int leavesAmount = 0;

            void add(int x, Node* temp)
            {
                if(root == nullptr)
                {
                    cout << "the value " << x << " inserted in the root" << endl;
                    ++ leavesAmount;
                    root = new Node(x); //stexcenq nor element iran poxancenq mer valun u qani vor inq@ arajinne inq@ bdi exni mer armat@
                }
                else if(x < temp->value) //ete x poqr e @ntaciqi valuic uremn kerdanq dzax
                {
                    if(temp->left == nullptr) //gnacel enq dzax bayc ete ed chyux@ datark e
                    {
                        cout << "the value " << x << " inserted at left" << endl;
                        ++ leavesAmount;
                        temp->left = new Node(x); //stexcenq nor element u @ntaciki left@ iran cuyc ta
                    }
                    else //isk ete chyux@ datark ch
                    {
                        cout << "RECURSIVE CALL TO LEFT" << endl;
                        add(x, temp->left); //rekursiv kanchenq es funkcian bayc arden @ntacikic dzax
                    }
                }
                else if(x > temp->value) //ete x mec e @ntaciqi valuic uremn kerdanq aj
                {
                    if(temp->right == nullptr) //gnacel enq aj bayc ete ed chyux@ datark e
                    {
                        cout << "the value " << x << " inserted at right" << endl;
                        ++ leavesAmount;
                        temp->right = new Node(x); //stexcenq nor element u @ntaciki right@ iran cuyc ta
                    }
                    else //isk ete chyux@ datark ch
                    {
                        cout << "RECURSIVE CALL TO RIGHT" << endl;
                        add(x, temp->right); //rekursiv kanchenq es funkcian bayc arden @ntacikic aj
                    }
                }
                else
                {
                    cout << "Node is exist" << endl;
                }
            }

            void print(Node* temp) //tpelu funkcia
            {
                if(temp->left != nullptr) //ete @ntaciki dzax koxm@ banm ka
                {
                    print(temp->left);    //rekursiv erdanq dzax
                }
                cout << "VALUE\t" << temp->value << endl;
                if(temp->right != nullptr) //ete @ntaciki aj koxm@ banm ka
                {
                    print(temp->right);    //rekursiv erdanq aj
                }
            }

            void destroy(Node* temp) //
            {
                if(temp == nullptr)
                {
                    cout << "the tree is empty" << endl;
                    return;
                }
                if(temp->left != nullptr) //ete @ntaciki dzax koxm@ banm ka
                {
                    destroy(temp->left);    //rekursiv erdanq dzax
                    //temp->left = nullptr;
                }
                if(temp->right != nullptr) //ete @ntaciki aj koxm@ banm ka
                {
                    destroy(temp->right);    //rekursiv erdanq aj
                    //temp->right = nullptr;
                }
                -- leavesAmount;
                delete temp;
                
            }

            Node* find(Node* temp, int copyX)
            {
                if(temp->value == copyX)
                {
                    return temp;
                }
                if(copyX < temp->value)
                {
                    if(temp->left != nullptr) //ete @ntaciki dzax koxm@ banm ka
                    {
                        return find(temp->left, copyX);    //rekursiv erdanq dzax
                    }
                }
                if(copyX > temp->value)
                {
                    if(temp->right != nullptr) //ete @ntaciki aj koxm@ banm ka
                    {
                        return find(temp->right, copyX);    //rekursiv erdanq aj
                    }
                }
                
                return nullptr;
            }

        public:

            BST()
            {
                cout << "Vizvolsya konstruktor dlya obekta " << this << endl;
            }

            ~BST()
            {
                cout << "Vizvolsya destruktor dlya obekta " << this << endl;
                destroy(root);
            }

            bool is_empty(void)
            {
                if(root == nullptr)
                {
                    return true;
                }
                else return false;
            }

            void add(int x)
            {
                add(x, root);
            }

            void print() //es funkcian bdi grvi or karoxananq myus@ rekursiv kanchenq
            {
                if(is_empty()) //dzerac het me stugumm el enenq
                {
                    cout << "the tree is empty" << endl;
                }
                else
                {
                    cout << "the trees Leaves Amount " << leavesAmount << endl;
                    print(root); //stexic nor krnanq peregruzkov mer iskakan funkciain kanchenq
                }
            }

            bool find(int x)
            {
                if(root == nullptr)
                {
                    return false;
                }
                else
                {
                    return find(root, x);
                }
            }

            void del(void)
            {
                destroy(root);
                root = nullptr;
            }
    };

    int main()
    {
        BST tree;
        tree.print();
        tree.del();
        tree.print();
        int array[] = {7, 3, 2, 1, 9, 5, 4, 6, 8};
        for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
        {
            tree.add(array[i]);
        }
        tree.del();
        //tree.print();
        //cout << "find " << tree.find(1) << endl;

        return 0;
    }