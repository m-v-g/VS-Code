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