template <typename T>
class MyQueue {
    private:
        Node<T> *head;
        Node<T> *tail;

public:
    MyQueue(): {
        this->head = nullptr;
        this->tail = head;
    }

    void push(T data) {
        Node<T>* node = new Node<T>(data);
        if (isEmpty()) {
            head = node;
        } else {
            tail->setNext(node);
            tail = node;
        }
    }

   
    T poll() {
        T data = head->getValue();
        head = head->getNext();  
        return data;
    }

    T peek() {
        return (isEmpty()) ? T() :head->getValue();
    }

    bool isEmpty() {
        return head == nullptr;
    }
};