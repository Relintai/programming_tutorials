
//Pszeudo kód

//void* -> c# Object, Java Object, c++ template<class T>

struct Node {
    Node *next;
    Node *prev;
    void* data;
};

class DoubleLinkedList {
    Node head;

    void add(void* data, void*after) {
        Node *node = new Node();
        node->data = data;
        
        //elem megkeres

        //pointerek beállít
    }

    void remove(void* data) {
        //elem megkeres, az a node kiszed
        //delete node
    }

};


