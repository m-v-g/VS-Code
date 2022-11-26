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
                left = right = parent = nullptr;
            }
    };

class Heap
{
private:
    Node* root = nullptr;
    int leavesAmount = 0;

    bool push(int x, Node* &temp)
    {
        if(!temp) //ete araji elementn e
        {
            ++ leavesAmount;
            temp = new Node(x);
            return true;
        }
        else if(x == temp->value) //ete arden ka
        {
            return false;
        }
        else if(!temp->left) //ete voch dzax uni voch el aj
        {
            temp->left = new Node(x);
            temp->left->parent = temp;
            return true;
        }
        else if(temp->left && !temp->right) //ete dzax uni bayc aj chuni
        {
            temp->right = new Node(x);
            temp->left->parent = temp;
            return true;
        }
        bool ret = push(x, temp->left);
        return ret;
    }

    void pop(void)
    {

    }

public:
    bool push(int x) //publichnaya abeortka dlya funkcii dobavleniya
    {
        return push(x, root);
    }
};

int main()
{
    Heap trash;
        int array[] = {70, 30, 20, 10, 90, 50, 40, 60, 80, 65};
        for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
        {
            trash.push(array[i]);
        }

    return 0;
}