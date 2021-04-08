
//lista

//Pszeudo kód

//void* -> c# Object, Java Object, c++ template<class T>

struct Node {
    Node *next;
    void* data;
};

class List {
    Node head;

    void add(void* data, void* after) {
        Node *node = new Node();
        node->data = data;
        
        Node *end = &head;
        while (end->data != data && end->next != nullptr)
        {
            end = end->next;
        }

        Node *n = end->next;
        end->next = node;
        node->next = n;
    }

    void remove(void* data) {
        //elem megkeres, az a node kiszed
        //delete node
    }

};


