
//Pszeudo kód

//void* -> c# Object, Java Object, c++ template<class T>

#include <mutex>
#include <atomic>

using namespace std;

struct Node {
    Node *next;
    void* data;
};

class Stack {
    Node head;
    mutex m;

    void push(void* data) {
        //mutex lezár

        Node *node = new Node();
        node->data = data;

        node->next = head.next;
        head.next = node;

        //mutex felold
    }

    void *pop() {
        //mutex lezár

        Node *node = head.next;

        if (node == nullptr)
            return nullptr;

        void *data = node->data;

        head.next = node->next;

        delete node;

        //mutex felold

        return data;
    }

};


