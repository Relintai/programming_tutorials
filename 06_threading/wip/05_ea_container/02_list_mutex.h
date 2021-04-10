

#include <mutex>

using namespace std;

struct Node {
    Node *next;
    void* data;
};

class List {
    Node head;
    mutex m;

    void add(void* data) {
        //mutex lezár

        Node *node = new Node();
        node->data = data;
        
        Node *end = &head;
        while (end->next != nullptr)
        {
            end = end->next;
        }

        end->next = node;

        //mutex felold
    }

    void remove(void* data) {
        //mutex lezár

        //elem megkeres, az a node kiszed
        //delete node

        //mutex felold
    }

};
