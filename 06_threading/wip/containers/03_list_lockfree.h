
//Pszeudo kód

//void* -> c# Object, Java Object, c++ template<class T>

struct Node {
    Atomic<Node> *next;
    void* data;
};

class List {
    Node head;

    void add(void* data, void* after) {
        Node *node = new Node();
        node->data = data;
        
        //megkeressük after alapján
        //node ba beállítjuk a next pointert
        //compare and swapoljuk az előtte álló elem next pointerét
        //std::atomic<T>::compare_exchange_weak, std::atomic<T>::compare_exchange_strong
    }

    void remove(void* data) {
        //elem megkeres
        //elem előtte levő elem pointere compareandswap a következő elemre
        //elem kitöröl
    }

};


