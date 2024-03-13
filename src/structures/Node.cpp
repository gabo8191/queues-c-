template <typename E>
class Node
{
private:
    E data;
    Node<E> *next;

public:
    Node(E data): data(data) {};
    
    E getData()
    {
        return data;
    }
    
    Node<E> *getNext()
    {
        return next;
    }
    void setNext(Node<E> *next)
    {
        this->next = next;
    }
};