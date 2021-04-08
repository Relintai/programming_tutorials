
//Pszeudo kód

//void* -> c# Object, Java Object, c++ template<class T>

struct Node {
    Node *next;
    void* data;
};

class Queue {
    Node head;

    void enqueue(void* data) {
        Node *node = new Node();
        node->data = data;
        
        Node *end = &head;
        while (end->next != nullptr)
        {
            end = end->next;
        }

        end->next = node;
    }

    void *dequeue() {
        Node *node = head.next;

        if (node == nullptr)
            return nullptr;

        void* data = node->data;

        head.next = node->next;

        delete node;

        return data;
    }

};


