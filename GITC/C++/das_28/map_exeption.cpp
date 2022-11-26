#include <iostream>
#include <ctime>
using namespace std;

template<class Type1, class Type2>
class Node
{
    public:
        Type1 kay;
        Type2 val;
        int index = 0;
        Node<Type1, Type2>* prev;
        Node<Type1, Type2>* next;

        Node(Type1 k, Type2 v)
        {
            kay = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
};

template<class TypeA, class TypeB>
class Stack
{
    private:
        Node<TypeA, TypeB>* head = nullptr;
        Node<TypeA, TypeB>* tail = nullptr;
        int userQuantity = 0;

    public:
        ~ Stack()
        {
            if(head != nullptr)
            {
                while(head != tail)
                {
                    head = head -> next;
                    delete head -> prev;
                }
                delete head;
            }
        } 

        void print(void)
        { 
            //Node<type1, type2>* temp = head;
            auto temp = head;
            while(temp != nullptr)
            {
                cout << "User Index\t" << temp->index << endl;
                cout << "User Name\t" << temp->kay << endl;
                cout << "User Password\t" << temp->val << endl;
                temp = temp -> next;
                cout << endl;
            }
                cout << endl << endl;
        }

        void push (TypeA kay, TypeB val)
        {
            //Node<type1, type2>* temp = new Node<type1, type2>(kay, val);
            auto temp = new Node<TypeA, TypeB>(kay, val);

            if(head == nullptr)
            {
                head = temp;
                tail = temp;
            }

            else if(find(kay))
            {
                cout << "-----User is exist-----" << endl;
                delete temp;
                return;
            }

            else
            {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }

            ++ userQuantity;
            temp->index = userQuantity;
            return;
        }

        Node<TypeA, TypeB> pop()
        {
            if(head == nullptr)
            {
                cout << "List is empty ";
                throw 404;
            }
            else
            {
                auto temp = *head;
                head = head->next;
                head->prev = nullptr;
                -- userQuantity;
                return temp;
            }
        }

        bool find (TypeA kayCopy)
        {
            //Node<type1, type2>* temp = head;
            auto temp = head;
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

        bool is_empty(void)
        {
            if(head == nullptr && tail == nullptr)
            {
                return true;
            }
            else return false;
        }


        void destroy ()
        {
            if(head != nullptr) 
            {
                while(is_empty())
                {
                    head = head -> next;
                    delete head -> prev;
                }
                delete head;
            }
        }
};

int main()
{
    //try{
        Stack<int, int> vk;
        vk.push(55, 5);
        vk.push(66, 6);
        vk.push(77, 7);
        vk.push(77, 8);
        vk.print();
        Stack<string, string> ok;
        ok.push("asd", "123");
        ok.print();

        auto t = vk.pop();
        //cout << t->kay << endl;
        //cout << t->val << endl;
    //}
    //catch{

    //}

    return 0;
}